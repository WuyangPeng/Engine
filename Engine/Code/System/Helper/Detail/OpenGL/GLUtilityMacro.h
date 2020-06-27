// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/07 23:43)

#ifndef SYSTEM_HELPER_GL_UTILITY_MACRO_H
#define SYSTEM_HELPER_GL_UTILITY_MACRO_H

#include "System/OpenGL/Detail/GetOpenGLFunction.h"

#ifdef SYSTEM_PLATFORM_WIN32
	// Microsoft Windows
	#define OPENGL_STDCALL __stdcall
	#define OPENGL_EXTERN __declspec(dllimport)
#else // !SYSTEM_PLATFORM_WIN32
	// Macintosh, Linux
	#define OPENGL_STDCALL
	#define OPENGL_EXTERN extern
#endif // SYSTEM_PLATFORM_WIN32

namespace System
{
	constexpr auto g_SystemOpenGLVersionNone = 0;
	constexpr auto g_SystemOpenGLVersion11 = 11;
	constexpr auto g_SystemOpenGLVersion12 = 12;
	constexpr auto g_SystemOpenGLVersion13 = 13;
	constexpr auto g_SystemOpenGLVersion14 = 14;
	constexpr auto g_SystemOpenGLVersion15 = 15;
	constexpr auto g_SystemOpenGLVersion20 = 20;
	constexpr auto g_SystemOpenGLVersion21 = 21;
	constexpr auto g_SystemOpenGLVersion30 = 30;
	constexpr auto g_SystemOpenGLVersion31 = 31;
	constexpr auto g_SystemOpenGLVersion32 = 32;
	constexpr auto g_SystemOpenGLVersion33 = 33;
	constexpr auto g_SystemOpenGLVersion40 = 40;
	constexpr auto g_SystemOpenGLVersion41 = 41;
	constexpr auto g_SystemOpenGLVersion42 = 42;
	constexpr auto g_SystemOpenGLVersion43 = 43;
	constexpr auto g_SystemOpenGLVersion44 = 44;
	constexpr auto g_SystemOpenGLVersion45 = 45;
	constexpr auto g_SystemOpenGLVersion46 = 46;
	constexpr auto g_SystemOpenGLVersionMax = 100;
}

// 如果一个函数指针为null，您可以重写指针为ARB或EXT的函数指针。设置为1为覆盖，0为不覆盖。
namespace System
{
	constexpr auto g_SystemArbOverride = 1;
	constexpr auto g_SystemExtOverride = 1;
	constexpr auto g_System3dfxOverride = 0;
	constexpr auto g_SystemAmdOverride = 0;
	constexpr auto g_SystemAngleOverride = 0;
	constexpr auto g_SystemAppleOverride = 0;
	constexpr auto g_SystemAtixOverride = 0;
	constexpr auto g_SystemAtiOverride = 0;
	constexpr auto g_SystemGremedyOverride = 0;
	constexpr auto g_SystemHpOverride = 0;
	constexpr auto g_SystemIbmOverride = 0;
	constexpr auto g_SystemIngrOverride = 0;
	constexpr auto g_SystemIntelOverride = 0;
	constexpr auto g_SystemKhrOverride = 0;
	constexpr auto g_SystemKtxOverride = 0;
	constexpr auto g_SystemMesaxOverride = 0;
	constexpr auto g_SystemMesaOverride = 0;
	constexpr auto g_SystemNvxOverride = 0;
	constexpr auto g_SystemNvOverride = 0;
	constexpr auto g_SystemOesOverride = 0;
	constexpr auto g_SystemOmlOverride = 0;
	constexpr auto g_SystemPgiOverride = 0;
	constexpr auto g_SystemRegalOverride = 0;
	constexpr auto g_SystemRendOverride = 0;
	constexpr auto g_SystemS3Override = 0;
	constexpr auto g_SystemSgisOverride = 1;
	constexpr auto g_SystemSgixOverride = 0;
	constexpr auto g_SystemSgiOverride = 1;
	constexpr auto g_SystemSunxOverride = 0;
	constexpr auto g_SystemSunOverride = 0;
	constexpr auto g_SystemWinOverride = 0;
}

