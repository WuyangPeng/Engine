///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 15:55)

#include "GaussPointsFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/GaussPointsFit3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class GaussPointsFit3<float>;
    template class GaussPointsFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, GaussPointsFit3Testing)

void Mathematics::GaussPointsFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::GaussPointsFit3Testing::FitTest()
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

        const GaussPointsFit3<double> gaussPointsFit2d(vertices);

        const Box3D box = gaussPointsFit2d.GetBox3();

        for (int i = 0; i < size; ++i)
        {
            const double distanceSquared = Vector3ToolsD::DistanceSquared(box.GetCenter(), vertices.at(i));
            const double maxDistanceSquared = box.GetExtent0() * box.GetExtent0() + box.GetExtent1() * box.GetExtent1() + box.GetExtent2() * box.GetExtent2();

            ASSERT_TRUE(distanceSquared <= maxDistanceSquared);
        }
    }
}
