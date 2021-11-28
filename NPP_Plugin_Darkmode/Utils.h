#pragma once

#include "Notepad_plus_msgs.h"

#include <string>
#include <Windows.h>
#include <CommCtrl.h>
#include <Shlwapi.h>
#include <shellapi.h>
#include <codecvt>
#include <ShlObj_core.h>

using std::string;
using std::wstring;

namespace Utils {
   int nppMessage(UINT messageID, WPARAM wparam, LPARAM lparam);

   string WideToNarrow(const wstring& wStr);

   COLORREF intToRGB(int color);
   int scaleDPIX(int x);
   int scaleDPIY(int y);
   wstring getKnownFolderPath(REFKNOWNFOLDERID folderID);

   bool checkBaseOS(winVer os);
}
