///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:15)

#include "GreatCircleFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/GreatCircleFit3Detail.h"
#include "Mathematics/NumericalAnalysis/EigenDecomposition.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

namespace Mathematics
{
    template class GreatCircleFit3<float>;
    template class GreatCircleFit3<double>;
}

Mathematics::GreatCircleFit3Testing::GreatCircleFit3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, GreatCircleFit3Testing)

void Mathematics::GreatCircleFit3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::GreatCircleFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::GreatCircleFit3Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(0.0, 100.0);
    std::uniform_int<> randomDistribution1(5, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.emplace_back(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        }

        double sumXX = 0.0;
        double sumXY = 0.0;
        double sumXZ = 0.0;
        double sumYY = 0.0;
        double sumYZ = 0.0;
        double sumZZ = 0.0;

        for (int i = 0; i < size; ++i)
        {
            Vector3D diff = vertices.at(i);

            sumXX += diff[0] * diff[0];
            sumXY += diff[0] * diff[1];
            sumXZ += diff[0] * diff[2];
            sumYY += diff[1] * diff[1];
            sumYZ += diff[1] * diff[2];
            sumZZ += diff[2] * diff[2];
        }

        sumXX /= size;
        sumXY /= size;
        sumXZ /= size;
        sumYY /= size;
        sumYZ /= size;
        sumZZ /= size;

        EigenDecompositionD eigenSystem(3);
        eigenSystem(0, 0) = sumXX;
        eigenSystem(0, 1) = sumXY;
        eigenSystem(0, 2) = sumXZ;
        eigenSystem(1, 0) = eigenSystem(0, 1);
        eigenSystem(1, 1) = sumYY;
        eigenSystem(1, 2) = sumYZ;
        eigenSystem(2, 0) = eigenSystem(0, 2);
        eigenSystem(2, 1) = eigenSystem(1, 2);
        eigenSystem(2, 2) = sumZZ;

        eigenSystem.Solve(false);

        GreatCircleFit3D greatCircleFit3(vertices);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, eigenSystem.GetEigenvector3(2), greatCircleFit3.GetNormal(), 1e-10);
    }
}
