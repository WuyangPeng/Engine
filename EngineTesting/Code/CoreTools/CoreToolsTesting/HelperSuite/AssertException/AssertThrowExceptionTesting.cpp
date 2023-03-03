///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/05 23:36)

#include "AssertThrowExceptionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::AssertThrowExceptionTesting::AssertThrowExceptionTesting(const OStreamShared& stream)
    : ParentType{ stream },
      parameter0{ 1 },
      parameter1{ 2 },
      parameter2{ 3 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertThrowExceptionTesting)

void CoreTools::AssertThrowExceptionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertThrowExceptionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertExceptionMacroTest);
}

void CoreTools::AssertThrowExceptionTesting::AssertExceptionMacroTest()
{
    ASSERT_THROW_EXCEPTION_0(AssertThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_1(AssertThrowExceptionTestWithParameter, parameter0);
    ASSERT_THROW_EXCEPTION_2(AssertThrowExceptionTestWith2Parameter, parameter0, parameter1);
    ASSERT_THROW_EXCEPTION_3(AssertThrowExceptionTestWith3Parameter, parameter0, parameter1, parameter2);

    ASSERT_THROW_EXCEPTION_USE_MESSAGE_0(AssertThrowExceptionTest, "����AssertExceptionMacro");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_1(AssertThrowExceptionTestWithParameter, parameter0, "����AssertExceptionMacro");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_2(AssertThrowExceptionTestWith2Parameter, parameter0, parameter1, "����AssertExceptionMacro");
    ASSERT_THROW_EXCEPTION_USE_MESSAGE_3(AssertThrowExceptionTestWith3Parameter, parameter0, parameter1, parameter2, "����AssertExceptionMacro");
}

void CoreTools::AssertThrowExceptionTesting::AssertThrowExceptionTest()
{
    THROW_EXCEPTION(SYSTEM_TEXT("�����쳣����ȷ�׳���"s))
}

void CoreTools::AssertThrowExceptionTesting::AssertThrowExceptionTestWithParameter(int aParameter)
{
    ASSERT_EQUAL(aParameter, parameter0);

    THROW_EXCEPTION(SYSTEM_TEXT("�����쳣����ȷ�׳���"s))
}

void CoreTools::AssertThrowExceptionTesting::AssertThrowExceptionTestWith2Parameter(int aParameter0, int aParameter1)
{
    ASSERT_EQUAL(aParameter0, parameter0);
    ASSERT_EQUAL(aParameter1, parameter1);

    THROW_EXCEPTION(SYSTEM_TEXT("�����쳣����ȷ�׳���"s))
}

void CoreTools::AssertThrowExceptionTesting::AssertThrowExceptionTestWith3Parameter(int aParameter0, int aParameter1, int aParameter2)
{
    ASSERT_EQUAL(aParameter0, parameter0);
    ASSERT_EQUAL(aParameter1, parameter1);
    ASSERT_EQUAL(aParameter2, parameter2);

    THROW_EXCEPTION(SYSTEM_TEXT("�����쳣����ȷ�׳���"s))
}