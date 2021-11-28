## Darkmode Libary for Notepad++ Plugins

Base code to enable darkmode feature for Notepad++ plugins

##### Files to include with your plugin:
1. **NPP_Plugin_Darkmode.h**
2. **NPP_Plugin_Darkmode.lib** [matching: x86 / x64 / arm64]
3. **NPP_Plugin_Darkmode.dll** [matching: x86 / x64 / arm64]
---

##### Functions exported by the DLL:
```c++
void NPPDM_InitDarkMode(const HWND _nppHandle);
bool NPPDM_IsEnabled();
bool NPPDM_IsToolBarFilled();
void NPPDM_AutoSubclassAndThemeChildControls(HWND hwndParent, bool subclass = true, bool theme = true);
void NPPDM_SetDarkTitleBar(HWND hwnd);
LRESULT NPPDM_OnCtlColor(HDC hdc);
LRESULT NPPDM_OnCtlColorSofter(HDC hdc);
LRESULT NPPDM_OnCtlColorDarker(HDC hdc);
LRESULT NPPDM_OnCtlColorError(HDC hdc);
LRESULT NPPDM_OnCtlColorSysLink(HDC hdc);
```
---

##### Sample Usage Pattern:
```C++
INT_PTR CALLBACK ConfigureDialog::run_dlgProc(UINT message, WPARAM wParam, LPARAM) {
   switch (message) {
...
...
...
   case WM_INITDIALOG:
      if (NppDarkMode::isEnabled()) {
         NppDarkMode::autoSubclassAndThemeChildControls(_hSelf);
      }
      break;

   case WM_CTLCOLORDLG:
   case WM_CTLCOLORLISTBOX:
   case WM_CTLCOLORSTATIC:
      if (NppDarkMode::isEnabled()) {
         return NppDarkMode::onCtlColorDarker(reinterpret_cast<HDC>(wParam));
      }
      break;

   case WM_CTLCOLOREDIT:
      if (NppDarkMode::isEnabled()) {
         return NppDarkMode::onCtlColorSofter(reinterpret_cast<HDC>(wParam));
      }
      break;

   case WM_PRINTCLIENT:
      if (NppDarkMode::isEnabled()) {
         return TRUE;
      }
      break;
   }
...
...
...
   return FALSE;
}
```