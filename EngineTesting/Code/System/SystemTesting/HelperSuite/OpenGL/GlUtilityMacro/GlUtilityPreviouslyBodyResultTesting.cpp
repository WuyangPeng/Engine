///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/18 13:15)

#include "GlUtilityPreviouslyBodyResultTesting.h"
#include "System/Helper/Detail/OpenGL/GLUtilityMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/GlUtilityMacroHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GlUtilityPreviouslyBodyResultTesting::GlUtilityPreviouslyBodyResultTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GlUtilityPreviouslyBodyResultTesting)

void System::GlUtilityPreviouslyBodyResultTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GlUtilityPreviouslyBodyResultTesting::MainTest()
{
    ASSERT_EQUAL(PreviouslyBody0Test(), 0);
    ASSERT_EQUAL(PreviouslyBody1Test(), 1);
    ASSERT_EQUAL(PreviouslyBody2Test(), 1 + 2);
    ASSERT_EQUAL(PreviouslyBody3Test(), 1 + 2 + 3);
    ASSERT_EQUAL(PreviouslyBody4Test(), 1 + 2 + 3 + 4);
    ASSERT_EQUAL(PreviouslyBody5Test(), 1 + 2 + 3 + 4 + 5);
}

int System::GlUtilityPreviouslyBodyResultTesting::PreviouslyBody0Test() noexcept
{
    const auto function = Function0;
    SYSTEM_PREVIOUSLY_BODY_0_RESULT(function, 0);
}

int System::GlUtilityPreviouslyBodyResultTesting::PreviouslyBody1Test() noexcept
{
    const auto function = Function1;
    SYSTEM_PREVIOUSLY_BODY_1_RESULT(function, 1, 0);
}

int System::GlUtilityPreviouslyBodyResultTesting::PreviouslyBody2Test() noexcept
{
    const auto function = Function2;
    SYSTEM_PREVIOUSLY_BODY_2_RESULT(function, 1, 2, 0);
}

int System::GlUtilityPreviouslyBodyResultTesting::PreviouslyBody3Test() noexcept
{
    const auto function = Function3;
    SYSTEM_PREVIOUSLY_BODY_3_RESULT(function, 1, 2, 3, 0);
}

int System::GlUtilityPreviouslyBodyResultTesting::PreviouslyBody4Test() noexcept
{
    const auto function = Function4;
    SYSTEM_PREVIOUSLY_BODY_4_RESULT(function, 1, 2, 3, 4, 0);
}

int System::GlUtilityPreviouslyBodyResultTesting::PreviouslyBody5Test() noexcept
{
    const auto function = Function5;
    SYSTEM_PREVIOUSLY_BODY_5_RESULT(function, 1, 2, 3, 4, 5, 0);
}
