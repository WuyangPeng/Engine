///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 13:57)

#include "CylinderFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Approximation/CylinderFit3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class CylinderFit3<float>;
    template class CylinderFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, CylinderFit3Testing)

void Mathematics::CylinderFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::CylinderFit3Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(10, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        vector<Vector3D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        const CylinderFit3D fit(vertices);

        const double exactly = fit.GetExactly();

        ASSERT_TRUE(exactly <= 1.0);

        const Vector3D center = fit.GetCenter();
        const Vector3D axis = fit.GetAxis();
        const double radius = fit.GetRadius();
        const double height = fit.GetHeight();

        double maxDistance = MathD::Sqrt(radius * radius + height * height);
        maxDistance = MathD::Sqrt(radius * radius + maxDistance * maxDistance);

        for (int i = 0; i < size; ++i)
        {
            // 计算点到原点的距离
            const double distance = Vector3ToolsD::Distance(vertices.at(i), center);

            ASSERT_TRUE(distance <= maxDistance);
        }
    }
}
