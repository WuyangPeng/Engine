///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 0:58)

// 单元测试类所需要的测试断言宏
#ifndef CORE_TOOLS_HELPER_ASSERT_TEST_MACRO_H
#define CORE_TOOLS_HELPER_ASSERT_TEST_MACRO_H

#include "Detail/AssertTestMacroDetail.h"

// 若condition、lhs、rhs中含有模板，请使用双重括号。

// assert true
#define ASSERT_TRUE(condition) \
    ASSERT_TRUE_DETAIL((condition), (""), (false))

#define ASSERT_TRUE_USE_MESSAGE(condition, message) \
    ASSERT_TRUE_DETAIL((condition), (message), (false))

#define ASSERT_TRUE_FAILURE_THROW(condition, message) \
    ASSERT_TRUE_DETAIL((condition), (message), (true))

// assert false
#define ASSERT_FALSE(condition) \
    ASSERT_TRUE_DETAIL(!(condition), (""), (false))

#define ASSERT_FALSE_USE_MESSAGE(condition, message) \
    ASSERT_TRUE_DETAIL(!(condition), (message), (false))

#define ASSERT_FALSE_FAILURE_THROW(condition, message) \
    ASSERT_TRUE_DETAIL(!(condition), (message), (true))

// assert equal
#define ASSERT_EQUAL(lhs, rhs) \
    ASSERT_EQUAL_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_EQUAL_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_EQUAL_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_EQUAL_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_EQUAL_DETAIL((lhs), (rhs), (message), (true))

#define ASSERT_ENUM_EQUAL(lhs, rhs) \
    ASSERT_ENUM_EQUAL_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_ENUM_EQUAL_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_ENUM_EQUAL_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_ENUM_EQUAL_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_ENUM_EQUAL_DETAIL((lhs), (rhs), (message), (true))

#define ASSERT_THREE_EQUAL(lhs, mhs, rhs) \
    ASSERT_THREE_EQUAL_DETAIL((lhs), (mhs), (rhs), (""), (false))

#define ASSERT_THREE_EQUAL_USE_MESSAGE(lhs, mhs, rhs, message) \
    ASSERT_THREE_EQUAL_DETAIL((lhs), (mhs), (rhs), (message), (false))

#define ASSERT_THREE_EQUAL_FAILURE_THROW(lhs, mhs, rhs, message) \
    ASSERT_THREE_EQUAL_DETAIL((lhs), (mhs), (rhs), (message), (true))

#define ASSERT_FLOATING_POINT_COMPLETE_EQUAL(lhs, rhs) \
    ASSERT_FLOATING_POINT_COMPLETE_EQUAL_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_FLOATING_POINT_COMPLETE_EQUAL_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_FLOATING_POINT_COMPLETE_EQUAL_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_FLOATING_POINT_COMPLETE_EQUAL_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_FLOATING_POINT_COMPLETE_EQUAL_DETAIL((lhs), (rhs), (message), (true))

// assert unequal
#define ASSERT_UNEQUAL(lhs, rhs) \
    ASSERT_UNEQUAL_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_UNEQUAL_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_UNEQUAL_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_UNEQUAL_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_UNEQUAL_DETAIL((lhs), (rhs), (message), (true))

#define ASSERT_ENUM_UNEQUAL(lhs, rhs) \
    ASSERT_ENUM_UNEQUAL_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_ENUM_UNEQUAL_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_ENUM_UNEQUAL_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_ENUM_UNEQUAL_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_ENUM_UNEQUAL_DETAIL((lhs), (rhs), (message), (true))

#define ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL(lhs, rhs) \
    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_DETAIL((lhs), (rhs), (message), (true))

// assert approximate
#define ASSERT_APPROXIMATE_FLOAT_ZERO(test) \
    ASSERT_APPROXIMATE((test), (0.0f), (Mathematics::MathF::GetZeroTolerance()))

#define ASSERT_APPROXIMATE_DOUBLE_ZERO(test) \
    ASSERT_APPROXIMATE((test), (0.0), (Mathematics::MathD::GetZeroTolerance()))

#define ASSERT_APPROXIMATE(lhs, rhs, epsilon) \
    ASSERT_APPROXIMATE_DETAIL((lhs), (rhs), (epsilon), (""), (false))

#define ASSERT_APPROXIMATE_USE_MESSAGE(lhs, rhs, epsilon, message) \
    ASSERT_APPROXIMATE_DETAIL((lhs), (rhs), (epsilon), (message), (false))

#define ASSERT_APPROXIMATE_FAILURE_THROW(lhs, rhs, epsilon, message) \
    ASSERT_APPROXIMATE_DETAIL((lhs), (rhs), (epsilon), (message), (true))

#define ASSERT_APPROXIMATE_USE_FUNCTION(function, lhs, rhs, epsilon) \
    ASSERT_APPROXIMATE_USE_FUNCTION_DETAIL((function), (lhs), (rhs), (epsilon), (""), (false))

