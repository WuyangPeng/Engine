///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 16:46)

#include "PolynomialFit4Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit4Detail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class PolynomialFit4<float>;
    template class PolynomialFit4<double>;
}

Mathematics::PolynomialFit4Testing::PolynomialFit4Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolynomialFit4Testing)

void Mathematics::PolynomialFit4Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolynomialFit4Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit4Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(0.0, 50.0);
    const uniform_int<> secondRandomDistribution(5, 40);
    const uniform_int<> thirdRandomDistribution(1, 4);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<double> x;
        std::vector<double> y;
        std::vector<double> z;
        std::vector<double> w;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            x.push_back(firstRandomDistribution(generator));
            y.push_back(firstRandomDistribution(generator));
            z.push_back(firstRandomDistribution(generator));
            w.push_back(firstRandomDistribution(generator));
        }

        const int xDegree = thirdRandomDistribution(generator);
        const int yDegree = thirdRandomDistribution(generator);
        const int zDegree = thirdRandomDistribution(generator);

        PolynomialFit4D polynomialFit(x, y, z, w, xDegree, yDegree, zDegree);

        if (polynomialFit.IsSolveSucceed())
        {
            vector<double> polynomial = polynomialFit.GetCoeff();

            for (int i = 0; i < size; ++i)
            {
                double sum = 0.0;
                for (int zIndex = 0; zIndex <= zDegree; ++zIndex)
                {
                    for (int yIndex = 0; yIndex <= yDegree; ++yIndex)
                    {
                        for (int xIndex = 0; xIndex <= xDegree; ++xIndex)
                        {
                            const auto temp = xIndex + (xDegree + 1) * (yIndex + (yDegree + 1) * zIndex);
                            sum += polynomial.at(temp) * MathD::Pow(x.at(i), xIndex) * MathD::Pow(y.at(i), yIndex) * MathD::Pow(z.at(i), zIndex);
                        }
                    }
                }

                const double value = sum - w.at(i);

                ASSERT_LESS_EQUAL(MathD::FAbs(value), 35.0);
            }
        }
    }
}
