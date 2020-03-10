// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 09:57)

#ifndef CORE_TOOLS_HELPER_ASSERT_TEST_MACRO_DETAIL_H
#define CORE_TOOLS_HELPER_ASSERT_TEST_MACRO_DETAIL_H

#include "CoreTools/Helper/FunctionDescribedMacro.h"

#define ASSERT_TRUE_DETAIL(condition,message,isFailureThrow) \
	    AssertTest((condition),(CORE_TOOLS_FUNCTION_DESCRIBED),(message),(isFailureThrow))

#define ASSERT_COMPARE_DETAIL(function,lhs,rhs,message,isFailureThrow) \
	    function((lhs),(rhs),(CORE_TOOLS_FUNCTION_DESCRIBED),(message),(isFailureThrow))

#define ASSERT_COMPARE_DO_NOT_USE_MESSAGE_DETAIL(function,lhs,rhs,isFailureThrow) \
	    function((lhs),(rhs),(CORE_TOOLS_FUNCTION_DESCRIBED),(isFailureThrow))

#define ASSERT_EQUAL_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertEqual),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_EQUAL_DO_NOT_USE_MESSAGE_DETAIL(lhs,rhs,isFailureThrow) \
	    ASSERT_COMPARE_DO_NOT_USE_MESSAGE_DETAIL((AssertEqualDoNotUseMessage), (lhs),(rhs),(isFailureThrow))

#define ASSERT_ENUM_EQUAL_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertEnumEqual),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_THREE_EQUAL_DETAIL(lhs,mhs,rhs,message,isFailureThrow)  \
	    AssertEqual((lhs),(mhs),(rhs),(CORE_TOOLS_FUNCTION_DESCRIBED),(message),(isFailureThrow))

#define ASSERT_FLOATING_POINT_COMPLETE_EQUAL_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertFloatingPointCompleteEqual),(lhs),(rhs),(message), (isFailureThrow))

#define ASSERT_UNEQUAL_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertUnequal),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_ENUM_UNEQUAL_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertEnumUnequal),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_UNEQUAL_DO_NOT_USE_MESSAGE_DETAIL(lhs,rhs,isFailureThrow) \
		ASSERT_COMPARE_DO_NOT_USE_MESSAGE_DETAIL((AssertUnequalDoNotUseMessage), (lhs),(rhs),(isFailureThrow))

#define ASSERT_FLOATING_POINT_COMPLETE_UNEQUAL_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertFloatingPointCompleteUnequal),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_APPROXIMATE_DETAIL(lhs,rhs,epsilon,message,isFailureThrow) \
	    AssertApproximate((lhs),(rhs),(epsilon),(CORE_TOOLS_FUNCTION_DESCRIBED), (message),(isFailureThrow))

#define ASSERT_APPROXIMATE_USE_FUNCTION_DETAIL(function,lhs,rhs,epsilon,message,isFailureThrow) \
	    AssertApproximateUseFunction((function),(lhs),(rhs),(epsilon),(CORE_TOOLS_FUNCTION_DESCRIBED),(message),(isFailureThrow))

#define ASSERT_PTR_DETAIL(function,ptr,message,isFailureThrow) \
	    function((ptr),(CORE_TOOLS_FUNCTION_DESCRIBED),(message),(isFailureThrow))

#define ASSERT_EQUAL_NULL_PTR_DETAIL(ptr,message,isFailureThrow) \
	    ASSERT_PTR_DETAIL((AssertEqualNullPtr),(ptr),(message),(isFailureThrow))

#define ASSERT_UNEQUAL_NULL_PTR_DETAIL(ptr,message,isFailureThrow) \
	    ASSERT_PTR_DETAIL((AssertUnequalNullPtr),(ptr),(message),(isFailureThrow))

#define ASSERT_RANGE_DETAIL(test,lhs,rhs,message,isFailureThrow) \
	    AssertRange((test),(lhs),(rhs),(CORE_TOOLS_FUNCTION_DESCRIBED),(message),(isFailureThrow))

#define ASSERT_LESS_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertLess),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_ENUM_LESS_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertEnumLess),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_LESS_EQUAL_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertLessEqual),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_ENUM_LESS_EQUAL_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertEnumLessEqual),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_GREATER_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertGreater),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_ENUM_GREATER_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertEnumGreater),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_GREATER_EQUAL_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertGreaterEqual),(lhs),(rhs),(message),(isFailureThrow))

#define ASSERT_ENUM_GREATER_EQUAL_DETAIL(lhs,rhs,message,isFailureThrow) \
	    ASSERT_COMPARE_DETAIL((AssertEnumGreaterEqual),(lhs),(rhs),(message),(isFailureThrow))

#endif // CORE_TOOLS_HELPER_ASSERT_TEST_MACRO_DETAIL_H
