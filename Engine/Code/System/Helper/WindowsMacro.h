// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:13)

#ifndef SYSTEM_HELPER_WINDOWS_MACRO_H
#define SYSTEM_HELPER_WINDOWS_MACRO_H

// Windows平台使用的宏，按需要添加于此。

#include "Platform.h"
#include "UnicodeUsing.h"
#include "System/Com/Using/IUnknownUsing.h"
#include "System/Window/Using/WindowUsing.h" 

namespace System
{
	constexpr WindowWord g_MakeLanguageIDShift{ 10 };

	constexpr WindowWord MakeLanguageID(WindowWord primary, WindowWord sub) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return MAKELANGID(primary, sub);
#else // !SYSTEM_USE_WINDOWS_MACRO
		return (sub << g_MakeLanguageIDShift) | primary;
#endif // SYSTEM_USE_WINDOWS_MACRO
	}

	constexpr WindowWord GetPrimaryLanguageID(WindowWord languageID) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return PRIMARYLANGID(languageID);
#else // !SYSTEM_USE_WINDOWS_MACRO
		constexpr WindowWord g_PrimaryLanguageIDMask{ (1 << g_MakeLanguageIDShift) - 1 };

		return languageID & g_PrimaryLanguageIDMask;
#endif // SYSTEM_USE_WINDOWS_MACRO
	}

	constexpr WindowWord GetSubLanguageID(WindowWord languageID) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return SUBLANGID(languageID);
#else // !SYSTEM_USE_WINDOWS_MACRO
		return languageID >> g_MakeLanguageIDShift;
#endif // SYSTEM_USE_WINDOWS_MACRO
	}

	constexpr TChar* MakeIntreSource(WindowWord id) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return MAKEINTRESOURCE(id);
#else // !SYSTEM_USE_WINDOWS_MACRO
		return reinterpret_cast<TChar*>(static_cast<uint64_t>(id));
#endif // SYSTEM_USE_WINDOWS_MACRO	
	}

	constexpr WindowDWord MakeLCID(WindowWord languageID, WindowWord sortID) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return MAKELCID(languageID, sortID);
#else // !SYSTEM_USE_WINDOWS_MACRO
		constexpr WindowWord g_MakeLanguageCIDShift{ 16 };

		return (static_cast<WindowDWord>(sortID) << g_MakeLanguageCIDShift) | (static_cast<WindowDWord>(languageID));
#endif // SYSTEM_USE_WINDOWS_MACRO	
	}

	constexpr bool IsFailed(SystemHResult result) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return FAILED(result);
#else // !SYSTEM_USE_WINDOWS_MACRO
		return result < 0;
#endif // SYSTEM_USE_WINDOWS_MACRO	
	}

	constexpr bool IsSucceeded(SystemHResult result) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return SUCCEEDED(result);
#else // !SYSTEM_USE_WINDOWS_MACRO
		return 0 <= result;
#endif // SYSTEM_USE_WINDOWS_MACRO			
	}

	constexpr WindowWord g_WordShift{ 16 };
	constexpr WindowWord g_WordMask{ (1 << g_WordShift) - 1 };

	constexpr WindowWord MakeWord(WindowPtrDWord low, WindowPtrDWord high) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return  MAKEWORD(low, high);
#else // !SYSTEM_USE_WINDOWS_MACRO
		constexpr WindowWord g_MakeWordShift{ 8 };
		constexpr WindowWord g_MakeWordMask{ (1 << g_MakeWordShift) - 1 };

		return static_cast<WindowWord>(static_cast<WindowByte>(low & g_MakeWordMask) | static_cast<WindowWord>(static_cast<WindowByte>(high & g_MakeWordMask)) << g_MakeWordShift);
#endif // SYSTEM_USE_WINDOWS_MACRO	
	}

	constexpr WindowWord LowWord(WindowPtrDWord param) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return LOWORD(param);
#else // !SYSTEM_USE_WINDOWS_MACRO
		return static_cast<WindowWord>(param & g_WordMask);
#endif // SYSTEM_USE_WINDOWS_MACRO	
	}

	constexpr WindowWord HighWord(WindowPtrDWord param) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return  HIWORD(param);
#else // !SYSTEM_USE_WINDOWS_MACRO
		return static_cast<WindowWord>(param >> g_WordShift) & g_WordMask;
#endif // SYSTEM_USE_WINDOWS_MACRO	
	}

	template<typename T>
	constexpr int PtrConversionInt(const T* ptr) noexcept
	{
#ifdef SYSTEM_USE_WINDOWS_MACRO
		return PtrToInt(ptr);
#else // !SYSTEM_USE_WINDOWS_MACRO
		return static_cast<int>(reinterpret_cast<WindowPtrInt>(ptr));
#endif // SYSTEM_USE_WINDOWS_MACRO	
	}

#ifdef SYSTEM_USE_WINDOWS_MACRO
	constexpr WindowBool g_True{ TRUE };
	constexpr WindowBool g_False{ FALSE };
#else // !SYSTEM_USE_WINDOWS_MACRO
	constexpr WindowBool g_True{ 1 };
	constexpr WindowBool g_False{ 0 };
#endif // SYSTEM_USE_WINDOWS_MACRO	
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

#else // !SYSTEM_USE_WINDOWS_MACRO	

#define SYSTEM_CALL_BACK __stdcall
#define SYSTEM_WINAPI __stdcall 
#define SYSTEM_IN  
#define SYSTEM_IN_OPT 
#define SYSTEM_OUT 
#define SYSTEM_OUT_OPT 
#define SYSTEM_IN_OUT 
#define SYSTEM_IN_OUT_OPT 

#endif // SYSTEM_USE_WINDOWS_MACRO

#endif // SYSTEM_HELPER_WINDOWS_MACRO_H
