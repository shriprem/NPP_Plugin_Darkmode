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

##### Usage Pattern:
```C++
BOOL APIENTRY DllMain(HANDLE hModule, DWORD  reasonForCall, LPVOID /*lpReserved*/) {
    switch (reasonForCall) {
      case DLL_PROCESS_ATTACH:
        pluginInit(hModule);
        NPPDM_InitDarkMode(nppData._nppHandle);
        break;
```

```C++
void StaticDialog::create(int dialogID, bool isRTL, bool msgDestParent)
{
...
...
...
   NPPDM_SetDarkTitleBar(_hSelf);
...
...
...
}
```

```C++
INT_PTR CALLBACK StaticDialog::dlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   switch (message)
   {
      case WM_INITDIALOG:
      {
         NPPDM_SetDarkTitleBar(hwnd);
...
...
...
}
```

```C++
INT_PTR CALLBACK ConfigureDialog::run_dlgProc(UINT message, WPARAM wParam, LPARAM) {
   switch (message) {
...
...
...
   case WM_INITDIALOG:
      if (NPPDM_IsEnabled()) {
         NPPDM_AutoSubclassAndThemeChildControls(_hSelf);
      }
      break;

   case WM_CTLCOLORDLG:
   case WM_CTLCOLORLISTBOX:
   case WM_CTLCOLORSTATIC:
      if (NPPDM_IsEnabled()) {
         return NPPDM_OnCtlColorDarker(reinterpret_cast<HDC>(wParam));
      }
      break;

   case WM_CTLCOLOREDIT:
      if (NPPDM_IsEnabled()) {
         return NPPDM_OnCtlColorSofter(reinterpret_cast<HDC>(wParam));
      }
      break;

   case WM_PRINTCLIENT:
      if (NPPDM_IsEnabled()) {
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