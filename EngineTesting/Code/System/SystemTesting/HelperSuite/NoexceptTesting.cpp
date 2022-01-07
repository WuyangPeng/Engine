///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/10 11:36)

#include "NoexceptTesting.h"
#include "System/Helper/Noexcept.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::NoexceptTesting::NoexceptTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, NoexceptTesting)

void System::NoexceptTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::NoexceptTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NoexceptTest);
}

void System::NoexceptTesting::NoexceptTest()
{
    NoexceptNoReturn(ClassType::Function0);
    NoexceptNoReturn(ClassType::Function1, 1);
    NoexceptNoReturn(ClassType::Function2, 1, 1);
    NoexceptNoReturn(ClassType::Function3, 1, 1, 1);
    NoexceptNoReturn(ClassType::Function4, 1, 1, 1, 1);

    ASSERT_EQUAL((Noexcept<int>(ClassType::Function5, 0)), 0);
    ASSERT_EQUAL((Noexcept<int>(ClassType::Function6, 1, 0)), 1);
    ASSERT_EQUAL((Noexcept<int>(ClassType::Function7, 1, 1, 0)), 1);
    ASSERT_EQUAL((Noexcept<int>(ClassType::Function8, 1, 1, 1, 0)), 1);
    ASSERT_EQUAL((Noexcept<int>(ClassType::Function9, 1, 1, 1, 1, 0)), 1);
}

void System::NoexceptTesting::Function0()
{
    THROW_WINDOWS_EXCEPTION;
}

void System::NoexceptTesting::Function1(MAYBE_UNUSED int parameter0)
{
    THROW_WINDOWS_EXCEPTION;
}

void System::NoexceptTesting::Function2(MAYBE_UNUSED int parameter0, MAYBE_UNUSED int parameter1)
{
    THROW_WINDOWS_EXCEPTION;
}

void System::NoexceptTesting::Function3(MAYBE_UNUSED int parameter0, MAYBE_UNUSED int parameter1, MAYBE_UNUSED int parameter2)
{
    THROW_WINDOWS_EXCEPTION;
}

void System::NoexceptTesting::Function4(MAYBE_UNUSED int parameter0, MAYBE_UNUSED int parameter1, MAYBE_UNUSED int parameter2, MAYBE_UNUSED int parameter3)
{
    THROW_WINDOWS_EXCEPTION;
}

int System::NoexceptTesting::Function5()
{
    THROW_WINDOWS_EXCEPTION;
}

int System::NoexceptTesting::Function6(MAYBE_UNUSED int parameter0)
{
    THROW_WINDOWS_EXCEPTION;
}

int System::NoexceptTesting::Function7(MAYBE_UNUSED int parameter0, MAYBE_UNUSED int parameter1)
{
    THROW_WINDOWS_EXCEPTION;
}

int System::NoexceptTesting::Function8(MAYBE_UNUSED int parameter0, MAYBE_UNUSED int parameter1, MAYBE_UNUSED int parameter2)
{
    THROW_WINDOWS_EXCEPTION;
}

int System::NoexceptTesting::Function9(MAYBE_UNUSED int parameter0, MAYBE_UNUSED int parameter1, MAYBE_UNUSED int parameter2, MAYBE_UNUSED int parameter3)
{
    THROW_WINDOWS_EXCEPTION;
}
