///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/30 11:17)

#include "Ellipsoid3CoefficientsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3CoefficientsDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Ellipsoid3Coefficients<float>;
    template class Ellipsoid3Coefficients<double>;
}

Mathematics::Ellipsoid3CoefficientsTesting::Ellipsoid3CoefficientsTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Ellipsoid3CoefficientsTesting)

void Mathematics::Ellipsoid3CoefficientsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Ellipsoid3CoefficientsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EllipsoidTest);
}

void Mathematics::Ellipsoid3CoefficientsTesting::EllipsoidTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D firstVector(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        Matrix3D firstMatrix(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        firstMatrix(0, 1) = firstRandomDistribution(generator);
        firstMatrix(0, 2) = firstRandomDistribution(generator);
        firstMatrix(1, 2) = firstRandomDistribution(generator);
        firstMatrix(1, 0) = firstMatrix(0, 1);
        firstMatrix(2, 0) = firstMatrix(0, 2);
        firstMatrix(2, 1) = firstMatrix(1, 2);

        double constants(firstRandomDistribution(generator));

        Ellipsoid3CoefficientsD ellipsoid3Coefficients(firstMatrix, firstVector, constants);

        auto secondMatrix = ellipsoid3Coefficients.GetMatrix();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(ellipsoid3Coefficients.GetVector(), firstVector));

        ASSERT_APPROXIMATE(constants, ellipsoid3Coefficients.GetConstants(), 1e-10);

        auto coefficient = ellipsoid3Coefficients.GetCoefficients();

        Ellipsoid3CoefficientsD secondEllipse2Coefficients(coefficient);

        auto secondCoefficient = secondEllipse2Coefficients.GetCoefficients();

        for (auto m = 0; m < secondEllipse2Coefficients.GetCoefficientsSize(); ++m)
        {
            ASSERT_APPROXIMATE(coefficient.at(m), secondCoefficient.at(m), 1e-10);
        }

        firstVector = secondEllipse2Coefficients.GetVector();
        firstMatrix = secondEllipse2Coefficients.GetMatrix();
        constants = secondEllipse2Coefficients.GetConstants();

        Ellipsoid3CoefficientsD thirdEllipse2Coefficients(firstMatrix, firstVector, constants);

        secondMatrix = thirdEllipse2Coefficients.GetMatrix();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(thirdEllipse2Coefficients.GetVector(), firstVector));

        ASSERT_APPROXIMATE(constants, thirdEllipse2Coefficients.GetConstants(), 1e-10);

        coefficient = thirdEllipse2Coefficients.GetCoefficients();

        for (auto m = 0; m < secondEllipse2Coefficients.GetCoefficientsSize(); ++m)
        {
            ASSERT_APPROXIMATE(coefficient.at(m), secondCoefficient.at(m), 1e-10);
        }

        ASSERT_TRUE(Approximate(secondEllipse2Coefficients, thirdEllipse2Coefficients, 1e-10));
    }
}
