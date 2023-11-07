///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:17)

#include "OrthogonalLineFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/OrthogonalLineFit2Detail.h"
#include "Mathematics/NumericalAnalysis/EigenDecomposition.h"

#include <random>

;

namespace Mathematics
{
    template class OrthogonalLineFit2<float>;
    template class OrthogonalLineFit2<double>;
}

Mathematics::OrthogonalLineFit2Testing::OrthogonalLineFit2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OrthogonalLineFit2Testing)

void Mathematics::OrthogonalLineFit2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OrthogonalLineFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::OrthogonalLineFit2Testing::FitTest()
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

        const OrthogonalLineFit2D orthogonalLineFit2(vertices);

        Vector2D origin;
        for (int i = 0; i < size; ++i)
        {
            origin += vertices.at(i);
        }

        origin /= static_cast<double>(size);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, orthogonalLineFit2.GetLine2().GetOrigin(), origin, 1e-10);

        double sumXX = 0.0;
        double sumXY = 0.0;
        double sumYY = 0.0;
        for (int i = 0; i < size; ++i)
        {
            Vector2 diff = vertices.at(i) - origin;
            sumXX += diff[0] * diff[0];
            sumXY += diff[0] * diff[1];
            sumYY += diff[1] * diff[1];
        }

        sumXX /= static_cast<double>(size);
        sumXY /= static_cast<double>(size);
        sumYY /= static_cast<double>(size);

        EigenDecompositionD esystem(2);
        esystem(0, 0) = sumYY;
        esystem(0, 1) = -sumXY;
        esystem(1, 0) = -sumXY;
        esystem(1, 1) = sumXX;

        esystem.Solve(false);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, orthogonalLineFit2.GetLine2().GetDirection(), esystem.GetEigenvector2(1), 1e-10);
    }
}
