///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:17)

#include "HeightLineFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/HeightLineFit2Detail.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

#include <random>

namespace Mathematics
{
    template class HeightLineFit2<float>;
    template class HeightLineFit2<double>;
}

Mathematics::HeightLineFit2Testing::HeightLineFit2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, HeightLineFit2Testing)

void Mathematics::HeightLineFit2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::HeightLineFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::HeightLineFit2Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(10, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
        }

        const HeightLineFit2D heightLineFit2(vertices);

        if (heightLineFit2.IsFit2Success())
        {
            double sumX = 0.0;
            double sumY = 0.0;
            double sumXX = 0.0;
            double sumXY = 0.0;

            for (const auto& vertice : vertices)
            {
                sumX += vertice.GetX();
                sumY += vertice.GetY();
                sumXX += vertice.GetX() * vertice.GetX();
                sumXY += vertice.GetX() * vertice.GetY();
            }
        }
    }
}
