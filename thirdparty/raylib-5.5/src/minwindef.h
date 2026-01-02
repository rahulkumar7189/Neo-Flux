#ifndef _MINWINDEF_
#define _MINWINDEF_

typedef unsigned long DWORD;
typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef float FLOAT;
typedef int INT;
typedef unsigned int UINT;
typedef long LONG;

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

typedef void *LPVOID;
typedef void *HANDLE;
typedef HANDLE HWND;
typedef HANDLE HINSTANCE;
typedef HANDLE HGLOBAL;
typedef HANDLE HDC;

#define WINAPI __stdcall
#define CALLBACK __stdcall
#define DECLSPEC_IMPORT __declspec(dllimport)

// Structs needed by win32_clipboard.h if not defined
// Actually, win32_clipboard.h defines BITMAPINFOHEADER etc itself if _WINGDI_ is not defined.
// So we just need basics.

#endif
