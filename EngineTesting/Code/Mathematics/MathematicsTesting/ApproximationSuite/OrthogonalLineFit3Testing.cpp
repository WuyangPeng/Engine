///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 16:28)

#include "OrthogonalLineFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/OrthogonalLineFit3Detail.h"
#include "Mathematics/NumericalAnalysis/EigenDecomposition.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class OrthogonalLineFit3<float>;
    template class OrthogonalLineFit3<double>;
}

Mathematics::OrthogonalLineFit3Testing::OrthogonalLineFit3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, OrthogonalLineFit3Testing)

void Mathematics::OrthogonalLineFit3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::OrthogonalLineFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::OrthogonalLineFit3Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(10, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        const OrthogonalLineFit3D orthogonalLineFit2(vertices);

        Vector3D origin;
        for (int i = 0; i < size; ++i)
        {
            origin += vertices.at(i);
        }

        origin /= static_cast<double>(size);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, orthogonalLineFit2.GetLine3().GetOrigin(), origin, 1e-10);

        double sumXX = 0.0;
        double sumXY = 0.0;
        double sumYY = 0.0;
        double sumXZ = 0.0;
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
        sumYY /= static_cast<double>(size);
        sumXZ /= static_cast<double>(size);
        sumYZ /= static_cast<double>(size);
        sumZZ /= static_cast<double>(size);

        EigenDecompositionD esystem(3);
        esystem(0, 0) = sumYY + sumZZ;
        esystem(0, 1) = -sumXY;
        esystem(0, 2) = -sumXZ;
        esystem(1, 0) = esystem(0, 1);
        esystem(1, 1) = sumXX + sumZZ;
        esystem(1, 2) = -sumYZ;
        esystem(2, 0) = esystem(0, 2);
        esystem(2, 1) = esystem(1, 2);
        esystem(2, 2) = sumXX + sumYY;

        esystem.Solve(false);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, orthogonalLineFit2.GetLine3().GetDirection(), esystem.GetEigenvector3(2), 1e-10);
    }
}
