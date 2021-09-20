// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 11:36)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_MACRO_GATEWAY_SERVER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H
#define GATEWAY_SERVER_MIDDLE_LAYER_MACRO_GATEWAY_SERVER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H

#include "UserMacro.h"
#include "CoreTools/Contract/Assertion.h"

#if defined(OPEN_IMPORTANT_EXCPTION_ASSERT)
	#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL 0
#endif // OPEN_IMPORTANT_EXCPTION_ASSERT

#if !defined(GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL)
	#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL 4
#endif // GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

static_assert(GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL <= ASSERT_LEVEL, "Assert level definition error.");

#if 0 <= GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_0(condition, format, ...) \
        ASSERTION_0((condition), (format), __VA_ARGS__)
#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_0((condition),(functionDescribed),(format), __VA_ARGS__)

#else // GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 0

#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_0(condition, format, ...) (static_cast<void>(0))
#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_0(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 0 <= GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 1 <= GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_1(condition, format, ...) \
        ASSERTION_1((condition), (format), __VA_ARGS__)
#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_1((condition),(functionDescribed),(format), __VA_ARGS__)

#else // GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 1

#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_1(condition, format, ...) (static_cast<void>(0))
#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_1(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 1 <= GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 2 <= GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_2(condition, format, ...) \
        ASSERTION_2((condition), (format), __VA_ARGS__)
#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_2((condition),(functionDescribed),(format), __VA_ARGS__)

#else // GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 2

#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_2(condition, format, ...) (static_cast<void>(0))
#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_2(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 2 <= GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 3 <= GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_3(condition, format, ...) \
        ASSERTION_3((condition), (format), __VA_ARGS__)
#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_3((condition),(functionDescribed),(format), __VA_ARGS__)

#else // GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 3

#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_3(condition, format, ...) (static_cast<void>(0))
#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_3(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 3 <= GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#if 4 <= GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_4(condition, format, ...) \
        ASSERTION_4((condition), (format), __VA_ARGS__)
#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition, functionDescribed, format, ...) \
        ASSERTION_USE_FUNCTION_DESCRIBED_4((condition),(functionDescribed),(format), __VA_ARGS__)

#else // GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL < 4

#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_4(condition, format, ...) (static_cast<void>(0))
#define GATEWAY_SERVER_MIDDLE_LAYER_ASSERTION_USE_FUNCTION_DESCRIBED_4(condition,functionDescribed,format, ...) (static_cast<void>(0))

#endif // 4 <= GATEWAY_SERVER_MIDDLE_LAYER_ASSERT_LEVEL

#endif // GATEWAY_SERVER_MIDDLE_LAYER_MACRO_GATEWAY_SERVER_MIDDLE_LAYER_CUSTOM_ASSERT_MACRO_H
