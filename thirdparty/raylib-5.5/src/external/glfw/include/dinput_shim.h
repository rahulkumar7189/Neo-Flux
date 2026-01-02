#ifndef _DINPUT_SHIM_H_
#define _DINPUT_SHIM_H_


#include "minwindef.h"

#define DIRECTINPUT_VERSION 0x0800

// Handles


// Basic Types
typedef struct {
    DWORD dwSize;
    DWORD dwHeaderSize;
    DWORD dwHow;
    DWORD dwObj;
    DWORD dwMip; // Optional
} DIPROPHEADER, *LPDIPROPHEADER;

typedef struct {
    DIPROPHEADER diph;
    DWORD        dwData;
} DIPROPDWORD, *LPDIPROPDWORD;

typedef struct {
    DIPROPHEADER diph;
    LONG         lMin;
    LONG         lMax;
} DIPROPRANGE, *LPDIPROPRANGE;

typedef struct {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwDevType;
    DWORD dwAxes;
    DWORD dwButtons;
    DWORD dwPOVs;
    DWORD dwFFSamplePeriod;
    DWORD dwFFMinTimeResolution;
    DWORD dwFirmwareRevision;
    DWORD dwHardwareRevision;
    DWORD dwFFDriverVersion;
} DIDEVCAPS, *LPDIDEVCAPS;

typedef struct {
    DWORD dwSize;
    GUID  guidType;
    DWORD dwOfs;
    DWORD dwType;
    DWORD dwFlags;
    CHAR  tszName[MAX_PATH];
    DWORD dwFFMaxForce;
    DWORD dwFFForceResolution;
    WORD  wCollectionNumber;
    WORD  wDesignatorIndex;
    WORD  wUsagePage;
    WORD  wUsage;
    DWORD dwDimension;
    WORD  wExponent;
    WORD  wReportId;
} DIDEVICEOBJECTINSTANCEA, *LPDIDEVICEOBJECTINSTANCEA;
typedef struct {
    DWORD dwSize;
    GUID  guidType;
    DWORD dwOfs;
    DWORD dwType;
    DWORD dwFlags;
    WCHAR tszName[MAX_PATH];
    DWORD dwFFMaxForce;
    DWORD dwFFForceResolution;
    WORD  wCollectionNumber;
    WORD  wDesignatorIndex;
    WORD  wUsagePage;
    WORD  wUsage;
    DWORD dwDimension;
    WORD  wExponent;
    WORD  wReportId;
} DIDEVICEOBJECTINSTANCEW, *LPDIDEVICEOBJECTINSTANCEW;
#ifdef UNICODE
typedef DIDEVICEOBJECTINSTANCEW DIDEVICEOBJECTINSTANCE;
typedef LPDIDEVICEOBJECTINSTANCEW LPDIDEVICEOBJECTINSTANCE;
#else
typedef DIDEVICEOBJECTINSTANCEA DIDEVICEOBJECTINSTANCE;
typedef LPDIDEVICEOBJECTINSTANCEA LPDIDEVICEOBJECTINSTANCE;
#endif

typedef struct {
    DWORD dwSize;
    GUID  guidInstance;
    GUID  guidProduct;
    DWORD dwDevType;
    CHAR  tszInstanceName[MAX_PATH];
    CHAR  tszProductName[MAX_PATH];
    GUID  guidFFDriver;
    WORD  wUsagePage;
    WORD  wUsage;
} DIDEVICEINSTANCEA, *LPDIDEVICEINSTANCEA;
typedef struct {
    DWORD dwSize;
    GUID  guidInstance;
    GUID  guidProduct;
    DWORD dwDevType;
    WCHAR tszInstanceName[MAX_PATH];
    WCHAR tszProductName[MAX_PATH];
    GUID  guidFFDriver;
    WORD  wUsagePage;
    WORD  wUsage;
} DIDEVICEINSTANCEW, *LPDIDEVICEINSTANCEW;
#ifdef UNICODE
typedef DIDEVICEINSTANCEW DIDEVICEINSTANCE;
typedef LPDIDEVICEINSTANCEW LPDIDEVICEINSTANCE;
#else
typedef DIDEVICEINSTANCEA DIDEVICEINSTANCE;
typedef LPDIDEVICEINSTANCEA LPDIDEVICEINSTANCE;
#endif