#define SYSTEM_GET_FUNCTION(glFunction) \
		System::GetFunction(SYSTEM_STRINGIZE(glFunction), glFunction)

#define SYSTEM_GET_FUNCTION_SUFFIX(glFunction,suffix,allowOverride) \
		System::GetFunctionSuffix(SYSTEM_STRINGIZE(glFunction)SYSTEM_STRINGIZE(suffix), SYSTEM_CONCATENATOR(glFunction,suffix), glFunction, allowOverride)  

#define SYSTEM_GET_FUNCTION_SUFFIX_ALT(glFunction,altGlFunction,suffix,allowOverride) \
		System::GetFunctionSuffix(SYSTEM_STRINGIZE(glFunction)SYSTEM_STRINGIZE(suffix), SYSTEM_CONCATENATOR(glFunction,suffix), altGlFunction, allowOverride)

// 宏对于事先存在的函数没有返回值。

#define SYSTEM_PREVIOUSLY_BODY_0(function) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(); SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_PREVIOUSLY_BODY_1(function,a0) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(a0); SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_PREVIOUSLY_BODY_2(function,a0,a1) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(a0,a1); SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_PREVIOUSLY_BODY_3(function,a0,a1,a2) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(a0,a1,a2); SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_PREVIOUSLY_BODY_4(function,a0,a1,a2,a3) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(a0,a1,a2,a3); SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_PREVIOUSLY_BODY_5(function,a0,a1,a2,a3,a4) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(a0,a1,a2,a3,a4); SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_PREVIOUSLY_BODY_6(function,a0,a1,a2,a3,a4,a5) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(a0,a1,a2,a3,a4,a5); SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_PREVIOUSLY_BODY_7(function,a0,a1,a2,a3,a4,a5,a6) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(a0,a1,a2,a3,a4,a5,a6); SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_PREVIOUSLY_BODY_8(function,a0,a1,a2,a3,a4,a5,a6,a7) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(a0,a1,a2,a3,a4,a5,a6,a7); SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_PREVIOUSLY_BODY_9(function,a0,a1,a2,a3,a4,a5,a6,a7,a8) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(a0,a1,a2,a3,a4,a5,a6,a7,a8); SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_PREVIOUSLY_BODY_10(function,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9) \
        SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); function(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9); SYSTEM_EXIT_FUNCTION(function)

// 宏对于事先存在的函数有返回值。

#define SYSTEM_PREVIOUSLY_BODY_0_RESULT(function,type) \
        type result{ }; SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); result = function(); SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_PREVIOUSLY_BODY_1_RESULT(function,a0,type) \
        type result{ }; SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); result = function(a0); SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_PREVIOUSLY_BODY_2_RESULT(function,a0,a1,type) \
        type result{ }; SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); result = function(a0,a1); SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_PREVIOUSLY_BODY_3_RESULT(function,a0,a1,a2,type) \
        type result{ }; SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); result = function(a0,a1,a2); SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_PREVIOUSLY_BODY_4_RESULT(function,a0,a1,a2,a3,type) \
        type result{ }; SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); result = function(a0,a1,a2,a3); SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_PREVIOUSLY_BODY_5_RESULT(function,a0,a1,a2,a3,a4,type) \
        type result{ }; SYSTEM_ENTER_FUNCTION(function); SYSTEM_NONNULL_FUNCTION(function); result = function(a0,a1,a2,a3,a4); SYSTEM_EXIT_FUNCTION(function); return result

// 宏对于函数没有返回值。

