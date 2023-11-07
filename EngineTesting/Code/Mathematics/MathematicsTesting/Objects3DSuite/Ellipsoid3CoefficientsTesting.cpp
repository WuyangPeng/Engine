///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:16)

#include "Ellipsoid3CoefficientsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3CoefficientsDetail.h"

#include <random>

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
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D vector0(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

        Matrix3D matrix0(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

        matrix0(0, 1) = randomDistribution0(generator);
        matrix0(0, 2) = randomDistribution0(generator);
        matrix0(1, 2) = randomDistribution0(generator);
        matrix0(1, 0) = matrix0(0, 1);
        matrix0(2, 0) = matrix0(0, 2);
        matrix0(2, 1) = matrix0(1, 2);

        double constants(randomDistribution0(generator));

        Ellipsoid3CoefficientsD ellipsoid3Coefficients(matrix0, vector0, constants);

        auto matrix1 = ellipsoid3Coefficients.GetMatrix();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(ellipsoid3Coefficients.GetVector(), vector0));

        ASSERT_APPROXIMATE(constants, ellipsoid3Coefficients.GetConstants(), 1e-10);

        auto coefficient = ellipsoid3Coefficients.GetCoefficients();

        Ellipsoid3CoefficientsD secondEllipse2Coefficients(coefficient);

        auto secondCoefficient = secondEllipse2Coefficients.GetCoefficients();

        for (auto m = 0; m < secondEllipse2Coefficients.GetCoefficientsSize(); ++m)
        {
            ASSERT_APPROXIMATE(coefficient.at(m), secondCoefficient.at(m), 1e-10);
        }

        vector0 = secondEllipse2Coefficients.GetVector();
        matrix0 = secondEllipse2Coefficients.GetMatrix();
        constants = secondEllipse2Coefficients.GetConstants();

        Ellipsoid3CoefficientsD thirdEllipse2Coefficients(matrix0, vector0, constants);

        matrix1 = thirdEllipse2Coefficients.GetMatrix();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(thirdEllipse2Coefficients.GetVector(), vector0));

        ASSERT_APPROXIMATE(constants, thirdEllipse2Coefficients.GetConstants(), 1e-10);

        coefficient = thirdEllipse2Coefficients.GetCoefficients();

        for (auto m = 0; m < secondEllipse2Coefficients.GetCoefficientsSize(); ++m)
        {
            ASSERT_APPROXIMATE(coefficient.at(m), secondCoefficient.at(m), 1e-10);
        }

        ASSERT_TRUE(Approximate(secondEllipse2Coefficients, thirdEllipse2Coefficients, 1e-10));
    }
}
