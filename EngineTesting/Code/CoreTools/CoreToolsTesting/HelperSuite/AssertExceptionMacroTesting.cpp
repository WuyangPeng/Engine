///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/04 22:15)

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

    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_0(AssertNotThrowExceptionTest, "����AssertExceptionMacro");
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_1(AssertNotThrowExceptionTestWithParameter, parameter0, "����AssertExceptionMacro");
    ASSERT_NOT_THROW_EXCEPTION_USE_MESSAGE_2(AssertNotThrowExceptionTestWithTwoParameter, parameter0, parameter1, "����AssertExceptionMacro");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_0(AssertThrowExceptionTest, "����AssertExceptionMacro");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_1(AssertThrowExceptionTestWithParameter, parameter0, "����AssertExceptionMacro");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_2(AssertThrowExceptionTestWithTwoParameter, parameter0, parameter1, "����AssertExceptionMacro");
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
    THROW_EXCEPTION(SYSTEM_TEXT("�����쳣����ȷ�׳���"s));
}

void CoreTools::AssertExceptionMacroTesting::AssertThrowExceptionTestWithParameter(MAYBE_UNUSED int parameter)
{
    THROW_EXCEPTION(SYSTEM_TEXT("�����쳣����ȷ�׳���"s));
}

void CoreTools::AssertExceptionMacroTesting::AssertThrowExceptionTestWithTwoParameter(MAYBE_UNUSED int parameter0, MAYBE_UNUSED int parameter1)
{
    THROW_EXCEPTION(SYSTEM_TEXT("�����쳣����ȷ�׳���"s));
}
