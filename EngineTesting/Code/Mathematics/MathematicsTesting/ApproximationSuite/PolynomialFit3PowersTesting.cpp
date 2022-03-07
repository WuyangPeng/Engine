// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:27)

#include "PolynomialFit3PowersTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/PolynomialFit3PowersDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"

#include "CoreTools/DataTypes/TupleDetail.h"
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

void Mathematics::PolynomialFit3PowersTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::PolynomialFit3PowersTesting ::FitTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(0.0, 2.0);
    uniform_int<> secondRandomDistribution(3, 7);
    uniform_int<> thirdRandomDistribution(2, 5);
    uniform_int<> fourthRandomDistribution(0, 3);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<double> x;
        std::vector<double> y;
        std::vector<double> w;
        int xSize = secondRandomDistribution(generator);
        int ySize = secondRandomDistribution(generator);

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

        int powSize = thirdRandomDistribution(generator);
        vector<CoreTools::Tuple<2, int>> power;

        for (int i = 0; i < powSize; ++i)
        {
            CoreTools::Tuple<2, int> tuple(fourthRandomDistribution(generator), fourthRandomDistribution(generator));
            power.push_back(tuple);
        }

        PolynomialFit3PowersD polynomialFit(x, y, w, power, true);

        if (polynomialFit.IsSolveSucceed())
        {
            for (int yIndex = 0; yIndex < ySize; ++yIndex)
            {
                for (int xIndex = 0; xIndex < xSize; ++xIndex)
                {
                    auto temp = xIndex + yIndex * xSize;
                    double value = polynomialFit(x[xIndex], y[yIndex]) - w[temp];

                    ASSERT_LESS_EQUAL(MathD::FAbs(value), 2600.0);
                }
            }
        }
    }
}
