// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 10:09)

#ifndef CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
#define CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H

#include "FunctionDescribedMacro.h"

// 用来启用或禁用各种断言子系统的宏。目前断言系统只在Microsoft Visual Studio中实现。
#if defined(OPEN_ASSERT) || defined(OPEN_IMPORTANT_EXCPTION_ASSERT)

	#if defined(SYSTEM_PLATFORM_WIN32) && defined(TCRE_USE_MSVC)
		#define CORE_TOOLS_USE_ASSERT
	#endif // defined(WIN32) && defined(TCRE_USE_MSVC)

#endif // defined(OPEN_ASSERT) || defined(OPEN_IMPORTANT_EXCPTION_ASSERT)

#ifdef CORE_TOOLS_USE_ASSERT

	#define ASSERTION(condition, format, ...) \
			CoreTools::Assertion{(condition),(CORE_TOOLS_FUNCTION_DESCRIBED), (format), __VA_ARGS__}

	#define ASSERTION_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) \
			CoreTools::Assertion{(condition),(functionDescribed),(format), __VA_ARGS__}

#else // !CORE_TOOLS_USE_ASSERT

	// 关闭断言。
	#define ASSERTION(condition, format, ...) ((void)0)
	#define ASSERTION_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) ((void)0)

#endif // CORE_TOOLS_USE_ASSERT

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

// 0：非常重要的断言。断言失败会导致程序崩溃。
// 1：重要的断言。断言失败会导致程序抛出异常或内存泄露。
// 2：一般的断言。断言失败会导致逻辑错误。
// 3：不重要的断言。断言失败会导致显示或计算错误。
// 4：可以忽略的断言。断言失败会导致数值精度不足。
#if !defined(ASSERT_LEVEL)
	#define ASSERT_LEVEL 4
#endif // ASSERT_LEVEL

#if defined(_DEBUG) && 0 <= ASSERT_LEVEL

	#define ASSERTION_DEBUG(condition, format, ...) \
			ASSERTION(condition, format, __VA_ARGS__)
	#define ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, __VA_ARGS__)

#else // !defined(_DEBUG) || ASSERT_LEVEL < 0

	#define ASSERTION_DEBUG(condition, format, ...) ((void)0)
	#define ASSERTION_DEBUG_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, ...) ((void)0)

#endif // defined(_DEBUG) && 0 <= ASSERT_LEVEL

#if 0 <= ASSERT_LEVEL

	#define ASSERTION_0(condition, format, ...) \
			ASSERTION(condition, format, __VA_ARGS__)
	#define ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, __VA_ARGS__)

#else // ASSERT_LEVEL < 0

	#define ASSERTION_0(condition, format, ...) ((void)0)
	#define ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) ((void)0)

#endif //0 <= ASSERT_LEVEL

#if 1 <= ASSERT_LEVEL

	#define ASSERTION_1(condition, format, ...) \
			ASSERTION(condition, format, __VA_ARGS__)
	#define ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, __VA_ARGS__)

#else // ASSERT_LEVEL < 1

	#define ASSERTION_1(condition, format, ...) ((void)0)
	#define ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) ((void)0)

#endif // 1 <= ASSERT_LEVEL

#if 2 <= ASSERT_LEVEL

	#define ASSERTION_2(condition, format, ...) \
			ASSERTION(condition, format, __VA_ARGS__)
	#define ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, __VA_ARGS__)

#else // ASSERT_LEVEL < 2

	#define ASSERTION_2(condition, format, ...) ((void)0)
	#define ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) ((void)0)

#endif // 2 <= ASSERT_LEVEL

#if 3 <= ASSERT_LEVEL

	#define ASSERTION_3(condition, format, ...) \
			ASSERTION(condition, format, __VA_ARGS__)
	#define ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, __VA_ARGS__)

#else // ASSERT_LEVEL < 3

	#define ASSERTION_3(condition, format, ...) ((void)0)
	#define ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) ((void)0)

#endif // 3 <= ASSERT_LEVEL

#if 4 <= ASSERT_LEVEL

	#define ASSERTION_4(condition, format, ...) \
			ASSERTION(condition, format, __VA_ARGS__)
	#define ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
			ASSERTION_USE_FUNCTION_DESCRIBED(condition,functionDescribed,format, __VA_ARGS__)

#else // ASSERT_LEVEL < 4

	#define ASSERTION_4(condition, format, ...) ((void)0)
	#define ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) ((void)0)

#endif // 4 <= ASSERT_LEVEL

#endif // CORE_TOOLS_HELPER_CUSTOM_ASSERT_MACRO_H
