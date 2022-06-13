///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 19:25)

#include "Ellipse2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Ellipse2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Ellipse2<float>;
    template class Ellipse2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Ellipse2Testing)

void Mathematics::Ellipse2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::Ellipse2Testing::ConstructionTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };
    const uniform_real<double> secondRandomDistribution(1.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 center(firstRandomDistribution(generator), firstRandomDistribution(generator));

        Vector2 axis0(firstRandomDistribution(generator), firstRandomDistribution(generator));

        axis0.Normalize();

        Vector2 axis1(firstRandomDistribution(generator), firstRandomDistribution(generator));

        axis1.Normalize();

        double extent0(MathD::FAbs(secondRandomDistribution(generator)));
        double extent1(MathD::FAbs(secondRandomDistribution(generator)));

        const Ellipse2D firstEllipse2(center, axis0, axis1, extent0, extent1);

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstEllipse2.GetCenter(), center));

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstEllipse2.GetAxis0(), axis0));
        ASSERT_TRUE(Vector2ToolsD::Approximate(firstEllipse2.GetAxis1(), axis1));
        ASSERT_APPROXIMATE(firstEllipse2.GetExtent0(), extent0, 1e-10);
        ASSERT_APPROXIMATE(firstEllipse2.GetExtent1(), extent1, 1e-10);

        const auto matrix = firstEllipse2.GetMatrix();

        if (MathD::FAbs(matrix.Determinant()) <= 1e-8)
            continue;

        auto firstEllipse2Coefficients = firstEllipse2.ToCoefficients();

        Ellipse2D secondEllipse2(firstEllipse2Coefficients);

        center = secondEllipse2.GetCenter();
        axis0 = secondEllipse2.GetAxis0();
        axis1 = secondEllipse2.GetAxis1();
        extent0 = secondEllipse2.GetExtent0();
        extent1 = secondEllipse2.GetExtent1();

        const Ellipse2D thirdEllipse2(center, axis0, axis1, extent0, extent1);

        ASSERT_TRUE(Approximate(secondEllipse2.ToCoefficients(), thirdEllipse2.ToCoefficients(), 1e-10));

        secondEllipse2.FromCoefficients(thirdEllipse2.ToCoefficients());

        ASSERT_TRUE(Vector2ToolsD::Approximate(secondEllipse2.GetCenter(), thirdEllipse2.GetCenter()));

        ASSERT_TRUE(Vector2ToolsD::Approximate(secondEllipse2.GetAxis0(), thirdEllipse2.GetAxis0()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(secondEllipse2.GetAxis1(), thirdEllipse2.GetAxis1()));
        ASSERT_APPROXIMATE(secondEllipse2.GetExtent0(), thirdEllipse2.GetExtent0(), 1e-4f);
        ASSERT_APPROXIMATE(secondEllipse2.GetExtent1(), thirdEllipse2.GetExtent1(), 1e-7f);
    }
}

void Mathematics::Ellipse2Testing::CalculateTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };
    const uniform_real<double> secondRandomDistribution(1.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 center(firstRandomDistribution(generator), firstRandomDistribution(generator));

        Vector2 axis0(firstRandomDistribution(generator), firstRandomDistribution(generator));

        axis0.Normalize();

        Vector2 axis1(firstRandomDistribution(generator), firstRandomDistribution(generator));

        axis1.Normalize();

        const double extent0(MathD::FAbs(secondRandomDistribution(generator)));
        const double extent1(MathD::FAbs(secondRandomDistribution(generator)));

        Ellipse2D firstEllipse2(center, axis0, axis1, extent0, extent1);

        const auto matrix = firstEllipse2.GetMatrix();

        if (MathD::FAbs(matrix.Determinant()) <= 1e-8)
            continue;

        auto firstEllipse2Coefficients = firstEllipse2.ToCoefficients();

        const Ellipse2D secondEllipse2(firstEllipse2Coefficients);

        firstEllipse2.FromCoefficients(secondEllipse2.ToCoefficients());

        // 测试firstEllipse2和secondEllipse2计算相等性
        auto firstMatrix = firstEllipse2.GetMatrix();
        auto secondMatrix = secondEllipse2.GetMatrix();
        auto thirdMatrix = Matrix2D(firstEllipse2.GetAxis0() / firstEllipse2.GetExtent0(), firstEllipse2.GetAxis0() / firstEllipse2.GetExtent0()) +
                           Matrix2D(firstEllipse2.GetAxis1() / firstEllipse2.GetExtent1(), firstEllipse2.GetAxis1() / firstEllipse2.GetExtent1());

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-9));
        ASSERT_TRUE(Approximate(firstMatrix, thirdMatrix, 1e-10));

        firstMatrix = firstEllipse2.GetMatrixInverse();
        secondMatrix = secondEllipse2.GetMatrixInverse();
        thirdMatrix = Matrix2D(firstEllipse2.GetAxis0() * firstEllipse2.GetExtent0(), firstEllipse2.GetAxis0() * firstEllipse2.GetExtent0()) +
                      Matrix2D(firstEllipse2.GetAxis1() * firstEllipse2.GetExtent1(), firstEllipse2.GetAxis1() * firstEllipse2.GetExtent1());

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-3));
        ASSERT_TRUE(Approximate(firstMatrix, thirdMatrix, 1e-10));

        const Vector2 point(firstRandomDistribution(generator), firstRandomDistribution(generator));

        auto diff = point - firstEllipse2.GetCenter();
        auto ratio0 = Vector2ToolsD::DotProduct(firstEllipse2.GetAxis0(), diff) / firstEllipse2.GetExtent0();
        auto ratio1 = Vector2ToolsD::DotProduct(firstEllipse2.GetAxis1(), diff) / firstEllipse2.GetExtent1();
        auto evaluate = ratio0 * ratio0 + ratio1 * ratio1 - 1.0;

        ASSERT_APPROXIMATE(firstEllipse2.Evaluate(point), secondEllipse2.Evaluate(point), 1e-5);

        ASSERT_APPROXIMATE(firstEllipse2.Evaluate(point), evaluate, 1e-10);

        ASSERT_EQUAL(firstEllipse2.Contains(point), secondEllipse2.Contains(point));

        ASSERT_EQUAL(firstEllipse2.Contains(point), evaluate <= 1e-10);
    }
}
