#include "Utils.h"

extern HWND nppHandle;

int Utils::nppMessage(UINT messageID, WPARAM wparam, LPARAM lparam) {
   return static_cast<int>(SendMessage(nppHandle, messageID, wparam, lparam));
}

string Utils::WideToNarrow(const wstring& wStr) {
   return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wStr);
}

COLORREF Utils::intToRGB(int color) {
   return RGB(GetRValue(color), GetGValue(color), GetBValue(color));
}

int Utils::scaleDPIX(int x) {
   HDC hdc = GetDC(NULL);
   if (!hdc) return 0;

   int scaleX{ MulDiv(x, GetDeviceCaps(hdc, LOGPIXELSX), 96) };
   ReleaseDC(NULL, hdc);
   return scaleX;
}

int Utils::scaleDPIY(int y) {
   HDC hdc = GetDC(NULL);
   if (!hdc) return 0;

   int scaleY{ MulDiv(y, GetDeviceCaps(hdc, LOGPIXELSY), 96) };
   ReleaseDC(NULL, hdc);
   return scaleY;
}

wstring Utils::getKnownFolderPath(REFKNOWNFOLDERID folderID) {
   PWSTR path;

   const HRESULT ret = SHGetKnownFolderPath(folderID, KF_FLAG_DEFAULT, NULL, &path);
   if (ret != S_OK) return L"";

   wstring sFolderPath{ path };
   CoTaskMemFree(path);
   return sFolderPath;
}

bool Utils::checkBaseOS(winVer os) {
   return (nppMessage(NPPM_GETWINDOWSVERSION, NULL, NULL) >= os);
}

float Utils::getNPPVersion() {
   long versionNum{ static_cast<long>(nppMessage(NPPM_GETNPPVERSION, 0, 0)) };

   return std::stof(std::to_wstring(HIWORD(versionNum)) + L"." + std::to_wstring(LOWORD(versionNum)));
}

