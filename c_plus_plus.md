### Usage Notes for Notepad++ Plugins written in C++

#### Usage Summary
1. [Initializing the DLL](#initializing-the-dll)
2. [Setting the Dark Title Bar in StaticDialog.cpp](#setting-dark-title-bar-in-staticdialog)
3. [Initializing Darkmode in individual dialogs](#individual-dialogs)
   * [Handling Darkmode for SysLink controls](#handling-darkmode-for-syslink-controls)

---

#### Initializing the DLL
The `NPP_Plugin_Darkmode.dll` will need to be initialized once with the handle to the Notepad++ instance. The ideal place for this initialization is during the `DLL_PROCESS_ATTACH` call for your plugin.
```C++
BOOL APIENTRY DllMain(HANDLE hModule, DWORD  reasonForCall, LPVOID /*lpReserved*/) {
    switch (reasonForCall) {
      case DLL_PROCESS_ATTACH:
        pluginInit(hModule);
        NPPDM_InitDarkMode(nppData._nppHandle);
        break;
```
For specific usage examples, see: [VisualizerMain.cpp](https://github.com/shriprem/FWDataViz/blob/master/src/VisualizerMain.cpp) and [GotoLineColMain.cpp](https://github.com/shriprem/Goto-Line-Col-NPP-Plugin/blob/master/src/GotoLineColMain.cpp).

---
#### Setting Dark Title Bar in StaticDialog
In the `StaticDialog` parent class, the `NPPDM_SetDarkTitleBar(_hSelf)` call is needed twice.

1. Once in the `StaticDialog::create` function:
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


2. And, once in the `StaticDialog::dlgProc` function:
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
For specific usage examples, see: [FWDataViz/StaticDialog.cpp](https://github.com/shriprem/FWDataViz/blob/master/src/NPP/StaticDialog.cpp) and [Goto-Line-Col-NPP-Plugin/StaticDialog.cpp](https://github.com/shriprem/Goto-Line-Col-NPP-Plugin/blob/master/src/NPP/StaticDialog.cpp).


---


#### Individual Dialogs
Within the `run_dlgProc` functions of each of the dialogs in your plugin, code _similar_ to the template below is needed.


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

* The `NPPDM_AutoSubclassAndThemeChildControls` function call under `WM_INITDIALOG` is a standard requirement for all dialogs.

* The `NPPDM_...` function call under `WM_CTLCOLORDLG` is also a standard requirement for all dialogs.

* The `NPPDM_...` function call under `WM_CTLCOLORLISTBOX` is required when a dialog has one or more list box controls.

* The `NPPDM_...` function call under `WM_CTLCOLORSTATIC` is required when a dialog has one or more static text controls.

* The `NPPDM_...` function call under `WM_CTLCOLOREDIT` is required when a dialog has one or more edit controls.

* The code under `WM_PRINTCLIENT` is required when a dialog has one or more button controls. The `return TRUE` will suppress white edges around button controls in darkmode in Windows 7 clients.

For specific usage examples, see:
1. [FWDataViz/AboutDialog.cpp](https://github.com/shriprem/Goto-Line-Col-NPP-Plugin/blob/master/src/Dialogs/AboutDialog.cpp)
2. [FWDataViz/PreferencesDialog.cpp](https://github.com/shriprem/FWDataViz/blob/master/src/Dialogs/PreferencesDialog.cpp)
3. [FWDataViz/DataExtractDialog.cpp](https://github.com/shriprem/FWDataViz/blob/master/src/Dialogs/DataExtractDialog.cpp)

##### Handling Darkmode for SysLink controls
In dialogs with SysLink controls, like [FWDataViz/AboutDialog.cpp](https://github.com/shriprem/Goto-Line-Col-NPP-Plugin/blob/master/src/Dialogs/AboutDialog.cpp) for example, additional code will be needed.

The SysLink controls should be first enabled for custom text colors. This can be done with `LIS_DEFAULTCOLORS` in a `LM_SETITEM` message during `WM_INITDIALOG`.
```C+++
INT_PTR CALLBACK AboutDialog::run_dlgProc(UINT message, WPARAM wParam, LPARAM lParam) {
   switch (message) {
   case WM_INITDIALOG:
      if (NPPDM_IsEnabled()) {
         LITEM item = { 0 };
         item.iLink = 0;
         item.mask = LIF_ITEMINDEX | LIF_STATE;
         item.state = LIS_DEFAULTCOLORS;
         item.stateMask = LIS_DEFAULTCOLORS;
         SendMessage(GetDlgItem(_hSelf, IDC_ABOUT_PROD_URL), LM_SETITEM, 0, (LPARAM)&item);
...
...
...
```

Then, `NPPDM_OnCtlColorSysLink` should be returned from within `WM_CTLCOLORSTATIC` when event control ID matches that of a SysLink control.

```C+++
...
...
...
   case WM_CTLCOLORSTATIC:
      if (GetDlgCtrlID((HWND)lParam) == IDC_ABOUT_PROD_URL) {
         if (NPPDM_IsEnabled()) {
            return NPPDM_OnCtlColorSysLink(reinterpret_cast<HDC>(wParam));
         }
      }

      if (NPPDM_IsEnabled()) {
         return NPPDM_OnCtlColorDarker((HDC)wParam);
      }
      break;```
...
...
...


