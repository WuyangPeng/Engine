///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:18)

#include "PolynomialFit2PowersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit2PowersDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

namespace Mathematics
{
    template class PolynomialFit2Powers<float>;
    template class PolynomialFit2Powers<double>;
}

Mathematics::PolynomialFit2PowersTesting::PolynomialFit2PowersTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolynomialFit2PowersTesting)

void Mathematics::PolynomialFit2PowersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolynomialFit2PowersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit2PowersTesting::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0(0.0, 5.0);
    std::uniform_int_distribution<> randomDistribution1(10, 50);
    std::uniform_int_distribution<> thirdRandomDistribution(3, 5);
    std::uniform_int_distribution<> fourthRandomDistribution(0, 7);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<double> x;
        std::vector<double> w;
        std::vector<int> power;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            x.push_back(randomDistribution0(generator));
            w.push_back(randomDistribution0(generator));
        }

        const int powSize = thirdRandomDistribution(generator);

        for (int i = 0; i < powSize; ++i)
        {
            power.push_back(fourthRandomDistribution(generator));
        }

        PolynomialFit2PowersD polynomialFit(x, w, power);

        if (polynomialFit.IsSolveSucceed())
        {
            for (int i = 0; i < size; ++i)
            {
                const double value = polynomialFit(x.at(i)) - w.at(i);

                ASSERT_LESS_EQUAL(MathD::FAbs(value), 110.0);
            }
        }
    }
}
