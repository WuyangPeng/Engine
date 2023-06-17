///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:15)

#include "GaussPointsFit3Testing.h"
#include "GreatArcFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/GreatArcFit3Detail.h"
#include "Mathematics/Approximation/GreatCircleFit3.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

namespace Mathematics
{
    template class GreatArcFit3<float>;
    template class GreatArcFit3<double>;
}

Mathematics::GreatArcFit3Testing::GreatArcFit3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, GreatArcFit3Testing)

void Mathematics::GreatArcFit3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::GreatArcFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::GreatArcFit3Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(0.0, 100.0);
    const std::uniform_int<> randomDistribution1(5, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator)));
        }

        const GreatArcFit3D greatArcFit(vertices);

        GreatCircleFit3D greatCircleFit(vertices);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, greatArcFit.GetNormal(), greatCircleFit.GetNormal(), 1e-10);

        const Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateComplementBasis(greatCircleFit.GetNormal());
    }
}
