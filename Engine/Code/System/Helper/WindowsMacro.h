/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:56)

#ifndef SYSTEM_HELPER_WINDOWS_MACRO_H
#define SYSTEM_HELPER_WINDOWS_MACRO_H

/// Windows平台使用的宏，按需要添加于此。

#include "Platform.h"
#include "UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifndef SYSTEM_USE_WINDOWS_MACRO

    constexpr WindowsWord gMakeLanguageIDShift{ 10 };

#endif  // SYSTEM_USE_WINDOWS_MACRO

    NODISCARD constexpr WindowsWord MakeLanguageId(WindowsWord primary, WindowsWord sub) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return MAKELANGID(primary, sub);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        return (sub << gMakeLanguageIDShift) | primary;

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    NODISCARD constexpr WindowsWord GetPrimaryLanguageId(WindowsWord languageId) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return PRIMARYLANGID(languageId);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        constexpr WindowsWord primaryLanguageIDMask{ (1 << gMakeLanguageIDShift) - 1 };

        return languageId & primaryLanguageIDMask;

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    NODISCARD constexpr WindowsWord GetSubLanguageId(WindowsWord languageId) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return SUBLANGID(languageId);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        return languageId >> gMakeLanguageIDShift;

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    NODISCARD constexpr TChar* MakeIntreSource(WindowsWord id) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return MAKEINTRESOURCE(id);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        return reinterpret_cast<TChar*>(static_cast<size_t>(id));

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    NODISCARD constexpr WindowsDWord MakeLanguageCid(WindowsWord languageId, WindowsWord sortId) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return MAKELCID(languageId, sortId);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        constexpr WindowsWord makeLanguageCIDShift{ 16 };

        return (static_cast<WindowsDWord>(sortId) << makeLanguageCIDShift) | (static_cast<WindowsDWord>(languageId));

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    NODISCARD constexpr bool IsFailed(SystemHResult result) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return FAILED(result);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        return result < 0;

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    NODISCARD constexpr bool IsSucceeded(SystemHResult result) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return SUCCEEDED(result);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        return 0 <= result;

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

#ifndef SYSTEM_USE_WINDOWS_MACRO

    constexpr WindowsWord gWordShift{ 16 };
    constexpr WindowsWord gWordMask{ (1 << gWordShift) - 1 };

#endif  // SYSTEM_USE_WINDOWS_MACRO

    NODISCARD constexpr WindowsWord MakeWord(WindowsDWordPtrSizeType low, WindowsDWordPtrSizeType high) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return MAKEWORD(low, high);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        constexpr WindowsWord makeWordShift{ 8 };
        constexpr WindowsWord makeWordMask{ (1 << makeWordShift) - 1 };

        return static_cast<WindowsWord>(static_cast<WindowsByte>(low & makeWordMask) | static_cast<WindowsWord>(static_cast<WindowsByte>(high & makeWordMask)) << makeWordShift);

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    template <typename T>
    requires std::is_integral_v<T>
    NODISCARD constexpr WindowsWord GetLowWord(T param) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return LOWORD(param);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        return static_cast<WindowsWord>(param & gWordMask);

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    template <typename T>
    requires std::is_integral_v<T>
    NODISCARD constexpr WindowsWord GetHighWord(T param) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return HIWORD(param);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        return static_cast<WindowsWord>(param >> gWordShift) & gWordMask;

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    template <typename T>
    NODISCARD constexpr int PtrConversionInt(const T* ptr) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO

        return PtrToInt(ptr);

#else  // !SYSTEM_USE_WINDOWS_MACRO

        return static_cast<int>(reinterpret_cast<size_t>(ptr));

#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

#ifdef SYSTEM_USE_WINDOWS_MACRO

    constexpr WindowsBool gTrue{ TRUE };
    constexpr WindowsBool gFalse{ FALSE };

#else  // !SYSTEM_USE_WINDOWS_MACRO

    constexpr WindowsBool gTrue{ 1 };
    constexpr WindowsBool gFalse{ 0 };

#endif  // SYSTEM_USE_WINDOWS_MACRO

    // 异常码
    constexpr auto exceptionShift = 0u;

    // 设备码
    constexpr auto facilityShift = 16u;

    // 保留的(0)
    constexpr auto reservedShift = 28u;

    // MS(0) 或 自定义(1)
    constexpr auto customerShift = 29u;

    // 严重性
    constexpr auto severityShift = 30u;

    constexpr auto exceptionBit = (1u << facilityShift) - 1u;

    constexpr auto facilityBit = 0x0FFF0000u;
}

#ifdef SYSTEM_USE_WINDOWS_MACRO

    #define SYSTEM_CALL_BACK CALLBACK
    #define SYSTEM_WINAPI WINAPI
    #define SYSTEM_IN _In_
    #define SYSTEM_IN_OPT _In_opt_
    #define SYSTEM_OUT _Out_
    #define SYSTEM_OUT_OPT _Out_opt_
    #define SYSTEM_IN_OUT _Inout_
    #define SYSTEM_IN_OUT_OPT _Inout_opt_

#else  // !SYSTEM_USE_WINDOWS_MACRO

    #define SYSTEM_CALL_BACK __stdcall
    #define SYSTEM_WINAPI __stdcall
    #define SYSTEM_IN
    #define SYSTEM_IN_OPT
    #define SYSTEM_OUT
    #define SYSTEM_OUT_OPT
    #define SYSTEM_IN_OUT
    #define SYSTEM_IN_OUT_OPT

#endif  // SYSTEM_USE_WINDOWS_MACRO

#endif  // SYSTEM_HELPER_WINDOWS_MACRO_H
