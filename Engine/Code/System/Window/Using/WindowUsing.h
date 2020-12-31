//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 10:52)

#ifndef SYSTEM_WINDOW_WINDOW_USING_H
#define SYSTEM_WINDOW_WINDOW_USING_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <TlHelp32.h>
#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WindowInt = INT;
    using WindowIntPtr = LPINT;
    using WindowUInt = UINT;
    using WindowUIntPtr = LPUINT;
    using WindowLong = LONG;
    using WindowLongPtr = LPLONG;
    using WindowULong = ULONG;
    using WindowULongPtr = PULONG;
    using WindowBool = BOOL;
    using WindowBoolPtr = LPBOOL;
    using WindowBoolean = BOOLEAN;
    using WindowUShort = USHORT;
    using WindowSize = SIZE_T;
    using WindowSizePtr = PSIZE_T;
    using WindowUChar = UCHAR;
    using WindowUCharPtr = PUCHAR;
    using WindowLongLong = LONGLONG;
    using WindowByte = BYTE;

    using WindowULargeInteger = ULARGE_INTEGER;
    using WindowULargeIntegerPtr = PULARGE_INTEGER;
    using WindowLargeInteger = LARGE_INTEGER;
    using WindowLargeIntegerPtr = PLARGE_INTEGER;

    using WindowConstGuidPtr = LPCGUID;
    using WindowConstVoidPtr = LPCVOID;
    using WindowVoidPtr = LPVOID;

    using WindowWord = WORD;
    using WindowWordPtr = LPWORD;
    using WindowDWord = DWORD;
    using WindowDWordPtr = PDWORD;

    using WindowPtrULong = ULONG_PTR;
    using WindowPtrULongPtr = PULONG_PTR;
    using WindowPtrLong = LONG_PTR;
    using WindowPtrInt = INT_PTR;
    using WindowPtrDWord = DWORD_PTR;

    using WindowPointSize = SIZE;

    using WindowHInstance = HINSTANCE;
    using WindowLParam = LPARAM;
    using WindowWParam = WPARAM;
    using WindowPoint = POINT;
    using WindowHWnd = HWND;
    using WindowHMenu = HMENU;
    using WindowRect = RECT;
    using WindowMsg = MSG;
    using WindowHAccel = HACCEL;
    using WindowHLocal = HLOCAL;
    using WindowLResult = LRESULT;
    using WindowProcess = WNDPROC;
    using WindowHdc = HDC;
    using WindowPaintStruct = PAINTSTRUCT;
    using WindowAtom = ATOM;
    using WindowClassEx = WNDCLASSEX;
    using WindowSystemInfo = SYSTEM_INFO;
    using WindowHandle = HANDLE;
    using WindowHandlePtr = PHANDLE;
    using WindowDlgProc = DLGPROC;

    constexpr auto g_MaxModuleName32 = MAX_MODULE_NAME32;
    constexpr auto g_WindowExceptionMaximumParameters = EXCEPTION_MAXIMUM_PARAMETERS;
    const WindowHandle g_InvalidHandleValue{ INVALID_HANDLE_VALUE };

    using WindowModuleEntry32 = MODULEENTRY32;
    using WindowModuleEntry32Ptr = LPMODULEENTRY32;
    using WindowExceptionRecord = EXCEPTION_RECORD;
    using WindowExceptionRecordPtr = PEXCEPTION_RECORD;
    using WindowContext = CONTEXT;
    using WindowContextPtr = PCONTEXT;
    using WindowExceptionPointers = EXCEPTION_POINTERS;
    using WindowExceptionPointersPtr = PEXCEPTION_POINTERS;
    using WindowImageImportDescriptor = IMAGE_IMPORT_DESCRIPTOR;
    using WindowImageImportDescriptorPtr = PIMAGE_IMPORT_DESCRIPTOR;
    using WindowTextMetric = TEXTMETRIC;

    constexpr WindowDWord g_MaxPath{ MAX_PATH };