#define ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(function, lhs, rhs, epsilon, message) \
    ASSERT_APPROXIMATE_USE_FUNCTION_DETAIL((function), (lhs), (rhs), (epsilon), (message), (false))

#define ASSERT_APPROXIMATE_USE_FUNCTION_FAILURE_THROW(function, lhs, rhs, epsilon, message) \
    ASSERT_APPROXIMATE_USE_FUNCTION_DETAIL((function), (lhs), (rhs), (epsilon), (message), (true))

// assert less
#define ASSERT_LESS(lhs, rhs) \
    ASSERT_LESS_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_LESS_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_LESS_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_LESS_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_LESS_DETAIL((lhs), (rhs), (message), (true))

#define ASSERT_ENUM_LESS(lhs, rhs) \
    ASSERT_ENUM_LESS_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_ENUM_LESS_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_ENUM_LESS_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_ENUM_LESS_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_ENUM_LESS_DETAIL((lhs), (rhs), (message), (true))

// assert less equal
#define ASSERT_LESS_EQUAL(lhs, rhs) \
    ASSERT_LESS_EQUAL_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_LESS_EQUAL_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_LESS_EQUAL_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_LESS_EQUAL_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_LESS_EQUAL_DETAIL((lhs), (rhs), (message), (true))

#define ASSERT_ENUM_LESS_EQUAL(lhs, rhs) \
    ASSERT_ENUM_LESS_EQUAL_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_ENUM_LESS_EQUAL_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_ENUM_LESS_EQUAL_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_ENUM_LESS_EQUAL_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_ENUM_LESS_EQUAL_DETAIL((lhs), (rhs), (message), (true))

// assert greater
#define ASSERT_GREATER(lhs, rhs) \
    ASSERT_GREATER_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_GREATER_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_GREATER_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_GREATER_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_GREATER_DETAIL((lhs), (rhs), (message), (true))

#define ASSERT_ENUM_GREATER(lhs, rhs) \
    ASSERT_ENUM_GREATER_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_ENUM_GREATER_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_ENUM_GREATER_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_ENUM_GREATER_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_ENUM_GREATER_DETAIL((lhs), (rhs), (message), (true))

// assert greater equal
#define ASSERT_GREATER_EQUAL(lhs, rhs) \
    ASSERT_GREATER_EQUAL_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_GREATER_EQUAL_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_GREATER_EQUAL_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_GREATER_EQUAL_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_GREATER_EQUAL_DETAIL((lhs), (rhs), (message), (true))

#define ASSERT_ENUM_GREATER_EQUAL(lhs, rhs) \
    ASSERT_ENUM_GREATER_EQUAL_DETAIL((lhs), (rhs), (""), (false))

#define ASSERT_ENUM_GREATER_EQUAL_USE_MESSAGE(lhs, rhs, message) \
    ASSERT_ENUM_GREATER_EQUAL_DETAIL((lhs), (rhs), (message), (false))

#define ASSERT_ENUM_GREATER_EQUAL_FAILURE_THROW(lhs, rhs, message) \
    ASSERT_ENUM_GREATER_EQUAL_DETAIL((lhs), (rhs), (message), (true))

// assert equal nullptr
#define ASSERT_EQUAL_NULL_PTR(ptr) \
    ASSERT_EQUAL_NULL_PTR_DETAIL((ptr), (""), (false))

#define ASSERT_EQUAL_NULL_PTR_USE_MESSAGE(ptr, message) \
    ASSERT_EQUAL_NULL_PTR_DETAIL((ptr), (message), (false))

#define ASSERT_EQUAL_NULL_PTR_FAILURE_THROW(ptr, message) \
    ASSERT_EQUAL_NULL_PTR_DETAIL((ptr), (message), (true))

// assert unequal nullptr
#define ASSERT_UNEQUAL_NULL_PTR(ptr) \
    ASSERT_UNEQUAL_NULL_PTR_DETAIL((ptr), (""), (false))

#define ASSERT_UNEQUAL_NULL_PTR_USE_MESSAGE(ptr, message) \
    ASSERT_UNEQUAL_NULL_PTR_DETAIL((ptr), (message), (false))

#define ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(ptr, message) \
    ASSERT_UNEQUAL_NULL_PTR_DETAIL((ptr), (message), (true))

// assert range [ ]
#define ASSERT_RANGE(test, lhs, rhs) \
    ASSERT_RANGE_DETAIL((test), (lhs), (rhs), (""), (false))

#define ASSERT_RANGE_USE_MESSAGE(test, lhs, rhs, message) \
    ASSERT_RANGE_DETAIL((test), (lhs), (rhs), (message), (false))

#define ASSERT_RANGE_FAILURE_THROW(test, lhs, rhs, message) \
    ASSERT_RANGE_DETAIL((test), (lhs), (rhs), (message), (true))

#endif  // CORE_TOOLS_HELPER_ASSERT_TEST_MACRO_H