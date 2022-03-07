// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:00)

#include "Ellipsoid3CoefficientsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3CoefficientsDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Ellipsoid3Coefficients<float>;
    template class Ellipsoid3Coefficients<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Ellipsoid3CoefficientsTesting)

void Mathematics::Ellipsoid3CoefficientsTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EllipsoidTest);
}

void Mathematics::Ellipsoid3CoefficientsTesting ::EllipsoidTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
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

        Matrix3D secondMatrix = ellipsoid3Coefficients.GetMatrix();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(ellipsoid3Coefficients.GetVector(), firstVector));

        ASSERT_APPROXIMATE(constants, ellipsoid3Coefficients.GetConstants(), 1e-10);

        std::vector<double> coefficient = ellipsoid3Coefficients.GetCoefficients();

        Ellipsoid3CoefficientsD secondEllipse2Coefficients(coefficient);

        std::vector<double> secondCoefficient = secondEllipse2Coefficients.GetCoefficients();

        // 		for(int m = 0;m < secondEllipse2Coefficients.GetCoefficientsSize();++m)
        // 		{
        // 			ASSERT_APPROXIMATE(coefficient[m],secondCoefficient[m],1e-10);
        // 		}

        firstVector = secondEllipse2Coefficients.GetVector();
        firstMatrix = secondEllipse2Coefficients.GetMatrix();
        constants = secondEllipse2Coefficients.GetConstants();

        Ellipsoid3CoefficientsD thirdEllipse2Coefficients(firstMatrix, firstVector, constants);

        secondMatrix = thirdEllipse2Coefficients.GetMatrix();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(thirdEllipse2Coefficients.GetVector(), firstVector));

        ASSERT_APPROXIMATE(constants, thirdEllipse2Coefficients.GetConstants(), 1e-10);

        coefficient = thirdEllipse2Coefficients.GetCoefficients();

        // 		for(int m = 0;m < secondEllipse2Coefficients.GetCoefficientsSize();++m)
        // 		{
        // 			ASSERT_APPROXIMATE(coefficient[m],secondCoefficient[m],1e-10);
        // 		}

        ASSERT_TRUE(Approximate(secondEllipse2Coefficients, thirdEllipse2Coefficients, 1e-10));
    }
}
