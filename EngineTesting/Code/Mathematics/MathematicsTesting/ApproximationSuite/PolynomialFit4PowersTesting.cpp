///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 16:46)

#include "PolynomialFit4PowersTesting.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit4PowersDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class PolynomialFit4Powers<float>;
    template class PolynomialFit4Powers<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialFit4PowersTesting)

void Mathematics::PolynomialFit4PowersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit4PowersTesting::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(0.0, 1.0);
    const uniform_int<> secondRandomDistribution(2, 5);
    const uniform_int<> thirdRandomDistribution(2, 3);
    const uniform_int<> fourthRandomDistribution(0, 2);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<double> x;
        std::vector<double> y;
        std::vector<double> z;
        std::vector<double> w;
        const int xSize = secondRandomDistribution(generator);
        const int ySize = secondRandomDistribution(generator);
        const int zSize = secondRandomDistribution(generator);

        for (int i = 0; i < xSize; ++i)
        {
            x.push_back(firstRandomDistribution(generator));
        }

        for (int i = 0; i < ySize; ++i)
        {
            y.push_back(firstRandomDistribution(generator));
        }

        for (int i = 0; i < zSize; ++i)
        {
            z.push_back(firstRandomDistribution(generator));
        }

        for (int i = 0; i < xSize * ySize * zSize; ++i)
        {
            w.push_back(firstRandomDistribution(generator));
        }

        const int powSize = thirdRandomDistribution(generator);
        vector<CoreTools::Tuple<3, int>> power;

        for (int i = 0; i < powSize; ++i)
        {
            const CoreTools::Tuple<3, int> tuple(fourthRandomDistribution(generator),
                                                 fourthRandomDistribution(generator),
                                                 fourthRandomDistribution(generator));
            power.push_back(tuple);
        }

        PolynomialFit4PowersD polynomialFit(x, y, z, w, power, true);

        if (polynomialFit.IsSolveSucceed())
        {
            for (int zIndex = 0; zIndex < zSize; ++zIndex)
            {
                for (int yIndex = 0; yIndex < ySize; ++yIndex)
                {
                    for (int xIndex = 0; xIndex < xSize; ++xIndex)
                    {
                        const auto temp = xIndex + (yIndex + zIndex * ySize) * xSize;
                        const double value = polynomialFit(x.at(xIndex), y.at(yIndex), z.at(zIndex)) - w.at(temp);

                        ASSERT_LESS_EQUAL(MathD::FAbs(value), 40000.0);
                    }
                }
            }
        }
    }
}
