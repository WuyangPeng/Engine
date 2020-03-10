// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 09:52)

// 单元测试类所需要的异常断言宏
#ifndef CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H
#define CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H

#include "CoreTools/Helper/FunctionDescribedMacro.h"

// 要测试的function不允许重载。
#define ASSERT_NOT_THROW_EXCEPTION_0(function) \
	    AssertNotThrowException(this,&ClassType::function,(CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_NOT_THROW_EXCEPTION_1(function,parameter) \
	    AssertNotThrowException(this,&ClassType::function,(parameter),(CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_NOT_THROW_EXCEPTION_2(function,parameter1,parameter2) \
	    AssertNotThrowException(this,&ClassType::function,(parameter1),(parameter2),(CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_THROW_EXCEPTION_0(function) \
	    AssertThrowException(this,&ClassType::function,(CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_THROW_EXCEPTION_1(function,parameter) \
	    AssertThrowException(this,&ClassType::function,(parameter), (CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_THROW_EXCEPTION_2(function,parameter1,parameter2) \
	    AssertThrowException(this,&ClassType::function,(parameter1),(parameter2),(CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_0(function,message) \
	    AssertNotThrowException(this,&ClassType::function,(CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_1(function,parameter,message) \
	    AssertNotThrowException(this,&ClassType::function,(parameter),(CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_2(function,parameter1, parameter2, message) \
	    AssertNotThrowException(this,&ClassType::function,(parameter1), (parameter2),(CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_THROW_EXCEPTION_USE_MESSAGE_0(function,message) \
	    AssertThrowException(this,&ClassType::function,(CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_THROW_EXCEPTION_USE_MESSAGE_1(function,parameter,message) \
	    AssertThrowException(this,&ClassType::function,(parameter),(CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_THROW_EXCEPTION_USE_MESSAGE_2(function,parameter1, parameter2, message) \
	    AssertThrowException(this,&ClassType::function,(parameter1),(parameter2),(CORE_TOOLS_FUNCTION_DESCRIBED), message)

#endif // CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H
