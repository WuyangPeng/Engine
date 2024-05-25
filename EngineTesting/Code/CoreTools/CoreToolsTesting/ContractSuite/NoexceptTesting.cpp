/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/26 13:06)

#include "NoexceptTesting.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Contract/NoexceptLog.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(NoexceptTest);
}

void CoreTools::NoexceptTesting::DisableNoexceptTest()
{
    DisableNoexcept();
}

void CoreTools::NoexceptTesting::NoexceptTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NoexceptNoConstTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoexceptConstTest);
}

void CoreTools::NoexceptTesting::NoexceptNoConstTest()
{
    NoexceptNoReturn(*this, &ClassType::Function0);
    NoexceptNoReturn(*this, &ClassType::Function1, 0);
    ASSERT_EQUAL(Noexcept<int>(*this, &ClassType::Function2, 0), 0);
    ASSERT_EQUAL((Noexcept<int>(*this, &ClassType::Function3, 2, 1)), 2);
}

void CoreTools::NoexceptTesting::NoexceptConstTest()
{
    NoexceptNoReturn(*this, &ClassType::ConstFunction0);
    NoexceptNoReturn(*this, &ClassType::ConstFunction1, 0);
    ASSERT_EQUAL(Noexcept<int>(*this, &ClassType::ConstFunction2, 0), 0);
    ASSERT_EQUAL((Noexcept<int>(*this, &ClassType::ConstFunction3, 3, 1)), 3);
}

void CoreTools::NoexceptTesting::Function0()
{
    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s));
}

void CoreTools::NoexceptTesting::Function1(int parameter)
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

int CoreTools::NoexceptTesting::Function2()
{
    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

int CoreTools::NoexceptTesting::Function3(int parameter)
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

void CoreTools::NoexceptTesting::ConstFunction0() const
{
    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

void CoreTools::NoexceptTesting::ConstFunction1(int parameter) const
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

int CoreTools::NoexceptTesting::ConstFunction2() const
{
    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}

int CoreTools::NoexceptTesting::ConstFunction3(int parameter) const
{
    System::UnusedFunction(parameter);

    THROW_EXCEPTION(SYSTEM_TEXT("正确的抛出异常。"s))
}