#else  // !SYSTEM_PLATFORM_WIN32

    using WindowInt = int;
    using WindowIntPtr = WindowInt*;
    using WindowUInt = uint32_t;
    using WindowUIntPtr = WindowUInt*;
    using WindowLong = long;
    using WindowLongPtr = WindowLong*;
    using WindowULong = unsigned long;
    using WindowULongPtr = WindowULong*;
    using WindowBool = int;
    using WindowBoolPtr = WindowBool*;
    using WindowBoolean = uint8_t;
    using WindowUShort = uint16_t;
    using WindowUChar = uint8_t;
    using WindowUCharPtr = WindowUChar*;
    using WindowLongLong = int64_t;
    using WindowByte = unsigned char;
    using WindowSize = uint64_t;
    using WindowSizePtr = WindowSize*;

    union WindowULargeInteger
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
    using WindowULargeIntegerPtr = WindowULargeInteger*;

    union WindowLargeInteger
    {
        struct
        {
            uint32_t LowPart;
            int HighPart;
        } DUMMYSTRUCTNAME;
        struct
        {
            uint32_t LowPart;
            int HighPart;
        } u;

        int64_t QuadPart;
    };
    using WindowLargeIntegerPtr = WindowLargeInteger*;

    using WindowConstVoidPtr = const void*;
    using WindowConstGuidPtr = const SystemGUID*;
    using WindowVoidPtr = void*;

    using WindowWord = uint16_t;
    using WindowWordPtr = WindowWord*;
    using WindowDWord = uint32_t;
    using WindowDWordPtr = WindowDWord*;

    using WindowPtrULong = uint64_t;
    using WindowPtrULongPtr = uint64_t*;
    using WindowPtrLong = int64_t;
    using WindowPtrInt = int64_t;
    using WindowPtrDWord = unsigned long;

    struct WindowPointSize
    {
        WindowLong cx;
        WindowLong cy;
    };

    using WindowHInstance = void*;
    using WindowLParam = int64_t;
    using WindowWParam = int64_t;

    struct WindowPoint
    {
        WindowLong x;
        WindowLong y;
    };

    struct WindowHWndDeclare
    {
        int unused;
    };
    using WindowHWnd = WindowHWndDeclare*;

    struct WindowHMenuDeclare
    {
        int unused;
    };
    using WindowHMenu = WindowHMenuDeclare*;

    struct WindowRect
    {
        WindowLong left;
        WindowLong top;
        WindowLong right;
        WindowLong bottom;
    };

    struct WindowMsg
    {
        WindowHWnd hwnd;
        uint32_t message;
        WindowWParam wParam;
        WindowLParam lParam;
        uint32_t time;
        WindowPoint pt;
    };

    struct WindowHaccelDeclare
    {
        int unused;
    };
    using WindowHAccel = WindowHaccelDeclare*;

    using WindowHLocal = void*;
    using WindowLResult = int;
    using WindowProcess = WindowLResult (*)(WindowHWnd hwnd, WindowUInt message, WindowWParam wParam, WindowLParam lParam);

    struct WindowHDCDeclare
    {
        int unused;
    };

    using WindowHdc = WindowHDCDeclare*;

    struct WindowPaintStruct
    {
        WindowHdc hdc;
        int fErase;
        WindowRect rcPaint;
        int fRestore;
        int fIncUpdate;
        uint8_t rgbReserved[32];
    };

    using WindowAtom = uint16_t;

    struct WindowClassEx
    {
        WindowUInt cbSize;
        WindowUInt style;
        WindowProcess lpfnWndProc;
        int cbClsExtra;
        int cbWndExtra;
        WindowHInstance hInstance;
        WindowHIcon hIcon;
        WindowHCursor hCursor;
        WindowHBrush hbrBackground;
        const TChar* lpszMenuName;
        const TChar* lpszClassName;
        WindowHIcon hIconSm;
    };

    struct WindowSystemInfo
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

    using WindowHandle = void*;
    using WindowHandlePtr = WindowHandle*;
    using WindowDlgProc = WindowPtrInt (*)(WindowHWnd, WindowUInt, WindowWParam, WindowLParam);

    constexpr int g_MaxModuleName32{ 255 };
    constexpr int g_WindowExceptionMaximumParameters{ 15 };
    const WindowHandle g_InvalidHandleValue{ reinterpret_cast<WindowHandle>(int(-1)) };

    struct WindowModuleEntry32
    {
        uint32_t dwSize;
        uint32_t th32ModuleID;
        uint32_t th32ProcessID;
        uint32_t GlblcntUsage;
        uint32_t ProccntUsage;
        unsigned char* modBaseAddr;
        uint32_t modBaseSize;
        void* hModule;
        char szModule[g_MaxModuleName32 + 1];
        char szExePath[g_MaxPath];
    };
    using WindowModuleEntry32Ptr = WindowModuleEntry32*;

    struct WindowExceptionRecord
    {
        uint32_t ExceptionCode;
        uint32_t ExceptionFlags;
        ExceptionRecord* ExceptionRecord;
        void* ExceptionAddress;
        uint32_t NumberParameters;
        uint64_t ExceptionInformation[g_WindowExceptionMaximumParameters];
    };

    using WindowExceptionRecordPtr = WindowExceptionRecord*;

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

    struct WindowContext
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
    using PWindowContext = WindowContext*;

    struct WindowExceptionPointers
    {
        WindowExceptionRecordPtr ExceptionRecord;
        WindowContextPtr ContextRecord;
    } using WindowExceptionPointersPtr = WindowExceptionPointers*;

    struct WindowImageImportDescriptor
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
    using WindowImageImportDescriptorPtr = WindowImageImportDescriptor*;

    struct WindowTextMetric
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

    constexpr WindowDWord g_MaxPath{ 260 };

#endif  // SYSTEM_PLATFORM_WIN32

    using DisplayFunction = void (*)(WindowHWnd hwnd, int64_t timeDelta);
}

#endif  // SYSTEM_WINDOW_WINDOW_USING_H