#define SYSTEM_BODY_0(function) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
		function(); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_1(function,a0) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
		function(a0); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_2(function,a0,a1) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
		function(a0,a1); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_3(function,a0,a1,a2) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
		function(a0,a1,a2); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_4(function,a0,a1,a2,a3) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
		function(a0,a1,a2,a3); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_5(function,a0,a1,a2,a3,a4) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
		function(a0,a1,a2,a3,a4); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_6(function,a0,a1,a2,a3,a4,a5) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
		function(a0,a1,a2,a3,a4,a5); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_7(function,a0,a1,a2,a3,a4,a5,a6) \
        SYSTEM_ENTER_FUNCTION(function); if (function  != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
		function(a0,a1,a2,a3,a4,a5,a6); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_8(function,a0,a1,a2,a3,a4,a5,a6,a7) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
        function(a0,a1,a2,a3,a4,a5,a6,a7); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_9(function,a0,a1,a2,a3,a4,a5,a6,a7,a8) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
        function(a0,a1,a2,a3,a4,a5,a6,a7,a8); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_10(function,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
        function(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_11(function,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
        function(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_12(function,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
        function(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

#define SYSTEM_BODY_15(function,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14) \
        SYSTEM_ENTER_FUNCTION(function); if (function != nullptr) { SYSTEM_NONNULL_FUNCTION(function); \
        function(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function)

// 宏对于函数有返回值。

#define SYSTEM_BODY_0_RESULT(function,type,nullReturnValue) \
        type result{ nullReturnValue }; SYSTEM_ENTER_FUNCTION(function); if (function != nullptr){ SYSTEM_NONNULL_FUNCTION(function); \
		result = function(); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_BODY_1_RESULT(function,a0,type,nullReturnValue) \
        type result{ nullReturnValue }; SYSTEM_ENTER_FUNCTION(function); if (function != nullptr){ SYSTEM_NONNULL_FUNCTION(function); \
		result = function(a0); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_BODY_2_RESULT(function,a0,a1,type,nullReturnValue) \
        type result{ nullReturnValue }; SYSTEM_ENTER_FUNCTION(function); if (function != nullptr){ SYSTEM_NONNULL_FUNCTION(function); \
		result = function(a0,a1); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_BODY_3_RESULT(function,a0,a1,a2,type,nullReturnValue) \
        type result{ nullReturnValue }; SYSTEM_ENTER_FUNCTION(function); if (function != nullptr){ SYSTEM_NONNULL_FUNCTION(function); \
		result = function(a0,a1,a2); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_BODY_4_RESULT(function,a0,a1,a2,a3,type,nullReturnValue) \
        type result{ nullReturnValue }; SYSTEM_ENTER_FUNCTION(function); if (function != nullptr){ SYSTEM_NONNULL_FUNCTION(function); \
		result = function(a0,a1,a2,a3); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_BODY_5_RESULT(function,a0,a1,a2,a3,a4,type,nullReturnValue) \
        type result{ nullReturnValue }; SYSTEM_ENTER_FUNCTION(function); if (function != nullptr){ SYSTEM_NONNULL_FUNCTION(function); \
		result = function(a0,a1,a2,a3,a4); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_BODY_6_RESULT(function,a0,a1,a2,a3,a4,a5,type,nullReturnValue) \
        type result{ nullReturnValue }; SYSTEM_ENTER_FUNCTION(function); if (function != nullptr){ SYSTEM_NONNULL_FUNCTION(function); \
		result = function(a0,a1,a2,a3,a4,a5); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_BODY_7_RESULT(function,a0,a1,a2,a3,a4,a5,a6,type,nullReturnValue) \
        type result{ nullReturnValue }; SYSTEM_ENTER_FUNCTION(function); if (function != nullptr){ SYSTEM_NONNULL_FUNCTION(function); \
		result = function(a0,a1,a2,a3,a4,a5,a6); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function); return result

#define SYSTEM_BODY_8_RESULT(function,a0,a1,a2,a3,a4,a5,a6,a7,type,nullReturnValue) \
        type result{ nullReturnValue }; SYSTEM_ENTER_FUNCTION(function); if (function != nullptr){ SYSTEM_NONNULL_FUNCTION(function); \
		result = function(a0,a1,a2,a3,a4,a5,a6,a7); } else { SYSTEM_NULL_FUNCTION(function); } SYSTEM_EXIT_FUNCTION(function); return result 

#endif // SYSTEM_HELPER_GL_UTILITY_MACRO_H
