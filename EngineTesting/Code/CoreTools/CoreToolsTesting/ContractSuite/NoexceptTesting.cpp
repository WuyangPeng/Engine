///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/26 13:06)

#include "NoexceptTesting.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::NoexceptTesting::NoexceptTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NoexceptTesting)

void CoreTools::NoexceptTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::NoexceptTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DisableNoexceptTest);
}

void CoreTools::NoexceptTesting::DisableNoexceptTest()
{
    DisableNoexcept();
}

void CoreTools::NoexceptTesting::NoexceptTest()
{
    NoexceptNoReturn(*this, &ClassType::Function0);
    NoexceptNoReturn(*this, &ClassType::Function1, 0);
    ASSERT_EQUAL(Noexcept<int>(*this, &ClassType::Function2, 0), 0);
    ASSERT_EQUAL((Noexcept<int>(*this, &ClassType::Function3, 0, 1)), 1);

    NoexceptNoReturn(*this, &ClassType::ConstFunction0);
    NoexceptNoReturn(*this, &ClassType::ConstFunction1, 0);
    ASSERT_EQUAL(Noexcept<int>(*this, &ClassType::ConstFunction2, 0), 0);
    ASSERT_EQUAL((Noexcept<int>(*this, &ClassType::ConstFunction3, 0, 1)), 1);
}

void CoreTools::NoexceptTesting::Function0()
{
    THROW_EXCEPTION(SYSTEM_TEXT("��ȷ���׳��쳣��"s));
}

void CoreTools::NoexceptTesting::Function1(MAYBE_UNUSED int parameter)
{
    THROW_EXCEPTION(SYSTEM_TEXT("��ȷ���׳��쳣��"s));
}

int CoreTools::NoexceptTesting::Function2()
{
    THROW_EXCEPTION(SYSTEM_TEXT("��ȷ���׳��쳣��"s));
}

int CoreTools::NoexceptTesting::Function3(MAYBE_UNUSED int parameter)
{
    THROW_EXCEPTION(SYSTEM_TEXT("��ȷ���׳��쳣��"s));
}

void CoreTools::NoexceptTesting::ConstFunction0() const
{
    THROW_EXCEPTION(SYSTEM_TEXT("��ȷ���׳��쳣��"s));
}

void CoreTools::NoexceptTesting::ConstFunction1(MAYBE_UNUSED int parameter) const
{
    THROW_EXCEPTION(SYSTEM_TEXT("��ȷ���׳��쳣��"s));
}

int CoreTools::NoexceptTesting::ConstFunction2() const
{
    THROW_EXCEPTION(SYSTEM_TEXT("��ȷ���׳��쳣��"s));
}

int CoreTools::NoexceptTesting::ConstFunction3(MAYBE_UNUSED int parameter) const
{
    THROW_EXCEPTION(SYSTEM_TEXT("��ȷ���׳��쳣��"s));
}