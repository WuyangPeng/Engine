// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 09:52)

// ��Ԫ����������Ҫ���쳣���Ժ�
#ifndef CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H
#define CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H

#include "CoreTools/Helper/FunctionDescribedMacro.h"

// Ҫ���Ե�function���������ء�
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