typedef struct {
    const GUID *pguid;
    DWORD   dwOfs;
    DWORD   dwType;
    DWORD   dwFlags;
} DIOBJECTDATAFORMAT, *LPDIOBJECTDATAFORMAT;

typedef struct {
    DWORD   dwSize;
    DWORD   dwObjSize;
    DWORD   dwFlags;
    DWORD   dwDataSize;
    DWORD   dwNumObjs;
    LPDIOBJECTDATAFORMAT rgodf;
} DIDATAFORMAT, *LPDIDATAFORMAT;

typedef struct DIJOYSTATE {
    LONG    lX;
    LONG    lY;
    LONG    lZ;
    LONG    lRx;
    LONG    lRy;
    LONG    lRz;
    LONG    rglSlider[2];
    DWORD   rgdwPOV[4];
    BYTE    rgbButtons[32];
} DIJOYSTATE, *LPDIJOYSTATE;

// Macros
#define DI_OK 0
#define DI_DEGREES 100

#define DI8DEVCLASS_GAMECTRL 4
#define DIEDFL_ALLDEVICES 0x00000000

#define DIDFT_ALL 0x00000000
#define DIDFT_RELAXIS 0x00000001
#define DIDFT_ABSAXIS 0x00000002
#define DIDFT_AXIS 0x00000003
#define DIDFT_PSHBUTTON 0x00000004
#define DIDFT_TGLBUTTON 0x00000008
#define DIDFT_BUTTON 0x0000000C
#define DIDFT_POV 0x00000010
#define DIDFT_COLLECTION 0x00000040
#define DIDFT_NODATA 0x00000080
#define DIDFT_ANYINSTANCE 0x00FFFF00
#define DIDFT_INSTANCEMASK DIDFT_ANYINSTANCE
#define DIDFT_MAKEINSTANCE(n) ((WORD)(n) << 8)
#define DIDFT_GETTYPE(n) LOBYTE(n)
#define DIDFT_GETINSTANCE(n) LOWORD((n) >> 8)
#define DIDFT_FFACTUATOR 0x01000000
#define DIDFT_FFEFFECTTRIGGER 0x02000000
#define DIDFT_OUTPUT 0x10000000
#define DIDFT_VENDORDEFINED 0x04000000
#define DIDFT_ALIAS 0x08000000
#define DIDFT_OPTIONAL 0x80000000

#define DIJOFS_X 0
#define DIJOFS_Y 4
#define DIJOFS_Z 8
#define DIJOFS_RX 12
#define DIJOFS_RY 16
#define DIJOFS_RZ 20
#define DIJOFS_SLIDER(n) (24 + (n)*4)
#define DIJOFS_POV(n) (32 + (n)*4)
#define DIJOFS_BUTTON(n) (48 + (n))

#define DIDOI_ASPECTPOSITION 0x00000100

#define DIPH_DEVICE 0
#define DIPH_BYOFFSET 1
#define DIPH_BYID 2
#define DIPH_BYUSAGE 3

#define DIPROP_BUFFERSIZE       ((REFGUID)1)
#define DIPROP_AXISMODE         ((REFGUID)2)
#define DIPROP_GRANULARITY      ((REFGUID)3)
#define DIPROP_RANGE            ((REFGUID)4)
#define DIPROP_DEADZONE         ((REFGUID)5)
#define DIPROP_SATURATION       ((REFGUID)6)
#define DIPROP_FFGAIN           ((REFGUID)7)
#define DIPROP_FFLOAD           ((REFGUID)8)
#define DIPROP_AUTOCENTER       ((REFGUID)9)
#define DIPROP_CALIBRATIONMODE  ((REFGUID)10)
#define DIPROP_CALIBRATION      ((REFGUID)11)
#define DIPROP_GUIDANDPATH      ((REFGUID)12)
#define DIPROP_INSTANCENAME     ((REFGUID)13)
#define DIPROP_PRODUCTNAME      ((REFGUID)14)
#define DIPROP_JOYSTICKID       ((REFGUID)15)
#define DIPROP_GETPORTDISPLAYNAME ((REFGUID)16)
#define DIPROP_PHYSICALRANGE    ((REFGUID)18)
#define DIPROP_LOGICALRANGE     ((REFGUID)19)
#define DIPROP_KEYNAME          ((REFGUID)20)
#define DIPROP_CPOINTS          ((REFGUID)21)
#define DIPROP_APPDATA          ((REFGUID)22)
#define DIPROP_SCANCODE         ((REFGUID)23)
#define DIPROP_VIDPID           ((REFGUID)24)
#define DIPROP_USERNAME         ((REFGUID)25)
#define DIPROP_TYPENAME         ((REFGUID)26)

