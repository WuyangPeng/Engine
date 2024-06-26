/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:13)

#include "GlUtilityPreviouslyBodyTesting.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/GlUtilityMacroHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GlUtilityPreviouslyBodyTesting::GlUtilityPreviouslyBodyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GlUtilityPreviouslyBodyTesting)

void System::GlUtilityPreviouslyBodyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GlUtilityPreviouslyBodyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody5Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody6Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody7Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody8Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody9Test);
    ASSERT_NOT_THROW_EXCEPTION_0(PreviouslyBody10Test);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody0Test() const noexcept
{
    const auto function = Function0;
    SYSTEM_PREVIOUSLY_BODY_0(function);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody1Test() const noexcept
{
    const auto function = Function1;
    SYSTEM_PREVIOUSLY_BODY_1(function, 1);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody2Test() const noexcept
{
    const auto function = Function2;
    SYSTEM_PREVIOUSLY_BODY_2(function, 1, 2);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody3Test() const noexcept
{
    const auto function = Function3;
    SYSTEM_PREVIOUSLY_BODY_3(function, 1, 2, 3);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody4Test() const noexcept
{
    const auto function = Function4;
    SYSTEM_PREVIOUSLY_BODY_4(function, 1, 2, 3, 4);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody5Test() const noexcept
{
    const auto function = Function5;
    SYSTEM_PREVIOUSLY_BODY_5(function, 1, 2, 3, 4, 5);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody6Test() const noexcept
{
    const auto function = Function6;
    SYSTEM_PREVIOUSLY_BODY_6(function, 1, 2, 3, 4, 5, 6);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody7Test() const noexcept
{
    const auto function = Function7;
    SYSTEM_PREVIOUSLY_BODY_7(function, 1, 2, 3, 4, 5, 6, 7);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody8Test() const noexcept
{
    const auto function = Function8;
    SYSTEM_PREVIOUSLY_BODY_8(function, 1, 2, 3, 4, 5, 6, 7, 8);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody9Test() const noexcept
{
    const auto function = Function9;
    SYSTEM_PREVIOUSLY_BODY_9(function, 1, 2, 3, 4, 5, 6, 7, 8, 9);
}

void System::GlUtilityPreviouslyBodyTesting::PreviouslyBody10Test() const noexcept
{
    const auto function = Function10;
    SYSTEM_PREVIOUSLY_BODY_10(function, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
}