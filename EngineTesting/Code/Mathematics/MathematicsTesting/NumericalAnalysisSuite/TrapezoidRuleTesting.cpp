///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 16:25)

#include "TrapezoidRuleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/TrapezoidRuleDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
namespace Mathematics
{
    template class TrapezoidRule<float, TrapezoidRuleTesting>;
    template class TrapezoidRule<double, TrapezoidRuleTesting>;
}

Mathematics::TrapezoidRuleTesting::TrapezoidRuleTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, TrapezoidRuleTesting)

void Mathematics::TrapezoidRuleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::TrapezoidRuleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
}

double Mathematics::TrapezoidRuleTesting::Solution(double input, const TrapezoidRuleTesting* userData) noexcept
{
    if (userData != nullptr)
        return input * userData->GetUserData() - 3;
    else
        return 0.0;
}

double Mathematics::TrapezoidRuleTesting::GetUserData() const noexcept
{
    return 5;
}

void Mathematics::TrapezoidRuleTesting::ValueTest()
{
    constexpr double end = 3.5;
    constexpr double begin = 1.5;
    constexpr int numSamples = 10;
    constexpr auto temp1 = (end - begin);
    constexpr auto temp2 = (numSamples - 1);
    constexpr double difference = temp1 / static_cast<double>(temp2);
    double value = 0.5 * (Solution(begin, this) + Solution(end, this));

    for (int i = 1; i <= numSamples - 2; ++i)
    {
        value += Solution(begin + i * difference, this);
    }

    value *= difference;

    const TrapezoidRule<double, TrapezoidRuleTesting> trapezoidRule(numSamples, begin, end, Solution, this);

    ASSERT_APPROXIMATE(value, trapezoidRule.GetValue(), 1e-10);
}
