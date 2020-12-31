//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/09/28 13:46)

// ��Ԫ����������Ҫ���쳣���Ժ�
#ifndef CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H
#define CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H

#include "CoreTools/Helper/FunctionDescribedMacro.h"

// Ҫ���Ե�function���������ء�
#define ASSERT_NOT_THROW_EXCEPTION_0(function) \
    AssertNotThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_NOT_THROW_EXCEPTION_1(function, parameter) \
    AssertNotThrowException(this, &ClassType::function, (parameter), (CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_NOT_THROW_EXCEPTION_2(function, parameter1, parameter2) \
    AssertNotThrowException(this, &ClassType::function, (parameter1), (parameter2), (CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_THROW_EXCEPTION_0(function) \
    AssertThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_THROW_EXCEPTION_1(function, parameter) \
    AssertThrowException(this, &ClassType::function, (parameter), (CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_THROW_EXCEPTION_2(function, parameter1, parameter2) \
    AssertThrowException(this, &ClassType::function, (parameter1), (parameter2), (CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_0(function, message) \
    AssertNotThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_1(function, parameter, message) \
    AssertNotThrowException(this, &ClassType::function, (parameter), (CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_2(function, parameter1, parameter2, message) \
    AssertNotThrowException(this, &ClassType::function, (parameter1), (parameter2), (CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_THROW_EXCEPTION_USE_MESSAGE_0(function, message) \
    AssertThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_THROW_EXCEPTION_USE_MESSAGE_1(function, parameter, message) \
    AssertThrowException(this, &ClassType::function, (parameter), (CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_THROW_EXCEPTION_USE_MESSAGE_2(function, parameter1, parameter2, message) \
    AssertThrowException(this, &ClassType::function, (parameter1), (parameter2), (CORE_TOOLS_FUNCTION_DESCRIBED), message)

#define ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(function) \
    AssertNotThrowException<ClassType, decltype(&ClassType::ExecuteLoopTesting<ClassType, decltype(&ClassType::function)>), ClassType*, decltype(&ClassType::function)>(this, &ClassType::ExecuteLoopTesting<ClassType, decltype(&ClassType::function)>, this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED))

#define ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION_USE_MESSAGE(function, message) \
    AssertNotThrowException<ClassType, decltype(&ClassType::ExecuteLoopTesting<ClassType, decltype(&ClassType::function)>), ClassType*, decltype(&ClassType::function)>(this, &ClassType::ExecuteLoopTesting<ClassType, decltype(&ClassType::function)>, this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), message)

#endif  // CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H
