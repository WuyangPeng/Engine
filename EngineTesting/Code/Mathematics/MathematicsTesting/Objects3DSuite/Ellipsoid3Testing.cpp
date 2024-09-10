///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:16)

#include "Ellipsoid3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

namespace Mathematics
{
    template class Ellipsoid3<float>;
    template class Ellipsoid3<double>;
}

Mathematics::Ellipsoid3Testing::Ellipsoid3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Ellipsoid3Testing)

void Mathematics::Ellipsoid3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Ellipsoid3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::Ellipsoid3Testing::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0{ -100.0, 100.0 };
    std::uniform_real_distribution<double> randomDistribution1(1.0, 10.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D center(randomDistribution0(generator),
                        randomDistribution0(generator),
                        randomDistribution0(generator));

        Vector3D axis0(randomDistribution0(generator),
                       randomDistribution0(generator),
                       randomDistribution0(generator));

        axis0.Normalize();

        Vector3D axis1(randomDistribution0(generator),
                       randomDistribution0(generator),
                       randomDistribution0(generator));

        axis1.Normalize();

        Vector3D axis2(randomDistribution0(generator),
                       randomDistribution0(generator),
                       randomDistribution0(generator));

        axis2.Normalize();

        double extent0(MathD::FAbs(randomDistribution1(generator)));
        double extent1(MathD::FAbs(randomDistribution1(generator)));
        double extent2(MathD::FAbs(randomDistribution1(generator)));

        const Ellipsoid3D firstEllipsoid3(center, axis0, axis1, axis2, extent0, extent1, extent2);

        ASSERT_TRUE(Vector3ToolsD::Approximate(firstEllipsoid3.GetCenter(), center));

        ASSERT_TRUE(Vector3ToolsD::Approximate(firstEllipsoid3.GetAxis0(), axis0));
        ASSERT_TRUE(Vector3ToolsD::Approximate(firstEllipsoid3.GetAxis1(), axis1));
        ASSERT_TRUE(Vector3ToolsD::Approximate(firstEllipsoid3.GetAxis2(), axis2));
        ASSERT_APPROXIMATE(firstEllipsoid3.GetExtent0(), extent0, 1e-10);
        ASSERT_APPROXIMATE(firstEllipsoid3.GetExtent1(), extent1, 1e-10);
        ASSERT_APPROXIMATE(firstEllipsoid3.GetExtent2(), extent2, 1e-10);

        const auto matrix = firstEllipsoid3.GetMatrix();

        if (MathD::FAbs(matrix.Determinant()) <= 1e-8)
            continue;

        auto firstEllipsoid3Coefficients = firstEllipsoid3.ToCoefficients();

        Ellipsoid3D secondEllipsoid3(firstEllipsoid3Coefficients, 1e-10);

        ASSERT_TRUE(Vector3ToolsD::Approximate(secondEllipsoid3.GetCenter(), center, 1e-8f));

        center = secondEllipsoid3.GetCenter();
        axis0 = secondEllipsoid3.GetAxis0();
        axis1 = secondEllipsoid3.GetAxis1();
        axis2 = secondEllipsoid3.GetAxis2();
        extent0 = secondEllipsoid3.GetExtent0();
        extent1 = secondEllipsoid3.GetExtent1();
        extent2 = secondEllipsoid3.GetExtent2();

        const Ellipsoid3D thirdEllipsoid3(center, axis0, axis1, axis2, extent0, extent1, extent2);

        ASSERT_TRUE(Approximate(secondEllipsoid3.ToCoefficients(), thirdEllipsoid3.ToCoefficients(), 1e-10));

        secondEllipsoid3.FromCoefficients(thirdEllipsoid3.ToCoefficients(), 1e-10);

        ASSERT_TRUE(Vector3ToolsD::Approximate(secondEllipsoid3.GetCenter(), thirdEllipsoid3.GetCenter(), 1e-9));

        ASSERT_TRUE(Vector3ToolsD::Approximate(secondEllipsoid3.GetAxis0(), thirdEllipsoid3.GetAxis0(), 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate(secondEllipsoid3.GetAxis1(), thirdEllipsoid3.GetAxis1(), 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate(secondEllipsoid3.GetAxis2(), thirdEllipsoid3.GetAxis2(), 1e-10));
        ASSERT_APPROXIMATE(secondEllipsoid3.GetExtent0(), thirdEllipsoid3.GetExtent0(), 1e-5);
        ASSERT_APPROXIMATE(secondEllipsoid3.GetExtent1(), thirdEllipsoid3.GetExtent1(), 1e-6);
        ASSERT_APPROXIMATE(secondEllipsoid3.GetExtent2(), thirdEllipsoid3.GetExtent2(), 1e-8);
    }
}

void Mathematics::Ellipsoid3Testing::CalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0{ -50.0, 50.0 };
    std::uniform_real_distribution<double> randomDistribution1(1.0, 10.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D center(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        Vector3D axis0(randomDistribution0(generator),
                       randomDistribution0(generator),
                       randomDistribution0(generator));

        axis0.Normalize();

        Vector3D axis1(randomDistribution0(generator),
                       randomDistribution0(generator),
                       randomDistribution0(generator));

        axis1.Normalize();

        Vector3D axis2(randomDistribution0(generator),
                       randomDistribution0(generator),
                       randomDistribution0(generator));

        axis2.Normalize();

        const double extent0(MathD::FAbs(randomDistribution1(generator)));
        const double extent1(MathD::FAbs(randomDistribution1(generator)));
        const double extent2(MathD::FAbs(randomDistribution1(generator)));

        Ellipsoid3D firstEllipse2(center, axis0, axis1, axis2, extent0, extent1, extent2);

        const auto matrix = firstEllipse2.GetMatrix();

        if (MathD::FAbs(matrix.Determinant()) <= 1e-8)
            continue;

        auto firstEllipse2Coefficients = firstEllipse2.ToCoefficients();

        const Ellipsoid3D secondEllipse2(firstEllipse2Coefficients, 1e-10);

        firstEllipse2.FromCoefficients(secondEllipse2.ToCoefficients(), 1e-10);

        // 测试firstEllipse2和secondEllipse2计算相等性

        auto matrix0 = firstEllipse2.GetMatrix();
        auto matrix1 = secondEllipse2.GetMatrix();
        auto matrix2 = Matrix3D(firstEllipse2.GetAxis0() / firstEllipse2.GetExtent0(), firstEllipse2.GetAxis0() / firstEllipse2.GetExtent0()) +
                       Matrix3D(firstEllipse2.GetAxis1() / firstEllipse2.GetExtent1(), firstEllipse2.GetAxis1() / firstEllipse2.GetExtent1()) +
                       Matrix3D(firstEllipse2.GetAxis2() / firstEllipse2.GetExtent2(), firstEllipse2.GetAxis2() / firstEllipse2.GetExtent2());

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-7));
        ASSERT_TRUE(Approximate(matrix0, matrix2, 1e-10));

        matrix0 = firstEllipse2.GetMatrixInverse();
        matrix1 = secondEllipse2.GetMatrixInverse();
        matrix2 = Matrix3D(firstEllipse2.GetAxis0() * firstEllipse2.GetExtent0(), firstEllipse2.GetAxis0() * firstEllipse2.GetExtent0()) +
                  Matrix3D(firstEllipse2.GetAxis1() * firstEllipse2.GetExtent1(), firstEllipse2.GetAxis1() * firstEllipse2.GetExtent1()) +
                  Matrix3D(firstEllipse2.GetAxis2() * firstEllipse2.GetExtent2(), firstEllipse2.GetAxis2() * firstEllipse2.GetExtent2());

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-1));
        ASSERT_TRUE(Approximate(matrix0, matrix2, 1e-10));

        const Vector3D point(randomDistribution0(generator),
                             randomDistribution0(generator),
                             randomDistribution0(generator));

        auto diff = point - firstEllipse2.GetCenter();
        auto ratio0 = Vector3ToolsD::DotProduct(firstEllipse2.GetAxis0(), diff) / firstEllipse2.GetExtent0();
        auto ratio1 = Vector3ToolsD::DotProduct(firstEllipse2.GetAxis1(), diff) / firstEllipse2.GetExtent1();
        auto ratio2 = Vector3ToolsD::DotProduct(firstEllipse2.GetAxis2(), diff) / firstEllipse2.GetExtent2();
        auto evaluate = ratio0 * ratio0 + ratio1 * ratio1 + ratio2 * ratio2 - 1.0;

        ASSERT_APPROXIMATE(firstEllipse2.Evaluate(point), secondEllipse2.Evaluate(point), 1e-3);

        ASSERT_APPROXIMATE(firstEllipse2.Evaluate(point), evaluate, 1e-10);

        ASSERT_EQUAL(firstEllipse2.Contains(point), secondEllipse2.Contains(point));

        ASSERT_EQUAL(firstEllipse2.Contains(point), evaluate <= 0.0);
    }
}
