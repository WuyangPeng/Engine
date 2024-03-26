/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:11)

#include "GlUtilityBodyResultTesting.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/GlUtilityMacroHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GlUtilityBodyResultTesting::GlUtilityBodyResultTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GlUtilityBodyResultTesting)

void System::GlUtilityBodyResultTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GlUtilityBodyResultTesting::MainTest()
{
    ASSERT_EQUAL(Body0Test(false), 0);
    ASSERT_EQUAL(Body1Test(false), 1);
    ASSERT_EQUAL(Body2Test(false), 1 + 2);
    ASSERT_EQUAL(Body3Test(false), 1 + 2 + 3);
    ASSERT_EQUAL(Body4Test(false), 1 + 2 + 3 + 4);
    ASSERT_EQUAL(Body5Test(false), 1 + 2 + 3 + 4 + 5);
    ASSERT_EQUAL(Body6Test(false), 1 + 2 + 3 + 4 + 5 + 6);
    ASSERT_EQUAL(Body7Test(false), 1 + 2 + 3 + 4 + 5 + 6 + 7);
    ASSERT_EQUAL(Body8Test(false), 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8);
    ASSERT_EQUAL(Body17Test(false), 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 + 16 + 17);

    ASSERT_EQUAL(Body0Test(true), -1);
    ASSERT_EQUAL(Body1Test(true), -1);
    ASSERT_EQUAL(Body2Test(true), -1);
    ASSERT_EQUAL(Body3Test(true), -1);
    ASSERT_EQUAL(Body4Test(true), -1);
    ASSERT_EQUAL(Body5Test(true), -1);
    ASSERT_EQUAL(Body6Test(true), -1);
    ASSERT_EQUAL(Body7Test(true), -1);
    ASSERT_EQUAL(Body8Test(true), -1);
    ASSERT_EQUAL(Body17Test(true), -1);
}

int System::GlUtilityBodyResultTesting::Body0Test(bool isNull) const noexcept
{
    const auto function = isNull ? nullptr : Function0;
    SYSTEM_BODY_0_RESULT(function, -1);
}

int System::GlUtilityBodyResultTesting::Body1Test(bool isNull) const noexcept
{
    const auto function = isNull ? nullptr : Function1;
    SYSTEM_BODY_1_RESULT(function, 1, -1);
}

int System::GlUtilityBodyResultTesting::Body2Test(bool isNull) const noexcept
{
    const auto function = isNull ? nullptr : Function2;
    SYSTEM_BODY_2_RESULT(function, 1, 2, -1);
}

int System::GlUtilityBodyResultTesting::Body3Test(bool isNull) const noexcept
{
    const auto function = isNull ? nullptr : Function3;
    SYSTEM_BODY_3_RESULT(function, 1, 2, 3, -1);
}

int System::GlUtilityBodyResultTesting::Body4Test(bool isNull) const noexcept
{
    const auto function = isNull ? nullptr : Function4;
    SYSTEM_BODY_4_RESULT(function, 1, 2, 3, 4, -1);
}

int System::GlUtilityBodyResultTesting::Body5Test(bool isNull) const noexcept
{
    const auto function = isNull ? nullptr : Function5;
    SYSTEM_BODY_5_RESULT(function, 1, 2, 3, 4, 5, -1);
}

int System::GlUtilityBodyResultTesting::Body6Test(bool isNull) const noexcept
{
    const auto function = isNull ? nullptr : Function6;
    SYSTEM_BODY_6_RESULT(function, 1, 2, 3, 4, 5, 6, -1);
}

int System::GlUtilityBodyResultTesting::Body7Test(bool isNull) const noexcept
{
    const auto function = isNull ? nullptr : Function7;
    SYSTEM_BODY_7_RESULT(function, 1, 2, 3, 4, 5, 6, 7, -1);
}

int System::GlUtilityBodyResultTesting::Body8Test(bool isNull) const noexcept
{
    const auto function = isNull ? nullptr : Function8;
    SYSTEM_BODY_8_RESULT(function, 1, 2, 3, 4, 5, 6, 7, 8, -1);
}

int System::GlUtilityBodyResultTesting::Body17Test(bool isNull) const noexcept
{
    const auto function = isNull ? nullptr : Function17;
    SYSTEM_BODY_17_RESULT(function, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, -1);
}