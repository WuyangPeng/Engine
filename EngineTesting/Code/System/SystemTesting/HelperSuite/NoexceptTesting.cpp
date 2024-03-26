/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 11:06)

#include "NoexceptTesting.h"
#include "System/Helper/Noexcept.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::NoexceptTesting::NoexceptTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    NoexceptNoReturn(Function0);
    NoexceptNoReturn(Function1, 1);
    NoexceptNoReturn(Function2, 1, 1);
    NoexceptNoReturn(Function3, 1, 1, 1);
    NoexceptNoReturn(Function4, 1, 1, 1, 1);

    ASSERT_EQUAL((Noexcept<int>(ClassType::Function5, 0)), 0);
    ASSERT_EQUAL((Noexcept<int>(ClassType::Function6, 1, 0)), 1);
    ASSERT_EQUAL((Noexcept<int>(ClassType::Function7, 2, 1, 0)), 2);
    ASSERT_EQUAL((Noexcept<int>(ClassType::Function8, 3, 1, 1, 0)), 3);
    ASSERT_EQUAL((Noexcept<int>(ClassType::Function9, 4, 1, 1, 1, 0)), 4);
}

void System::NoexceptTesting::Function0()
{
    THROW_WINDOWS_EXCEPTION
}

void System::NoexceptTesting::Function1(int parameter0)
{
    UnusedFunction(parameter0);

    THROW_WINDOWS_EXCEPTION
}

void System::NoexceptTesting::Function2(int parameter0, int parameter1)
{
    UnusedFunction(parameter0, parameter1);

    THROW_WINDOWS_EXCEPTION
}

void System::NoexceptTesting::Function3(int parameter0, int parameter1, int parameter2)
{
    UnusedFunction(parameter0, parameter1, parameter2);

    THROW_WINDOWS_EXCEPTION
}

void System::NoexceptTesting::Function4(int parameter0, int parameter1, int parameter2, int parameter3)
{
    UnusedFunction(parameter0, parameter1, parameter2, parameter3);

    THROW_WINDOWS_EXCEPTION
}

int System::NoexceptTesting::Function5()
{
    THROW_WINDOWS_EXCEPTION
}

int System::NoexceptTesting::Function6(int parameter0)
{
    UnusedFunction(parameter0);

    THROW_WINDOWS_EXCEPTION
}

int System::NoexceptTesting::Function7(int parameter0, int parameter1)
{
    UnusedFunction(parameter0, parameter1);

    THROW_WINDOWS_EXCEPTION
}

int System::NoexceptTesting::Function8(int parameter0, int parameter1, int parameter2)
{
    UnusedFunction(parameter0, parameter1, parameter2);

    THROW_WINDOWS_EXCEPTION
}

int System::NoexceptTesting::Function9(int parameter0, int parameter1, int parameter2, int parameter3)
{
    UnusedFunction(parameter0, parameter1, parameter2, parameter3);

    THROW_WINDOWS_EXCEPTION
}
