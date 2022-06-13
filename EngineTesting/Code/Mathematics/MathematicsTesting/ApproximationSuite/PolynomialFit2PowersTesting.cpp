///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 16:38)

#include "PolynomialFit2PowersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit2PowersDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class PolynomialFit2Powers<float>;
    template class PolynomialFit2Powers<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialFit2PowersTesting)

void Mathematics::PolynomialFit2PowersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::PolynomialFit2PowersTesting::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(0.0, 50.0);
    const uniform_int<> secondRandomDistribution(10, 50);
    const uniform_int<> thirdRandomDistribution(3, 5);
    const uniform_int<> fourthRandomDistribution(0, 7);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        vector<double> x;
        vector<double> w;
        vector<int> power;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            x.push_back(firstRandomDistribution(generator));
            w.push_back(firstRandomDistribution(generator));
        }

        const int powSize = thirdRandomDistribution(generator);

        for (int i = 0; i < powSize; ++i)
        {
            power.push_back(fourthRandomDistribution(generator));
        }

        PolynomialFit2PowersD polynomialFit(x, w, power);

        if (polynomialFit.IsSolveSucceed())
        {
            for (int i = 0; i < size; ++i)
            {
                const double value = polynomialFit(x.at(i)) - w.at(i);

                ASSERT_LESS_EQUAL(MathD::FAbs(value), 75.0);
            }
        }
    }
}
