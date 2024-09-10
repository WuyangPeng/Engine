///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:18)

#include "PolynomialFit3PowersTesting.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit3PowersDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

namespace Mathematics
{
    template class PolynomialFit3Powers<float>;
    template class PolynomialFit3Powers<double>;
}

Mathematics::PolynomialFit3PowersTesting::PolynomialFit3PowersTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolynomialFit3PowersTesting)

void Mathematics::PolynomialFit3PowersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolynomialFit3PowersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit3PowersTesting::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0(0.0, 2.0);
    std::uniform_int_distribution<> randomDistribution1(3, 7);
    std::uniform_int_distribution<> thirdRandomDistribution(2, 5);
    std::uniform_int_distribution<> fourthRandomDistribution(0, 3);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<double> x;
        std::vector<double> y;
        std::vector<double> w;
        const int xSize = randomDistribution1(generator);
        const int ySize = randomDistribution1(generator);

        for (int i = 0; i < xSize; ++i)
        {
            x.push_back(randomDistribution0(generator));
        }

        for (int i = 0; i < ySize; ++i)
        {
            y.push_back(randomDistribution0(generator));
        }

        for (int i = 0; i < xSize * ySize; ++i)
        {
            w.push_back(randomDistribution0(generator));
        }

        const int powSize = thirdRandomDistribution(generator);
        std::vector<CoreTools::Tuple<2, int>> power;

        for (int i = 0; i < powSize; ++i)
        {
            const CoreTools::Tuple<2, int> tuple(fourthRandomDistribution(generator), fourthRandomDistribution(generator));
            power.push_back(tuple);
        }

        PolynomialFit3PowersD polynomialFit(x, y, w, power, true);

        if (polynomialFit.IsSolveSucceed())
        {
            for (int yIndex = 0; yIndex < ySize; ++yIndex)
            {
                for (int xIndex = 0; xIndex < xSize; ++xIndex)
                {
                }
            }
        }
    }
}
