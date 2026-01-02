#ifndef _MINWINDEF_
#define _MINWINDEF_

#if defined(_WIN32)
  #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
  #endif
  #include <windows.h>
  #include <objbase.h>
#else
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
#define VOID void

typedef unsigned long long SIZE_T; // Assuming 64-bit build
typedef char *LPSTR;
typedef const char *LPCSTR;
typedef wchar_t *LPWSTR;
typedef const wchar_t *LPCWSTR;
typedef unsigned int *PUINT;
typedef long HRESULT;
typedef struct _GUID {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;
typedef GUID IID;
typedef const IID *REFIID;
typedef void IUnknown; // Minimal stub
typedef IUnknown *LPUNKNOWN;
#endif



#endif
