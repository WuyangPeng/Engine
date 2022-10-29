///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 12:49)

#ifndef SYSTEM_WINDOWS_WINDOWS_USING_H
#define SYSTEM_WINDOWS_WINDOWS_USING_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <TlHelp32.h>
#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WindowsInt = INT;
    using WindowsIntPtr = LPINT;
    using WindowsUInt = UINT;
    using WindowsUIntPtr = LPUINT;
    using WindowsLong = LONG;
    using WindowsLongPtr = LPLONG;
    using WindowsULong = ULONG;
    using WindowsULongPtr = PULONG;
    using WindowsBool = BOOL;
    using WindowsBoolPtr = LPBOOL;
    using WindowsBoolean = BOOLEAN;
    using WindowsUShort = USHORT;
    using WindowsUShortPtr = PUSHORT;
    using WindowsSize = SIZE_T;
    using WindowsSizePtr = PSIZE_T;
    using WindowsUChar = UCHAR;
    using WindowsUCharPtr = PUCHAR;
    using WindowsLongLong = LONGLONG;
    using WindowsLongLongPtr = PLONGLONG;
    using WindowsByte = BYTE;
    using WindowsBytePtr = PBYTE;

    using WindowsInt32 = INT32;
    using WindowsInt64 = INT64;

    using WindowsULargeInteger = ULARGE_INTEGER;
    using WindowsULargeIntegerPtr = PULARGE_INTEGER;
    using WindowsLargeInteger = LARGE_INTEGER;
    using WindowsLargeIntegerPtr = PLARGE_INTEGER;

    using WindowsConstGuidPtr = LPCGUID;
    using WindowsConstVoidPtr = LPCVOID;
    using WindowsVoidPtr = LPVOID;

    using WindowsWord = WORD;
    using WindowsWordPtr = LPWORD;
    using WindowsDWord = DWORD;
    using WindowsDWordPtr = PDWORD;

    using WindowsPtrULong = ULONG_PTR;
    using WindowsPtrULongPtr = PULONG_PTR;
    using WindowsPtrLong = LONG_PTR;
    using WindowsPtrInt = INT_PTR;
    using WindowsPtrDWord = DWORD_PTR;

    using WindowsPointSize = SIZE;

    using WindowsHInstance = HINSTANCE;
    using WindowsLParam = LPARAM;
    using WindowsWParam = WPARAM;
    using WindowsPoint = POINT;
    using WindowsHWnd = HWND;
    using WindowsHMenu = HMENU;
    using WindowsRect = RECT;
    using WindowsMsg = MSG;
    using WindowsHAccel = HACCEL;
    using WindowsHLocal = HLOCAL;
    using WindowsLResult = LRESULT;
    using WindowsProcess = WNDPROC;
    using WindowsHDC = HDC;
    using WindowsPaintStruct = PAINTSTRUCT;
    using WindowsAtom = ATOM;
    using WindowsClassEx = WNDCLASSEX;
    using WindowsSystemInfo = SYSTEM_INFO;
    using WindowsHandle = HANDLE;
    using WindowsHandlePtr = PHANDLE;
    using WindowsDlgProc = DLGPROC;

    constexpr auto gMaxModuleName32 = MAX_MODULE_NAME32;
    constexpr auto gWindowExceptionMaximumParameters = EXCEPTION_MAXIMUM_PARAMETERS;
    const WindowsHandle gInvalidHandleValue{ INVALID_HANDLE_VALUE };

    using WindowsModuleEntry32 = MODULEENTRY32;
    using WindowsModuleEntry32Ptr = LPMODULEENTRY32;
    using WindowsExceptionRecord = EXCEPTION_RECORD;
    using WindowsExceptionRecordPtr = PEXCEPTION_RECORD;
    using WindowsContext = CONTEXT;
    using WindowsContextPtr = PCONTEXT;
    using WindowsExceptionPointers = EXCEPTION_POINTERS;
    using WindowsExceptionPointersPtr = PEXCEPTION_POINTERS;
    using WindowsImageImportDescriptor = IMAGE_IMPORT_DESCRIPTOR;
    using WindowsImageImportDescriptorPtr = PIMAGE_IMPORT_DESCRIPTOR;
    using WindowsTextMetric = TEXTMETRIC;

    constexpr WindowsDWord gMaxPath{ MAX_PATH };

    using SystemHResult = HRESULT;
    using SystemIID = IID;
    using SystemCLSID = CLSID;
    using SystemGUID = GUID;

    constexpr SystemHResult g_ResultOK{ S_OK };
    constexpr SystemHResult g_ResultNoInterface{ E_NOINTERFACE };
    constexpr SystemHResult g_ResultClassNoaggregation{ CLASS_E_NOAGGREGATION };
    constexpr SystemHResult g_NoError{ NOERROR };

    using GetWindowsInformationFunction = decltype(::GetClassName);

