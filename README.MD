## Darkmode Libary for Notepad++ Plugins

A common, shareable DLL for enabling the Darkmode feature across multiple Notepad++ plugins.

This common library was initially developed for use with the [FWDataViz](https://github.com/shriprem/FWDataViz) and [GotoLineCol](https://github.com/shriprem/Goto-Line-Col-NPP-Plugin) plugins.

The documentation here is primarily meant for Notepad++ plugins written in C++. Adaptations for other programming languages are welcome.

A significant portion of the code in this repo has been either imported _as is_ or adapted from files in the [Notepad++ repository](https://github.com/notepad-plus-plus/notepad-plus-plus). For more information, see: [Attributions](#attributions).


#### Files to include with your plugin:
1. **NPP_Plugin_Darkmode.h**
   * Needed at _compile time_
   * Include in the _Source_ path
   * [_Common_](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/NPP_Plugin_Darkmode/NPP_Plugin_Darkmode.h) version for x86 / x64 / arm64

2. **NPP_Plugin_Darkmode.lib**
   * Needed at _link time_
   * Include in the _Library_ path
   * Needs _matching_ version for [x86](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/Release/Win32/NPP_Plugin_Darkmode.lib) / [x64](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/Release/x64/NPP_Plugin_Darkmode.lib) / [arm64](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/Release/ARM64/NPP_Plugin_Darkmode.lib)

3. **NPP_Plugin_Darkmode.dll**
   * Needed at _run time_
   * Include either in `<NPP_folder>` or `<NPP_Plugins_folder>` or `<NPP_Plugins_folder>/Plugin_subfolder`.
   * Needs _matching_ version for [x86](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/Release/Win32/NPP_Plugin_Darkmode.dll) / [x64](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/Release/x64/NPP_Plugin_Darkmode.dll) / [arm64](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/Release/ARM64/NPP_Plugin_Darkmode.dll)



#### Functions exported by the DLL:
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

#### Usage Notes:
1. [Documentation](https://github.com/shriprem/NPP_Plugin_Darkmode/c_plus_plus.md) for plugins written in C++.

#### Source Code Attribution:

##### Unchanged [Notepad++](https://github.com/notepad-plus-plus/notepad-plus-plus)  Source Files

1. DarkMode.h
2. DarkMode.cpp
3. IatHook.h
4. Notepad_plus_msgs.h


##### Adapted [Notepad++](https://github.com/notepad-plus-plus/notepad-plus-plus) Source Files
1. NppParameters.h
2. NppParameters.cpp
3. NppDarkMode.h
4. NppDarkMode.cpp


##### [TinyXML-2](https://github.com/leethomason/tinyxml2) Source Files
1. tinyxml2.h
2. tinyxml2.cpp
