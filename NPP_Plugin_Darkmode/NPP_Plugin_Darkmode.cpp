#include "NPP_Plugin_Darkmode.h"

HWND nppHandle;

void NPPDM_InitDarkMode(const HWND _nppHandle) {
   nppHandle = _nppHandle;
   return NppDarkMode::initDarkMode();
}

bool NPPDM_IsEnabled() {
   return NppDarkMode::isEnabled();
}

bool NPPDM_IsToolBarFilled() {
   return NppDarkMode::isToolBarFilled();
}

void NPPDM_AutoSubclassAndThemeChildControls(HWND hwndParent, bool subclass, bool theme) {
   return NppDarkMode::autoSubclassAndThemeChildControls(hwndParent, subclass, theme);
}

void NPPDM_SetDarkTitleBar(HWND hwnd) {
   return NppDarkMode::setDarkTitleBar(hwnd);
}

LRESULT NPPDM_OnCtlColor(HDC hdc) {
   return NppDarkMode::onCtlColor(hdc);
}

LRESULT NPPDM_OnCtlColorSofter(HDC hdc) {
   return NppDarkMode::onCtlColorSofter(hdc);
}

LRESULT NPPDM_OnCtlColorDarker(HDC hdc) {
   return NppDarkMode::onCtlColorDarker(hdc);
}

LRESULT NPPDM_OnCtlColorError(HDC hdc) {
   return NppDarkMode::onCtlColorError(hdc);
}

LRESULT NPPDM_OnCtlColorSysLink(HDC hdc) {
   return NppDarkMode::onCtlColorSysLink(hdc);
}
