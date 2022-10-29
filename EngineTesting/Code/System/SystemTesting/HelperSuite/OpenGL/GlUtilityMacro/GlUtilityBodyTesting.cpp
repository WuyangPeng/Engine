///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/03 11:47)

#include "GlUtilityBodyTesting.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/GlUtilityMacroHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GlUtilityBodyTesting::GlUtilityBodyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GlUtilityBodyTesting)

void System::GlUtilityBodyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GlUtilityBodyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Body0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body5Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body6Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body7Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body8Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body9Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body10Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body11Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body12Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Body15Test);
}

void System::GlUtilityBodyTesting::Body0Test() noexcept
{
    auto function = Function0;
    SYSTEM_BODY_0(function);
}

void System::GlUtilityBodyTesting::Body1Test() noexcept
{
    auto function = Function1;
    SYSTEM_BODY_1(function, 1);
}

void System::GlUtilityBodyTesting::Body2Test() noexcept
{
    auto function = Function2;
    SYSTEM_BODY_2(function, 1, 2);
}

void System::GlUtilityBodyTesting::Body3Test() noexcept
{
    auto function = Function3;
    SYSTEM_BODY_3(function, 1, 2, 3);
}

void System::GlUtilityBodyTesting::Body4Test() noexcept
{
    auto function = Function4;
    SYSTEM_BODY_4(function, 1, 2, 3, 4);
}

void System::GlUtilityBodyTesting::Body5Test() noexcept
{
    auto function = Function5;
    SYSTEM_BODY_5(function, 1, 2, 3, 4, 5);
}

void System::GlUtilityBodyTesting::Body6Test() noexcept
{
    auto function = Function6;
    SYSTEM_BODY_6(function, 1, 2, 3, 4, 5, 6);
}

void System::GlUtilityBodyTesting::Body7Test() noexcept
{
    auto function = Function7;
    SYSTEM_BODY_7(function, 1, 2, 3, 4, 5, 6, 7);
}

void System::GlUtilityBodyTesting::Body8Test() noexcept
{
    auto function = Function8;
    SYSTEM_BODY_8(function, 1, 2, 3, 4, 5, 6, 7, 8);
}

void System::GlUtilityBodyTesting::Body9Test() noexcept
{
    auto function = Function9;
    SYSTEM_BODY_9(function, 1, 2, 3, 4, 5, 6, 7, 8, 9);
}

void System::GlUtilityBodyTesting::Body10Test() noexcept
{
    auto function = Function10;
    SYSTEM_BODY_10(function, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}

void System::GlUtilityBodyTesting::Body11Test() noexcept
{
    auto function = Function11;
    SYSTEM_BODY_11(function, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
}

void System::GlUtilityBodyTesting::Body12Test() noexcept
{
    auto function = Function12;
    SYSTEM_BODY_12(function, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
}

void System::GlUtilityBodyTesting::Body15Test() noexcept
{
    auto function = Function15;
    SYSTEM_BODY_15(function, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
}
