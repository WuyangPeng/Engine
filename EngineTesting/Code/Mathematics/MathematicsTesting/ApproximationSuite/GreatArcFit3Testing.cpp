///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 16:03)

#include "GreatArcFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/GreatArcFit3Detail.h"
#include "Mathematics/Approximation/GreatCircleFit3.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class GreatArcFit3<float>;
    template class GreatArcFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, GreatArcFit3Testing)

void Mathematics::GreatArcFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::GreatArcFit3Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(0.0, 100.0);
    const uniform_int<> secondRandomDistribution(5, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        const GreatArcFit3D greatArcFit(vertices);

        GreatCircleFit3D greatCircleFit(vertices);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, greatArcFit.GetNormal(), greatCircleFit.GetNormal(), 1e-10);

        const Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateComplementBasis(greatCircleFit.GetNormal());
    }
}
