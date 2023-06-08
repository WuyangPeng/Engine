///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 19:21)

#include "Ellipse2CoefficientsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Ellipse2CoefficientsDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

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
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector2 firstVector(firstRandomDistribution(generator),
                            firstRandomDistribution(generator));

        Matrix2D firstMatrix(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             0.0,
                             firstRandomDistribution(generator));

        firstMatrix(1, 0) = firstMatrix(0, 1);

        double constants(firstRandomDistribution(generator));

        Ellipse2CoefficientsD ellipse2Coefficients(firstMatrix, firstVector, constants);

        auto secondMatrix = ellipse2Coefficients.GetMatrix();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));

        ASSERT_TRUE(Vector2ToolsD::Approximate(ellipse2Coefficients.GetVector(), firstVector));

        ASSERT_APPROXIMATE(constants, ellipse2Coefficients.GetConstants(), 1e-10);

        auto coefficient = ellipse2Coefficients.GetCoefficients();

        Ellipse2CoefficientsD secondEllipse2Coefficients(coefficient);

        auto secondCoefficient = secondEllipse2Coefficients.GetCoefficients();

        for (auto m = 0; m < 6; ++m)
        {
            ASSERT_APPROXIMATE(coefficient.at(m), secondCoefficient.at(m), 1e-10);
        }

        firstVector = secondEllipse2Coefficients.GetVector();
        firstMatrix = secondEllipse2Coefficients.GetMatrix();
        constants = secondEllipse2Coefficients.GetConstants();

        Ellipse2CoefficientsD thirdEllipse2Coefficients(firstMatrix, firstVector, constants);

        secondMatrix = thirdEllipse2Coefficients.GetMatrix();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));

        ASSERT_TRUE(Vector2ToolsD::Approximate(thirdEllipse2Coefficients.GetVector(), firstVector, 1e-10));

        ASSERT_APPROXIMATE(constants, thirdEllipse2Coefficients.GetConstants(), 1e-10);

        coefficient = thirdEllipse2Coefficients.GetCoefficients();

        for (auto m = 0; m < 6; ++m)
        {
            ASSERT_APPROXIMATE(coefficient.at(m), secondCoefficient.at(m), 1e-10);
        }

        ASSERT_TRUE(Approximate(secondEllipse2Coefficients, thirdEllipse2Coefficients, 1e-10));
    }
}
