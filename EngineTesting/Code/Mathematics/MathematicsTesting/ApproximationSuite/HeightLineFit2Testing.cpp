// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:08)

#include "HeightLineFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/HeightLineFit2Detail.h"

#include "Mathematics/NumericalAnalysis/LinearSystem.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class HeightLineFit2<float>;
    template class HeightLineFit2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, HeightLineFit2Testing)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::HeightLineFit2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::HeightLineFit2Testing ::FitTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(10, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        HeightLineFit2D heightLineFit2(vertices);

        if (heightLineFit2.IsFit2Success())
        {
            double sumX = 0.0;
            double sumY = 0.0;
            double sumXX = 0.0;
            double sumXY = 0.0;

            for (unsigned i = 0; i < vertices.size(); ++i)
            {
                sumX += vertices[i].GetX();
                sumY += vertices[i].GetY();
                sumXX += vertices[i].GetX() * vertices[i].GetX();
                sumXY += vertices[i].GetX() * vertices[i].GetY();
            }

            double matrix[2][2]{
                { sumXX, sumX },
                { sumX, static_cast<double>(vertices.size()) }
            };

            double inputVector[2]{
                sumXY,
                sumY
            };

            // 			double outputVector[2]   { 0.0, 0.0 };
            //
            // 			DoubleLinearSystem linearSystem;
            //
            // 			linearSystem.Solve2(matrix, inputVector, outputVector);
            //
            // 			ASSERT_APPROXIMATE(heightLineFit2.GetCoeffA(), outputVector[0], 1e-10);
            // 			ASSERT_APPROXIMATE(heightLineFit2.GetCoeffB(), outputVector[1], 1e-10);
        }
    }
}
