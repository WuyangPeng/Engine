///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:18)

#include "PolynomialFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit2Detail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

namespace Mathematics
{
    template class PolynomialFit2<float>;
    template class PolynomialFit2<double>;
}

Mathematics::PolynomialFit2Testing::PolynomialFit2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolynomialFit2Testing)

void Mathematics::PolynomialFit2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolynomialFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit2Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-50.0, 50.0);
    const std::uniform_int<> randomDistribution1(10, 50);
    const std::uniform_int<> thirdRandomDistribution(3, 10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<double> x;
        std::vector<double> w;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            x.push_back(randomDistribution0(generator));
            w.push_back(randomDistribution0(generator));
        }

        PolynomialFit2D polynomialFit2(x, w, thirdRandomDistribution(generator));

        if (polynomialFit2.IsSolveSucceed())
        {
            PolynomialD polynomial = polynomialFit2.GetCoeff();

            for (int i = 0; i < size; ++i)
            {
                const double value = polynomial(x.at(i)) - w.at(i);

                ASSERT_LESS_EQUAL(MathD::FAbs(value), 75.0);
            }
        }
    }
}