#define DIPROPAXISMODE_ABS 0
#define DIPROPAXISMODE_REL 1

#define DIENUM_STOP 0
#define DIENUM_CONTINUE 1

#define DIERR_INPUTLOST 0x8007001E // Just generic
#define DIERR_NOTACQUIRED 0x8007001C

#include <objbase.h>

// Forward Declarations
typedef struct IDirectInput8 IDirectInput8;
typedef struct IDirectInputDevice8 IDirectInputDevice8;
typedef IDirectInput8 *LPDIRECTINPUT8;
typedef IDirectInputDevice8 *LPDIRECTINPUTDEVICE8;

// Explicit COM Interface Definitions
typedef struct IDirectInput8Vtbl IDirectInput8Vtbl;
struct IDirectInput8 {
    IDirectInput8Vtbl *lpVtbl;
};
typedef IDirectInput8 IDirectInput8W;
typedef IDirectInput8 IDirectInput8A;

struct IDirectInput8Vtbl {
    HRESULT (WINAPI *QueryInterface)(IDirectInput8*, REFIID, LPVOID*);
    ULONG (WINAPI *AddRef)(IDirectInput8*);
    ULONG (WINAPI *Release)(IDirectInput8*);
    HRESULT (WINAPI *CreateDevice)(IDirectInput8*, REFGUID, LPDIRECTINPUTDEVICE8*, LPUNKNOWN);
    HRESULT (WINAPI *EnumDevices)(IDirectInput8*, DWORD, LPVOID, LPVOID, DWORD);
    HRESULT (WINAPI *GetDeviceStatus)(IDirectInput8*, REFGUID);
    HRESULT (WINAPI *RunControlPanel)(IDirectInput8*, HWND, DWORD);
    HRESULT (WINAPI *Initialize)(IDirectInput8*, HINSTANCE, DWORD);
};

typedef struct IDirectInputDevice8Vtbl IDirectInputDevice8Vtbl;
struct IDirectInputDevice8 {
    IDirectInputDevice8Vtbl *lpVtbl;
};
typedef IDirectInputDevice8 IDirectInputDevice8W;
typedef IDirectInputDevice8 IDirectInputDevice8A;

typedef const DIDATAFORMAT *LPCDIDATAFORMAT;

