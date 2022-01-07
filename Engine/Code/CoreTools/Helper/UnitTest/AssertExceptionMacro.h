///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.1 (2021/07/29 16:10)

// ��Ԫ����������Ҫ���쳣���Ժ�
#ifndef CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H
#define CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H

#include "CoreTools/Helper/FunctionDescribedMacro.h"

// Ҫ���Ե�function���������ء�
#define ASSERT_NOT_THROW_EXCEPTION_0(function) \
    AssertNotThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), std::string{})

#define ASSERT_NOT_THROW_EXCEPTION_1(function, parameter) \
    AssertNotThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), std::string{}, (parameter))

#define ASSERT_NOT_THROW_EXCEPTION_2(function, parameter0, parameter1) \
    AssertNotThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), std::string{}, (parameter0), (parameter1))

#define ASSERT_THROW_EXCEPTION_0(function) \
    AssertThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), std::string{})

#define ASSERT_THROW_EXCEPTION_1(function, parameter) \
    AssertThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), std::string{}, (parameter))

#define ASSERT_THROW_EXCEPTION_2(function, parameter0, parameter1) \
    AssertThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), std::string{}, (parameter0), (parameter1))

#define ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_0(function, message) \
    AssertNotThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), (message))

#define ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_1(function, parameter, message) \
    AssertNotThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), (message), (parameter))

#define ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_2(function, parameter0, parameter1, message) \
    AssertNotThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), (message), (parameter0), (parameter1))

#define ASSERT_THROW_EXCEPTION_USE_MESSAGE_0(function, message) \
    AssertThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), (message))

#define ASSERT_THROW_EXCEPTION_USE_MESSAGE_1(function, parameter, message) \
    AssertThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), (message), (parameter))

#define ASSERT_THROW_EXCEPTION_USE_MESSAGE_2(function, parameter0, parameter1, message) \
    AssertThrowException(this, &ClassType::function, (CORE_TOOLS_FUNCTION_DESCRIBED), (message), (parameter0), (parameter1))

#define ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(function) \
    AssertNotThrowException<ClassType, decltype(&ClassType::ExecuteLoopTesting<ClassType, decltype(&ClassType::function)>), ClassType*, decltype(&ClassType::function)>(this, &ClassType::ExecuteLoopTesting<ClassType, decltype(&ClassType::function)>, (CORE_TOOLS_FUNCTION_DESCRIBED), std::string{}, this, &ClassType::function)

#define ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION_USE_MESSAGE(function, message) \
    AssertNotThrowException<ClassType, decltype(&ClassType::ExecuteLoopTesting<ClassType, decltype(&ClassType::function)>), ClassType*, decltype(&ClassType::function)>(this, &ClassType::ExecuteLoopTesting<ClassType, decltype(&ClassType::function)>, (CORE_TOOLS_FUNCTION_DESCRIBED), (message), this, &ClassType::function)

#endif  // CORE_TOOLS_HELPER_ASSERT_EXCEPTION_MACRO_H
