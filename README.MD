## Darkmode Libary for Notepad++ Plugins

![GitHub](https://img.shields.io/github/license/shriprem/NPP_Plugin_Darkmode) ![GitHub release (latest by date)](https://img.shields.io/github/v/release/shriprem/NPP_Plugin_Darkmode) ![GitHub all releases](https://img.shields.io/github/downloads/shriprem/NPP_Plugin_Darkmode/total)

API Library for enabling the Darkmode feature in any Notepad++ plugin written in C++.

This API library was initially developed for use with the [FWDataViz](https://github.com/shriprem/FWDataViz) and [GotoLineCol](https://github.com/shriprem/Goto-Line-Col-NPP-Plugin) plugins.

The documentation here is primarily meant for Notepad++ plugins written in C++.

A significant portion of the code in this repo has been either imported _as is_ or adapted from files in the [Notepad++ repository](https://github.com/notepad-plus-plus/notepad-plus-plus). For more information, see: [Source Code Attributions](#source-code-attributions).


#### `NOTE:` _This release is compatible with Notepad++ 8.4.1 or later versions_

### Source File Usage:
This API Library can be utilized by importing all the 8 files found in the folder path `NPP_Plugin_Darkmode/Darkmode/` of this repo into your plugin solution, and then adding `#include "<relative_Darkmode_folder_path>/NPP_Plugin_Darkmode.h"` in all your _DialogXYZ.cpp_ files.


### API Functions:
```c++
void NPPDM_InitDarkMode(const HWND _nppHandle);
void NPPDM_QueryNPPDarkmode();
bool NPPDM_IsEnabled();
void NPPDM_AutoSubclassAndThemeChildControls(HWND hwndParent);
void NPPDM_AutoThemeChildControls(HWND hwndParent);
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

### API Usage Notes:
1. [Documentation](https://github.com/shriprem/NPP_Plugin_Darkmode/blob/master/c_plus_plus.md) for plugins written in C++. (_This document will be updated shortly for the NPP_Plugin_Darkmode 2.0 version changes._)

### Source Code Attributions:

#### Unchanged [Notepad++](https://github.com/notepad-plus-plus/notepad-plus-plus)  Source Files

1. DarkMode.h
2. DarkMode.cpp
3. IatHook.h
4. Notepad_plus_msgs.h


#### Adapted [Notepad++](https://github.com/notepad-plus-plus/notepad-plus-plus) Source Files
1. NppDarkMode.h
2. NppDarkMode.cpp