struct IDirectInputDevice8Vtbl {
    HRESULT (WINAPI *QueryInterface)(IDirectInputDevice8*, REFIID, LPVOID*);
    ULONG (WINAPI *AddRef)(IDirectInputDevice8*);
    ULONG (WINAPI *Release)(IDirectInputDevice8*);
    HRESULT (WINAPI *GetCapabilities)(IDirectInputDevice8*, LPDIDEVCAPS);
    HRESULT (WINAPI *EnumObjects)(IDirectInputDevice8*, LPVOID, LPVOID, DWORD);
    HRESULT (WINAPI *GetProperty)(IDirectInputDevice8*, REFGUID, LPDIPROPHEADER);
    HRESULT (WINAPI *SetProperty)(IDirectInputDevice8*, REFGUID, LPDIPROPHEADER);
    HRESULT (WINAPI *Acquire)(IDirectInputDevice8*);
    HRESULT (WINAPI *Unacquire)(IDirectInputDevice8*);
    HRESULT (WINAPI *GetDeviceState)(IDirectInputDevice8*, DWORD, LPVOID);
    HRESULT (WINAPI *GetDeviceData)(IDirectInputDevice8*, DWORD, LPVOID, DWORD*, DWORD);
    HRESULT (WINAPI *SetDataFormat)(IDirectInputDevice8*, LPCDIDATAFORMAT);
    HRESULT (WINAPI *SetEventNotification)(IDirectInputDevice8*, HANDLE);
    HRESULT (WINAPI *SetCooperativeLevel)(IDirectInputDevice8*, HWND, DWORD);
    HRESULT (WINAPI *GetObjectInfo)(IDirectInputDevice8*, LPDIDEVICEOBJECTINSTANCE, DWORD, DWORD);
    HRESULT (WINAPI *GetDeviceInfo)(IDirectInputDevice8*, LPDIDEVICEINSTANCE);
    HRESULT (WINAPI *RunControlPanel)(IDirectInputDevice8*, HWND, DWORD);
    HRESULT (WINAPI *Initialize)(IDirectInputDevice8*, HINSTANCE, DWORD, REFGUID);
    HRESULT (WINAPI *CreateEffect)(IDirectInputDevice8*, REFGUID, LPVOID, LPVOID, LPUNKNOWN);
    HRESULT (WINAPI *EnumEffects)(IDirectInputDevice8*, LPVOID, LPVOID, DWORD);
    HRESULT (WINAPI *GetEffectInfo)(IDirectInputDevice8*, LPVOID, REFGUID);
    HRESULT (WINAPI *GetForceFeedbackState)(IDirectInputDevice8*, DWORD*);
    HRESULT (WINAPI *SendForceFeedbackCommand)(IDirectInputDevice8*, DWORD);
    HRESULT (WINAPI *EnumCreatedEffectObjects)(IDirectInputDevice8*, LPVOID, LPVOID, DWORD);

    HRESULT (WINAPI *Escape)(IDirectInputDevice8*, LPVOID);
    HRESULT (WINAPI *Poll)(IDirectInputDevice8*);
    HRESULT (WINAPI *SendDeviceData)(IDirectInputDevice8*, DWORD, LPVOID, DWORD*, DWORD);
    HRESULT (WINAPI *EnumEffectsInFile)(IDirectInputDevice8*, LPCSTR, LPVOID, LPVOID, DWORD);
    HRESULT (WINAPI *WriteEffectToFile)(IDirectInputDevice8*, LPCSTR, DWORD, LPVOID, DWORD);
};

// C Macros for COM methods
#define IDirectInput8_CreateDevice(p,a,b,c) (p)->lpVtbl->CreateDevice(p,a,b,c)
#define IDirectInput8_EnumDevices(p,a,b,c,d) (p)->lpVtbl->EnumDevices(p,a,b,c,d)
#define IDirectInput8_Release(p) (p)->lpVtbl->Release(p)

#define IDirectInputDevice8_SetDataFormat(p,a) (p)->lpVtbl->SetDataFormat(p,a)
#define IDirectInputDevice8_Acquire(p) (p)->lpVtbl->Acquire(p)
#define IDirectInputDevice8_Unacquire(p) (p)->lpVtbl->Unacquire(p)
#define IDirectInputDevice8_Release(p) (p)->lpVtbl->Release(p)
#define IDirectInputDevice8_GetCapabilities(p,a) (p)->lpVtbl->GetCapabilities(p,a)
#define IDirectInputDevice8_SetProperty(p,a,b) (p)->lpVtbl->SetProperty(p,a,b)
#define IDirectInputDevice8_EnumObjects(p,a,b,c) (p)->lpVtbl->EnumObjects(p,a,b,c)
#define IDirectInputDevice8_Poll(p) (p)->lpVtbl->Poll(p)
#define IDirectInputDevice8_GetDeviceState(p,a,b) (p)->lpVtbl->GetDeviceState(p,a,b)

// Missing function pointer
 typedef HRESULT (WINAPI * PFN_DirectInput8Create)(HINSTANCE,DWORD,REFIID,LPVOID*,LPUNKNOWN);

#endif
