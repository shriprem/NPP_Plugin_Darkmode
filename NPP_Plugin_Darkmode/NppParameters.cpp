// This file was developed for the FWDataViz and GotoLineCol plugins,
// culled from the Notepad++'s Darkmode implementation in Parameters.cpp.
// Copyright (C) 2022 Shridhar Kumar <shriprem@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "NppParameters.h"

#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "Shlwapi.lib")

void NppParameters::init() {
   TCHAR sPath[MAX_PATH]{};
   Utils::nppMessage(NPPM_GETNPPDIRECTORY, MAX_PATH, (LPARAM)sPath);
   _nppPath = wstring{ sPath };

   _isLocal = isLocal();
   _darkmode._customColors = NppDarkMode::getDarkModeDefaultColors();
   loadConfigSettings();
}

DarkModeConf NppParameters::getDarkModeConf() {
   return _darkmode;
}

toolBarStatusType NppParameters::gettoolBarStatusType() {
   return _tbType;
}

COLORREF NppParameters::nppBackgroundRGB() {
   return Utils::intToRGB(Utils::nppMessage(NPPM_GETEDITORDEFAULTBACKGROUNDCOLOR, NULL, NULL));
}

bool NppParameters::isLocal() {
   TCHAR sLocalConfPath[MAX_PATH]{};
   PathCombine(sLocalConfPath, _nppPath.c_str(), L"doLocalConf.xml");

   bool bLocal(PathFileExists(sLocalConfPath));

   if (bLocal) {
      if (Utils::checkBaseOS(WV_VISTA)) {
         bLocal = (_nppPath != Utils::getKnownFolderPath(FOLDERID_ProgramFiles));
      }
   }

   return bLocal;
}

wstring NppParameters::getSettingsFolder() {
   if (_isLocal) return _nppPath;

   wstring sAppData = Utils::getKnownFolderPath(FOLDERID_RoamingAppData);
   if (sAppData == L"") return _nppPath;

   TCHAR nppAppData[MAX_PATH]{};
   PathCombine(nppAppData, sAppData.c_str(), L"Notepad++");

   return ((PathFileExists(nppAppData)) ? wstring{ nppAppData } : _nppPath);
}

bool NppParameters::loadConfigSettings() {
   char configPath[MAX_PATH]{};
   PathCombineA(configPath, Utils::WideToNarrow(getSettingsFolder()).c_str(), "config.xml");

   TXMLDocument confXML;
   TXMLError loadStatus = confXML.LoadFile(configPath);
   if (loadStatus != tinyxml2::XML_SUCCESS) return FALSE;

   TXMLElement* guiConfig =
      confXML.FirstChildElement("NotepadPlus")->
      FirstChildElement("GUIConfigs")->
      FirstChildElement("GUIConfig");

   while (guiConfig != nullptr) {
      if (guiConfig->Attribute("name", "ToolBar")) {
         string sTBType{ guiConfig->GetText() };

         if (sTBType == "small")
            _tbType = NppDarkMode::TB_SMALL;
         else if (sTBType == "large")
            _tbType = NppDarkMode::TB_LARGE;
         else if (sTBType == "small2")
            _tbType = NppDarkMode::TB_SMALL2;
         else if (sTBType == "large2")
            _tbType = NppDarkMode::TB_LARGE2;
         else
            _tbType = NppDarkMode::TB_STANDARD;
      }

      if (guiConfig->Attribute("name", "DarkMode")) {
         _darkmode._isEnabled = (string{ guiConfig->Attribute("enable") } == "yes");
         _darkmode._colorTone = static_cast<NppDarkMode::ColorTone>(guiConfig->IntAttribute("colorTone"));
         _darkmode._customColors.pureBackground = guiConfig->IntAttribute("customColorTop");
         _darkmode._customColors.hotBackground = guiConfig->IntAttribute("customColorMenuHotTrack");
         _darkmode._customColors.softerBackground = guiConfig->IntAttribute("customColorActive");
         _darkmode._customColors.background = guiConfig->IntAttribute("customColorMain");
         _darkmode._customColors.errorBackground = guiConfig->IntAttribute("customColorError");
         _darkmode._customColors.text = guiConfig->IntAttribute("customColorText");
         _darkmode._customColors.darkerText = guiConfig->IntAttribute("customColorDarkText");
         _darkmode._customColors.disabledText = guiConfig->IntAttribute("customColorDisabledText");
         _darkmode._customColors.edge = guiConfig->IntAttribute("customColorEdge");
         _darkmode._customColors.linkText = guiConfig->IntAttribute("customColorLinkText");
      }

      guiConfig = guiConfig->NextSiblingElement("GUIConfig");
   }

   return TRUE;
}
