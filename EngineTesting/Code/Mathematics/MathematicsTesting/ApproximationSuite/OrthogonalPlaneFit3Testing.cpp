///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:17)

#include "OrthogonalPlaneFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/OrthogonalPlaneFit3Detail.h"
#include "Mathematics/NumericalAnalysis/EigenDecomposition.h"

#include <random>

namespace Mathematics
{
    template class OrthogonalPlaneFit3<float>;
    template class OrthogonalPlaneFit3<double>;
}

Mathematics::OrthogonalPlaneFit3Testing::OrthogonalPlaneFit3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OrthogonalPlaneFit3Testing)

void Mathematics::OrthogonalPlaneFit3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OrthogonalPlaneFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::OrthogonalPlaneFit3Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(10, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator)));
        }

        const OrthogonalPlaneFit3D orthogonalPlaneFit(vertices);

        Vector3D origin;

        for (int i = 0; i < size; i++)
        {
            origin += vertices.at(i);
        }

        origin /= static_cast<double>(size);

        double sumXX = 0.0;
        double sumXY = 0.0;
        double sumXZ = 0.0;
        double sumYY = 0.0;
        double sumYZ = 0.0;
        double sumZZ = 0.0;

        for (int i = 0; i < size; ++i)
        {
            Vector3D diff = vertices.at(i) - origin;
            sumXX += diff[0] * diff[0];
            sumXY += diff[0] * diff[1];
            sumXZ += diff[0] * diff[2];
            sumYY += diff[1] * diff[1];
            sumYZ += diff[1] * diff[2];
            sumZZ += diff[2] * diff[2];
        }

        sumXX /= static_cast<double>(size);
        sumXY /= static_cast<double>(size);
        sumXZ /= static_cast<double>(size);
        sumYY /= static_cast<double>(size);
        sumYZ /= static_cast<double>(size);
        sumZZ /= static_cast<double>(size);

        EigenDecompositionD esystem(3);
        esystem(0, 0) = sumXX;
        esystem(0, 1) = sumXY;
        esystem(0, 2) = sumXZ;
        esystem(1, 0) = sumXY;
        esystem(1, 1) = sumYY;
        esystem(1, 2) = sumYZ;
        esystem(2, 0) = sumXZ;
        esystem(2, 1) = sumYZ;
        esystem(2, 2) = sumZZ;

        esystem.Solve(false);

        const Vector3D normal = esystem.GetEigenvector3(2);

        const Plane3D plane(normal, origin);

        ASSERT_APPROXIMATE(plane.GetConstant(), orthogonalPlaneFit.GetPlane3().GetConstant(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, plane.GetNormal(), orthogonalPlaneFit.GetPlane3().GetNormal(), 1e-10);
    }
}
