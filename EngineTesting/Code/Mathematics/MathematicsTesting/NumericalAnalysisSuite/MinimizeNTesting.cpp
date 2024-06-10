///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:04)

#include "MinimizeNTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/Minimize1Detail.h"
#include "Mathematics/NumericalAnalysis/MinimizeNDetail.h"

#include <random>

namespace Mathematics
{
    template class MinimizeN<float, MinimizeNTesting>;
    template class MinimizeN<double, MinimizeNTesting>;
}

Mathematics::MinimizeNTesting::MinimizeNTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, MinimizeNTesting)

void Mathematics::MinimizeNTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::MinimizeNTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetMinimumTest);
}

void Mathematics::MinimizeNTesting::GetMinimumTest()
{
    const MinimizeN<double, MinimizeNTesting> minimizeN(5, Function, 10, 10, 10, this);

    std::vector<double> begin{ -10.0, -20.0, -30.0, -40.0, -70.0 };

    std::vector<double> end{ 10.0, 20.0, 30.0, 40.0, 70.0 };

    std::vector<double> initial{ 0.0, 0.0, 0.0, 0.0, 0.0 };

    MinimizeNDataD result = minimizeN.GetMinimum(begin, end, initial);

    ASSERT_APPROXIMATE(result.GetMinValue(), Function(result.GetMinLocation(), this), 1e-10);

    std::default_random_engine generator{ GetEngineRandomSeed() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<double> value;

        for (auto beginIndex = 0u; beginIndex < begin.size(); ++beginIndex)
        {
            std::uniform_int_distribution<> integerRandomDistribution(static_cast<int>(begin.at(beginIndex)), static_cast<int>(end.at(beginIndex)));

            value.push_back(integerRandomDistribution(generator));
        }

        ASSERT_TRUE(result.GetMinValue() <= Function(value, this));
    }
}

double Mathematics::MinimizeNTesting::Function(const std::vector<double>& value, const MinimizeNTesting* minimize1Testing) noexcept
{
    double result = 0.0;

    if (minimize1Testing != nullptr)
    {
        for (auto iter = value.begin(); iter != value.end(); ++iter)
        {
            result += (*iter) * (*iter) * minimize1Testing->GetValue() + (*iter) * 5.0 + 3.0;
        }
    }

    return result;
}

double Mathematics::MinimizeNTesting::GetValue() const noexcept
{
    return 1.0;
}
