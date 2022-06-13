///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 16:44)

#include "PolynomialFit3PowersTesting.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit3PowersDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class PolynomialFit3Powers<float>;
    template class PolynomialFit3Powers<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialFit3PowersTesting)

void Mathematics::PolynomialFit3PowersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit3PowersTesting::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(0.0, 2.0);
    const uniform_int<> secondRandomDistribution(3, 7);
    const uniform_int<> thirdRandomDistribution(2, 5);
    const uniform_int<> fourthRandomDistribution(0, 3);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<double> x;
        std::vector<double> y;
        std::vector<double> w;
        const int xSize = secondRandomDistribution(generator);
        const int ySize = secondRandomDistribution(generator);

        for (int i = 0; i < xSize; ++i)
        {
            x.push_back(firstRandomDistribution(generator));
        }

        for (int i = 0; i < ySize; ++i)
        {
            y.push_back(firstRandomDistribution(generator));
        }

        for (int i = 0; i < xSize * ySize; ++i)
        {
            w.push_back(firstRandomDistribution(generator));
        }

        const int powSize = thirdRandomDistribution(generator);
        vector<CoreTools::Tuple<2, int>> power;

        for (int i = 0; i < powSize; ++i)
        {
            const CoreTools::Tuple<2, int> tuple(fourthRandomDistribution(generator), fourthRandomDistribution(generator));
            power.push_back(tuple);
        }

        PolynomialFit3PowersD polynomialFit(x, y, w, power, true);

        if (polynomialFit.IsSolveSucceed())
        {
            for (int yIndex = 0; yIndex < ySize; ++yIndex)
            {
                for (int xIndex = 0; xIndex < xSize; ++xIndex)
                {
                    const auto temp = xIndex + yIndex * xSize;
                    const double value = polynomialFit(x.at(xIndex), y.at(yIndex)) - w.at(temp);

                    ASSERT_LESS_EQUAL(MathD::FAbs(value), 2600.0);
                }
            }
        }
    }
}
