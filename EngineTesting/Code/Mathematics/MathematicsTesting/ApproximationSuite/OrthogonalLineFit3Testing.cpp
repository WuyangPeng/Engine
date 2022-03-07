// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:13)

#include "OrthogonalLineFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/OrthogonalLineFit3Detail.h"

#include "Mathematics/NumericalAnalysis/EigenDecomposition.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class OrthogonalLineFit3<float>;
    template class OrthogonalLineFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, OrthogonalLineFit3Testing)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::OrthogonalLineFit3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::OrthogonalLineFit3Testing ::FitTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(10, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        OrthogonalLineFit3D orthogonalLineFit2(vertices);

        Vector3D origin;
        for (int i = 0; i < size; ++i)
        {
            origin += vertices[i];
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
            Vector3D diff = vertices[i] - origin;
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
