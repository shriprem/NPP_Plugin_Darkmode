## Darkmode Libary for Notepad++ Plugins

![GitHub](https://img.shields.io/github/license/shriprem/NPP_Plugin_Darkmode) ![GitHub release (latest by date)](https://img.shields.io/github/v/release/shriprem/NPP_Plugin_Darkmode) ![GitHub all releases](https://img.shields.io/github/downloads/shriprem/NPP_Plugin_Darkmode/total)

A common, shareable DLL for enabling the Darkmode feature across multiple Notepad++ plugins.

This common library was initially developed for use with the [FWDataViz](https://github.com/shriprem/FWDataViz) and [GotoLineCol](https://github.com/shriprem/Goto-Line-Col-NPP-Plugin) plugins.

The documentation here is primarily meant for Notepad++ plugins written in C++. Adaptations for other programming languages are welcome.

A significant portion of the code in this repo has been either imported _as is_ or adapted from files in the [Notepad++ repository](https://github.com/notepad-plus-plus/notepad-plus-plus). For more information, see: [Source Code Attributions](#source-code-attributions).


#### _This release is compatible with Notepad++ 8.4.1 or later versions_


### Files to include with your plugin:
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
   * Include either in `<NPP_folder>` or `<NPP_Plugins_folder>/Plugin_subfolder`.
   * Needs _matching_ version for [x86](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/Release/Win32/NPP_Plugin_Darkmode.dll) / [x64](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/Release/x64/NPP_Plugin_Darkmode.dll) / [arm64](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/Release/ARM64/NPP_Plugin_Darkmode.dll)



### Functions exported by the DLL:
```c++
void NPPDM_InitDarkMode(const HWND _nppHandle);
void NPPDM_QueryNPPDarkmode();
bool NPPDM_IsEnabled();
void NPPDM_AutoSubclassAndThemeChildControls(HWND hwndParent, bool subclass = true, bool theme = true);
void NPPDM_SetDarkTitleBar(HWND hwnd);
void NPPDM_InitSysLink(HWND hCtl);
LRESULT NPPDM_OnCtlColor(HDC hdc);
LRESULT NPPDM_OnCtlColorSofter(HDC hdc);
LRESULT NPPDM_OnCtlColorDarker(HDC hdc);
LRESULT NPPDM_OnCtlColorError(HDC hdc);
LRESULT NPPDM_OnCtlColorSysLink(HDC hdc);
LRESULT NPPDM_OnCtlColorIfEnabled(HDC hdc, bool isEnabled);
LRESULT NPPDM_OnCtlHiliteIfEnabled(HDC hdc, bool isEnabled);
INT_PTR NPPDM_OnCtlColorListbox(WPARAM wParam, LPARAM lParam);
```

### Usage Notes:
1. [Documentation](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/c_plus_plus.md) for plugins written in C++.

### Source Code Attributions:

#### Unchanged [Notepad++](https://github.com/notepad-plus-plus/notepad-plus-plus)  Source Files

1. DarkMode.h
2. DarkMode.cpp
3. IatHook.h
4. Notepad_plus_msgs.h


#### Adapted [Notepad++](https://github.com/notepad-plus-plus/notepad-plus-plus) Source Files
1. NppDarkMode.h
2. NppDarkMode.cpp
