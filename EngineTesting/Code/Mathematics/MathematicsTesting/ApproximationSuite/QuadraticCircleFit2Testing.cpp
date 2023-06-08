///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 16:54)

#include "QuadraticCircleFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/QuadraticCircleFit2Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class QuadraticCircleFit2<float>;
    template class QuadraticCircleFit2<double>;
}

Mathematics::QuadraticCircleFit2Testing::QuadraticCircleFit2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, QuadraticCircleFit2Testing)

void Mathematics::QuadraticCircleFit2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::QuadraticCircleFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::QuadraticCircleFit2Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(3, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
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
