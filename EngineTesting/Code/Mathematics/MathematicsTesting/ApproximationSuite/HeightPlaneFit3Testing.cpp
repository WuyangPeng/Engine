///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:17)

#include "HeightPlaneFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/HeightPlaneFit3Detail.h"

#include <random>

namespace Mathematics
{
    template class HeightPlaneFit3<float>;
    template class HeightPlaneFit3<double>;
}

Mathematics::HeightPlaneFit3Testing::HeightPlaneFit3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, HeightPlaneFit3Testing)

void Mathematics::HeightPlaneFit3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::HeightPlaneFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::HeightPlaneFit3Testing::FitTest()
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
            vertices.emplace_back(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        }

        const HeightPlaneFit3D heightPlaneFit3(vertices);

        double sumX = 0.0;
        double sumY = 0.0;
        double sumZ = 0.0;
        double sumXX = 0.0;
        double sumXY = 0.0;
        double sumXZ = 0.0;
        double sumYY = 0.0;
        double sumYZ = 0.0;

        for (int i = 0; i < size; ++i)
        {
            sumX += vertices.at(i)[0];
            sumY += vertices.at(i)[1];
            sumZ += vertices.at(i)[2];
            sumXX += vertices.at(i)[0] * vertices.at(i)[0];
            sumXY += vertices.at(i)[0] * vertices.at(i)[1];
            sumXZ += vertices.at(i)[0] * vertices.at(i)[2];
            sumYY += vertices.at(i)[1] * vertices.at(i)[1];
            sumYZ += vertices.at(i)[1] * vertices.at(i)[2];
        }
    }
}
