///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/17 10:38)

#ifndef SYSTEM_HELPER_WINDOWS_MACRO_H
#define SYSTEM_HELPER_WINDOWS_MACRO_H

// Windows平台使用的宏，按需要添加于此。

#include "Platform.h"
#include "UnicodeUsing.h"
#include "System/Helper/PragmaWarning/CallTraits.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    template <typename T, size_t N>
    NODISCARD constexpr size_t GetArraySize(T (&)[N]) noexcept
    {
        return N;
    }

    template <typename... T>
    void NullFunction(MAYBE_UNUSED typename boost::call_traits<T>::param_type... value) noexcept
    {
    }

#ifndef SYSTEM_USE_WINDOWS_MACRO
    constexpr WindowsWord g_MakeLanguageIDShift{ 10 };
#endif  // SYSTEM_USE_WINDOWS_MACRO

    NODISCARD constexpr WindowsWord MakeLanguageID(WindowsWord primary, WindowsWord sub) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO
        return MAKELANGID(primary, sub);
#else  // !SYSTEM_USE_WINDOWS_MACRO
        return (sub << g_MakeLanguageIDShift) | primary;
#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    NODISCARD constexpr WindowsWord GetPrimaryLanguageID(WindowsWord languageID) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO
        return PRIMARYLANGID(languageID);
#else  // !SYSTEM_USE_WINDOWS_MACRO
        constexpr WindowsWord g_PrimaryLanguageIDMask{ (1 << g_MakeLanguageIDShift) - 1 };

        return languageID & g_PrimaryLanguageIDMask;
#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    NODISCARD constexpr WindowsWord GetSubLanguageID(WindowsWord languageID) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO
        return SUBLANGID(languageID);
#else  // !SYSTEM_USE_WINDOWS_MACRO
        return languageID >> g_MakeLanguageIDShift;
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

    NODISCARD constexpr WindowsDWord MakeLanguageCID(WindowsWord languageID, WindowsWord sortID) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO
        return MAKELCID(languageID, sortID);
#else  // !SYSTEM_USE_WINDOWS_MACRO
        constexpr WindowsWord g_MakeLanguageCIDShift{ 16 };

        return (static_cast<WindowsDWord>(sortID) << g_MakeLanguageCIDShift) | (static_cast<WindowsDWord>(languageID));
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
    constexpr WindowsWord g_WordShift{ 16 };
    constexpr WindowsWord g_WordMask{ (1 << g_WordShift) - 1 };
#endif  // SYSTEM_USE_WINDOWS_MACRO

    NODISCARD constexpr WindowsWord MakeWord(WindowsPtrDWord low, WindowsPtrDWord high) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO
        return MAKEWORD(low, high);
#else  // !SYSTEM_USE_WINDOWS_MACRO
        constexpr WindowsWord g_MakeWordShift{ 8 };
        constexpr WindowsWord g_MakeWordMask{ (1 << g_MakeWordShift) - 1 };

        return static_cast<WindowsWord>(static_cast<WindowsByte>(low & g_MakeWordMask) | static_cast<WindowWord>(static_cast<WindowsByte>(high & g_MakeWordMask)) << g_MakeWordShift);
#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    NODISCARD constexpr WindowsWord LowWord(WindowsPtrDWord param) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO
        return LOWORD(param);
#else  // !SYSTEM_USE_WINDOWS_MACRO
        return static_cast<WindowsWord>(param & g_WordMask);
#endif  // SYSTEM_USE_WINDOWS_MACRO
    }

    NODISCARD constexpr WindowsWord HighWord(WindowsPtrDWord param) noexcept
    {
#ifdef SYSTEM_USE_WINDOWS_MACRO
        return HIWORD(param);
#else  // !SYSTEM_USE_WINDOWS_MACRO
        return static_cast<WindowsWord>(param >> g_WordShift) & g_WordMask;
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
    constexpr WindowsBool g_True{ TRUE };
    constexpr WindowsBool g_False{ FALSE };
#else  // !SYSTEM_USE_WINDOWS_MACRO
    constexpr WindowsBool g_True{ 1 };
    constexpr WindowsBool g_False{ 0 };
#endif  // SYSTEM_USE_WINDOWS_MACRO
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

#if defined(_DEBUG) && !defined(NDEBUG)
constexpr auto isDebug = true;
#else  // !_DEBUG
constexpr auto isDebug = false;
#endif  // _DEBUG

constexpr auto isRelease = !isDebug;

#endif  // SYSTEM_HELPER_WINDOWS_MACRO_H
