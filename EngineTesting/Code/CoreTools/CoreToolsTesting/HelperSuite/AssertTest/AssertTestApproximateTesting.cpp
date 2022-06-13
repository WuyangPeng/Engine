///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
///	¡™œµ◊˜’ﬂ£∫94458936@qq.com
///
///	±Í◊º£∫std:c++20
///	“˝«Ê≤‚ ‘∞Ê±æ£∫0.8.0.8 (2022/05/19 11:21)

#include "AssertTestApproximateTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::AssertTestApproximateTesting::AssertTestApproximateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AssertTestApproximateTesting)

void CoreTools::AssertTestApproximateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AssertTestApproximateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AssertApproximateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertApproximateMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssertApproximateFailureThrowTest);
}

void CoreTools::AssertTestApproximateTesting::AssertApproximateTest()
{
    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.0f;

    ASSERT_APPROXIMATE(lhsExpression, lhsExpression, 1e-6f);
    ASSERT_APPROXIMATE_USE_FUNCTION(ClassType::Approximate, lhsExpression, rhsExpression, 1e-6f);
}

void CoreTools::AssertTestApproximateTesting::AssertApproximateMessageTest()
{
    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.0f;

    ASSERT_APPROXIMATE_USE_MESSAGE(lhsExpression, lhsExpression, 1e-6f, "≤‚ ‘");
    ASSERT_APPROXIMATE_USE_FUNCTION_AND_MESSAGE(ClassType::Approximate, lhsExpression, rhsExpression, 1e-6f, "≤‚ ‘");
}

void CoreTools::AssertTestApproximateTesting::AssertApproximateFailureThrowTest()
{
    constexpr auto lhsExpression = 20.0f;
    constexpr auto rhsExpression = 20.0f;

    ASSERT_APPROXIMATE_FAILURE_THROW(lhsExpression, lhsExpression, 1e-6f, "≤‚ ‘");
    ASSERT_APPROXIMATE_USE_FUNCTION_FAILURE_THROW(ClassType::Approximate, lhsExpression, rhsExpression, 1e-6f, "≤‚ ‘");
}

bool CoreTools::AssertTestApproximateTesting::Approximate(float lhs, float rhs, float epsilon) noexcept
{
    return Mathematics::MathF::FAbs(lhs - rhs) <= epsilon;
}