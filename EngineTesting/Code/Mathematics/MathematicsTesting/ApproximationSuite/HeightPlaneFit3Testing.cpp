///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 16:23)

#include "HeightPlaneFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/HeightPlaneFit3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class HeightPlaneFit3<float>;
    template class HeightPlaneFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, HeightPlaneFit3Testing)

void Mathematics::HeightPlaneFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::HeightPlaneFit3Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(10, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.emplace_back(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
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
