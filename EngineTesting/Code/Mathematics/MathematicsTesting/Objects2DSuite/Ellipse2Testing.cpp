///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:12)

#include "Ellipse2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Ellipse2Detail.h"

#include <random>

namespace Mathematics
{
    template class Ellipse2<float>;
    template class Ellipse2<double>;
}

Mathematics::Ellipse2Testing::Ellipse2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Ellipse2Testing)

void Mathematics::Ellipse2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Ellipse2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::Ellipse2Testing::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0{ -100.0, 100.0 };
    std::uniform_real<double> randomDistribution1(1.0, 10.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector2 center(randomDistribution0(generator), randomDistribution0(generator));

        Vector2 axis0(randomDistribution0(generator), randomDistribution0(generator));

        axis0.Normalize();

        Vector2 axis1(randomDistribution0(generator), randomDistribution0(generator));

        axis1.Normalize();

        double extent0(MathD::FAbs(randomDistribution1(generator)));
        double extent1(MathD::FAbs(randomDistribution1(generator)));

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
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0{ -100.0, 100.0 };
    std::uniform_real<double> randomDistribution1(1.0, 10.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 center(randomDistribution0(generator), randomDistribution0(generator));

        Vector2 axis0(randomDistribution0(generator), randomDistribution0(generator));

        axis0.Normalize();

        Vector2 axis1(randomDistribution0(generator), randomDistribution0(generator));

        axis1.Normalize();

        const double extent0(MathD::FAbs(randomDistribution1(generator)));
        const double extent1(MathD::FAbs(randomDistribution1(generator)));

        Ellipse2D firstEllipse2(center, axis0, axis1, extent0, extent1);

        const auto matrix = firstEllipse2.GetMatrix();

        if (MathD::FAbs(matrix.Determinant()) <= 1e-8)
            continue;

        auto firstEllipse2Coefficients = firstEllipse2.ToCoefficients();

        const Ellipse2D secondEllipse2(firstEllipse2Coefficients);

        firstEllipse2.FromCoefficients(secondEllipse2.ToCoefficients());

        // 测试firstEllipse2和secondEllipse2计算相等性
        auto matrix0 = firstEllipse2.GetMatrix();
        auto matrix1 = secondEllipse2.GetMatrix();
        auto matrix2 = Matrix2D(firstEllipse2.GetAxis0() / firstEllipse2.GetExtent0(), firstEllipse2.GetAxis0() / firstEllipse2.GetExtent0()) +
                       Matrix2D(firstEllipse2.GetAxis1() / firstEllipse2.GetExtent1(), firstEllipse2.GetAxis1() / firstEllipse2.GetExtent1());

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-8));
        ASSERT_TRUE(Approximate(matrix0, matrix2, 1e-10));

        matrix0 = firstEllipse2.GetMatrixInverse();
        matrix1 = secondEllipse2.GetMatrixInverse();
        matrix2 = Matrix2D(firstEllipse2.GetAxis0() * firstEllipse2.GetExtent0(), firstEllipse2.GetAxis0() * firstEllipse2.GetExtent0()) +
                  Matrix2D(firstEllipse2.GetAxis1() * firstEllipse2.GetExtent1(), firstEllipse2.GetAxis1() * firstEllipse2.GetExtent1());

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-3));
        ASSERT_TRUE(Approximate(matrix0, matrix2, 1e-10));

        const Vector2 point(randomDistribution0(generator), randomDistribution0(generator));

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
