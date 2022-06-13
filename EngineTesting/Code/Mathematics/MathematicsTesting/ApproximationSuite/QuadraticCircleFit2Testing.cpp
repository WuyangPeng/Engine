///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 16:54)

#include "QuadraticCircleFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/QuadraticCircleFit2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class QuadraticCircleFit2<float>;
    template class QuadraticCircleFit2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QuadraticCircleFit2Testing)

void Mathematics::QuadraticCircleFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::QuadraticCircleFit2Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(3, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        const QuadraticCircleFit2D quadraticCircleFit2(vertices);

        const Vector2 center = quadraticCircleFit2.GetCenter();
        const double radius = quadraticCircleFit2.GetRadius();
        const double eigenValue = quadraticCircleFit2.GetEigenValue();

        ASSERT_TRUE(0.0 <= eigenValue && eigenValue <= 1.0);
        ASSERT_TRUE(0.0 <= radius);

        for (int i = 0; i < size; ++i)
        {
            const double distance = Vector2ToolsD::Distance(vertices.at(i), center);

            if (eigenValue <= MathD::GetZeroTolerance())
            {
                ASSERT_TRUE(distance <= radius + MathD::GetZeroTolerance());
            }
            else if (eigenValue <= 0.5)
            {
                ASSERT_TRUE(distance <= radius * 1.5);
            }
            else if (eigenValue <= 1.0)
            {
                ASSERT_TRUE(distance <= radius * 2.0);
            }
        }
    }
}
