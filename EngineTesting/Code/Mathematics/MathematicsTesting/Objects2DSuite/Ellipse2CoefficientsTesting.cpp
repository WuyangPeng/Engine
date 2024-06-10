///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:11)

#include "Ellipse2CoefficientsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Ellipse2CoefficientsDetail.h"

#include <random>

namespace Mathematics
{
    template class Ellipse2Coefficients<float>;
    template class Ellipse2Coefficients<double>;
}

Mathematics::Ellipse2CoefficientsTesting::Ellipse2CoefficientsTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Ellipse2CoefficientsTesting)

void Mathematics::Ellipse2CoefficientsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Ellipse2CoefficientsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EllipseTest);
}

void Mathematics::Ellipse2CoefficientsTesting::EllipseTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector2 vector0(randomDistribution0(generator),
                        randomDistribution0(generator));

        Matrix2D matrix0(randomDistribution0(generator),
                         randomDistribution0(generator),
                         0.0,
                         randomDistribution0(generator));

        matrix0(1, 0) = matrix0(0, 1);

        double constants(randomDistribution0(generator));

        Ellipse2CoefficientsD ellipse2Coefficients(matrix0, vector0, constants);

        auto matrix1 = ellipse2Coefficients.GetMatrix();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-10));

        ASSERT_TRUE(Vector2ToolsD::Approximate(ellipse2Coefficients.GetVector(), vector0));

        ASSERT_APPROXIMATE(constants, ellipse2Coefficients.GetConstants(), 1e-10);

        auto coefficient = ellipse2Coefficients.GetCoefficients();

        Ellipse2CoefficientsD secondEllipse2Coefficients(coefficient);

        auto secondCoefficient = secondEllipse2Coefficients.GetCoefficients();

        for (auto m = 0; m < 6; ++m)
        {
            ASSERT_APPROXIMATE(coefficient.at(m), secondCoefficient.at(m), 1e-10);
        }

        vector0 = secondEllipse2Coefficients.GetVector();
        matrix0 = secondEllipse2Coefficients.GetMatrix();
        constants = secondEllipse2Coefficients.GetConstants();

        Ellipse2CoefficientsD thirdEllipse2Coefficients(matrix0, vector0, constants);

        matrix1 = thirdEllipse2Coefficients.GetMatrix();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-10));

        ASSERT_TRUE(Vector2ToolsD::Approximate(thirdEllipse2Coefficients.GetVector(), vector0, 1e-10));

        ASSERT_APPROXIMATE(constants, thirdEllipse2Coefficients.GetConstants(), 1e-10);

        coefficient = thirdEllipse2Coefficients.GetCoefficients();

        for (auto m = 0; m < 6; ++m)
        {
            ASSERT_APPROXIMATE(coefficient.at(m), secondCoefficient.at(m), 1e-10);
        }

        ASSERT_TRUE(Approximate(secondEllipse2Coefficients, thirdEllipse2Coefficients, 1e-10));
    }
}