#else  // !SYSTEM_PLATFORM_WIN32

    using WindowsInt = int;
    using WindowsIntPtr = WindowsInt*;
    using WindowsUInt = uint32_t;
    using WindowsUIntPtr = WindowsUInt*;
    using WindowsLong = long;
    using WindowsLongPtr = WindowsLong*;
    using WindowsULong = unsigned long;
    using WindowsULongPtr = WindowsULong*;
    using WindowsBool = int;
    using WindowsBoolPtr = WindowsBool*;
    using WindowsBoolean = uint8_t;
    using WindowsUShort = uint16_t;
    using WindowsUShortPtr = WindowsUShort*;
    using WindowsSize = uint64_t;
    using WindowsSizePtr = WindowsSize*;
    using WindowsUChar = uint8_t;
    using WindowsUCharPtr = WindowsUChar*;
    using WindowsLongLong = int64_t;
    using WindowsLongLongPtr = WindowsLongLong*;
    using WindowsByte = unsigned char;
    using WindowsBytePtr = WindowsByte*;

    using WindowsInt32 = int32_t;
    using WindowsInt64 = int64_t;

    union WindowsULargeInteger
    {
        struct
        {
            uint32_t LowPart;
            uint32_t HighPart;
        } DUMMYSTRUCTNAME;
        struct
        {
            uint32_t LowPart;
            uint32_t HighPart;
        } u;

        uint64_t QuadPart;
    };
    using WindowsULargeIntegerPtr = WindowsULargeInteger*;

    union WindowsLargeInteger
    {
        struct
        {
            uint32_t LowPart;
            int32_t HighPart;
        } DUMMYSTRUCTNAME;
        struct
        {
            uint32_t LowPart;
            int32_t HighPart;
        } u;

        int64_t QuadPart;
    };
    using WindowsLargeIntegerPtr = WindowsLargeInteger*;

    using WindowsConstGuidPtr = const SystemGUID*;
    using WindowsConstVoidPtr = const void*;
    using WindowsVoidPtr = void*;

    using WindowsWord = uint16_t;
    using WindowsWordPtr = WindowsWord*;
    using WindowsDWord = uint32_t;
    using WindowsDWordPtr = WindowsDWord*;

    using WindowsPtrULong = uint64_t;
    using WindowsPtrULongPtr = uint64_t*;
    using WindowsPtrLong = int64_t;
    using WindowsPtrInt = int64_t;
    using WindowsPtrDWord = uint64_t;

    struct WindowsPointSize
    {
        WindowsLong cx;
        WindowsLong cy;
    };

    using WindowsHInstance = void*;
    using WindowsLParam = int64_t;
    using WindowsWParam = int64_t;

    struct WindowsPoint
    {
        WindowsLong x;
        WindowsLong y;
    };

    struct WindowHWndDeclare
    {
        int unused;
    };
    using WindowsHWnd = WindowHWndDeclare*;

    struct WindowHMenuDeclare
    {
        int unused;
    };
    using WindowsHMenu = WindowHMenuDeclare*;

    struct WindowsRect
    {
        WindowsLong left;
        WindowsLong top;
        WindowsLong right;
        WindowsLong bottom;
    };

    struct WindowsMsg
    {
        WindowsHWnd hwnd;
        uint32_t message;
        WindowsWParam wParam;
        WindowsLParam lParam;
        uint32_t time;
        WindowsPoint pt;
    };

    struct WindowHaccelDeclare
    {
        int unused;
    };
    using WindowsHAccel = WindowHaccelDeclare*;

    using WindowsHLocal = void*;
    using WindowsLResult = int;
    using WindowsProcess = WindowsLResult (*)(WindowsHWnd hwnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam);

    struct WindowsHDCDeclare
    {
        int unused;
    };
    using WindowsHDC = WindowsHDCDeclare*;

    struct WindowsPaintStruct
    {
        WindowsHDC hdc;
        int fErase;
        WindowsRect rcPaint;
        int fRestore;
        int fIncUpdate;
        uint8_t rgbReserved[32];
    };

    using WindowsAtom = uint16_t;

    struct WindowsClassEx
    {
        WindowsUInt cbSize;
        WindowsUInt style;
        WindowsProcess lpfnWndProc;
        int cbClsExtra;
        int cbWndExtra;
        WindowsHInstance hInstance;
        WindowsHIcon hIcon;
        WindowsHCursor hCursor;
        WindowsHBrush hbrBackground;
        const TChar* lpszMenuName;
        const TChar* lpszClassName;
        WindowsHIcon hIconSm;
    };

    struct WindowsSystemInfo
    {
        uint16_t wProcessorArchitecture;  // 处理器的体系结构
        uint16_t wReserved;
        uint32_t dwPageSize;  // 分页大小
        void* lpMinimumApplicationAddress;  // 最小寻址空间
        void* lpMaximumApplicationAddress;  // 最大寻址空间
        uint32_t dwActiveProcessorMask;  // 处理器掩码
        uint32_t dwNumberOfProcessors;  // 处理器数目
        uint32_t dwProcessorType;  // 处理器类型
        uint32_t dwAllocationGranularity;  // 虚拟内存空间的粒度
        uint16_t wProcessorLevel;  // 处理器等级
        uint16_t wProcessorRevision;  // 处理器版本
    };

    using WindowsHandle = void*;
    using WindowsHandlePtr = WindowsHandle*;
    using WindowsDlgProc = WindowsPtrInt (*)(WindowsHWnd, WindowsUInt, WindowsWParam, WindowsLParam);

    constexpr int gMaxModuleName32{ 255 };
    constexpr int gWindowExceptionMaximumParameters{ 15 };
    const WindowsHandle gInvalidHandleValue{ reinterpret_cast<WindowsHandle>(int(-1)) };

    struct WindowsModuleEntry32
    {
        uint32_t dwSize;
        uint32_t th32ModuleID;
        uint32_t th32ProcessID;
        uint32_t GlblcntUsage;
        uint32_t ProccntUsage;
        unsigned char* modBaseAddr;
        uint32_t modBaseSize;
        void* hModule;
        char szModule[gMaxModuleName32 + 1];
        char szExePath[gMaxPath];
    };
    using WindowsModuleEntry32Ptr = WindowsModuleEntry32*;

    struct WindowsExceptionRecord
    {
        uint32_t ExceptionCode;
        uint32_t ExceptionFlags;
        ExceptionRecord* ExceptionRecord;
        void* ExceptionAddress;
        uint32_t NumberParameters;
        uint64_t ExceptionInformation[gWindowExceptionMaximumParameters];
    };
    using WindowsExceptionRecordPtr = WindowsExceptionRecord*;

    constexpr auto g_WindowMaximumSupportedExtension = 512;
    constexpr auto g_WindowSizeOf80387Registers = 80;

    struct WindowFloatingSaveArea
    {
        uint32_t ControlWord;
        uint32_t StatusWord;
        uint32_t TagWord;
        uint32_t ErrorOffset;
        uint32_t ErrorSelector;
        uint32_t DataOffset;
        uint32_t DataSelector;
        unsigned char RegisterArea[g_WindowSizeOf80387Registers];
        uint32_t Cr0NpxState;
    };

    struct WindowsContext
    {
        uint32_t ContextFlags;
        uint32_t Dr0;
        uint32_t Dr1;
        uint32_t Dr2;
        uint32_t Dr3;
        uint32_t Dr6;
        uint32_t Dr7;
        WindowFloatingSaveArea FloatSave;
        uint32_t SegGs;
        uint32_t SegFs;
        uint32_t SegEs;
        uint32_t SegDs;
        uint32_t Edi;
        uint32_t Esi;
        uint32_t Ebx;
        uint32_t Edx;
        uint32_t Ecx;
        uint32_t Eax;
        uint32_t Ebp;
        uint32_t Eip;
        uint32_t SegCs;
        uint32_t EFlags;
        uint32_t Esp;
        uint32_t SegSs;
        unsigned char ExtendedRegisters[g_WindowMaximumSupportedExtension];
    };
    using PWindowContext = WindowsContext*;

    struct WindowsExceptionPointers
    {
        WindowsExceptionRecordPtr ExceptionRecord;
        WindowsContextPtr ContextRecord;
    };
    using WindowsExceptionPointersPtr = WindowsExceptionPointers*;

    struct WindowsImageImportDescriptor
    {
        union DUMMYUNIONNAME
        {
            uint32_t Characteristics;
            uint32_t OriginalFirstThunk;
        };

        uint32_t TimeDateStamp;
        uint32_t ForwarderChain;
        uint32_t Name;
        uint32_t FirstThunk;
    };
    using WindowsImageImportDescriptorPtr = WindowsImageImportDescriptor*;

    struct WindowsTextMetric
    {
        long tmHeight;
        long tmAscent;
        long tmDescent;
        long tmInternalLeading;
        long tmExternalLeading;
        long tmAveCharWidth;
        long tmMaxCharWidth;
        long tmWeight;
        long tmOverhang;
        long tmDigitizedAspectX;
        long tmDigitizedAspectY;
        TChar tmFirstChar;
        TChar tmLastChar;
        TChar tmDefaultChar;
        TChar tmBreakChar;
        uint8_t tmItalic;
        uint8_t tmUnderlined;
        uint8_t tmStruckOut;
        uint8_t tmPitchAndFamily;
        uint8_t tmCharSet;
    };

    constexpr WindowsDWord gMaxPath{ 260 };

    using SystemHResult = long;

    struct SystemIID
    {
        unsigned long Data1;
        unsigned short Data2;
        unsigned short Data3;
        unsigned char Data4[8];
    };

    using SystemCLSID = SystemIID;
    using SystemGUID = SystemIID;

    constexpr SystemHResult g_ResultOK{ 0 };
    constexpr SystemHResult g_ResultNoInterface{ 0x80004002L };
    constexpr SystemHResult g_ResultClassNoaggregation{ 0x80040110L };
    constexpr SystemHResult g_NoError{ 0 };

    using GetWindowsInformationFunction = int (*)(WindowsHWnd, const TChar*, int);

#endif  // SYSTEM_PLATFORM_WIN32

    using DisplayFunction = void (*)(WindowsHWnd hwnd, int64_t timeDelta);
}

#endif  // SYSTEM_WINDOWS_WINDOWS_USING_H
