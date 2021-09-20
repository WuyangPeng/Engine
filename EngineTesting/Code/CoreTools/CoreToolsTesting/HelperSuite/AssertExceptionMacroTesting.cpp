///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/04 22:15)

#include "AssertExceptionMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;

CoreTools::AssertExceptionMacroTesting::AssertExceptionMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertExceptionMacroTesting)

void CoreTools::AssertExceptionMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertExceptionMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertExceptionMacroTest);
}

void CoreTools::AssertExceptionMacroTesting::AssertExceptionMacroTest()
{
    constexpr auto parameter0 = 0;
    constexpr auto parameter1 = 0;

    ASSERT_NOT_THROW_EXCEPTION_0(AssertNotThrowExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_1(AssertNotThrowExceptionTestWithParameter, parameter0);
    ASSERT_NOT_THROW_EXCEPTION_2(AssertNotThrowExceptionTestWithTwoParameter, parameter0, parameter1);
    ASSERT_THROW_EXCEPTION_0(AssertThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_1(AssertThrowExceptionTestWithParameter, parameter0);
    ASSERT_THROW_EXCEPTION_2(AssertThrowExceptionTestWithTwoParameter, parameter0, parameter1);

    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_0(AssertNotThrowExceptionTest, "测试AssertExceptionMacro");
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_1(AssertNotThrowExceptionTestWithParameter, parameter0, "测试AssertExceptionMacro");
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_2(AssertNotThrowExceptionTestWithTwoParameter, parameter0, parameter1, "测试AssertExceptionMacro");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_0(AssertThrowExceptionTest, "测试AssertExceptionMacro");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_1(AssertThrowExceptionTestWithParameter, parameter0, "测试AssertExceptionMacro");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_2(AssertThrowExceptionTestWithTwoParameter, parameter0, parameter1, "测试AssertExceptionMacro");
}

void CoreTools::AssertExceptionMacroTesting::AssertNotThrowExceptionTest() noexcept
{
}

void CoreTools::AssertExceptionMacroTesting::AssertNotThrowExceptionTestWithParameter(MAYBE_UNUSED int parameter) noexcept
{
}

void CoreTools::AssertExceptionMacroTesting::AssertNotThrowExceptionTestWithTwoParameter(MAYBE_UNUSED int parameter0, MAYBE_UNUSED int parameter1) noexcept
{
}

void CoreTools::AssertExceptionMacroTesting::AssertThrowExceptionTest()
{
    THROW_EXCEPTION(SYSTEM_TEXT("测试异常被正确抛出！"s));
}

void CoreTools::AssertExceptionMacroTesting::AssertThrowExceptionTestWithParameter(MAYBE_UNUSED int parameter)
{
    THROW_EXCEPTION(SYSTEM_TEXT("测试异常被正确抛出！"s));
}

void CoreTools::AssertExceptionMacroTesting::AssertThrowExceptionTestWithTwoParameter(MAYBE_UNUSED int parameter0, MAYBE_UNUSED int parameter1)
{
    THROW_EXCEPTION(SYSTEM_TEXT("测试异常被正确抛出！"s));
}
