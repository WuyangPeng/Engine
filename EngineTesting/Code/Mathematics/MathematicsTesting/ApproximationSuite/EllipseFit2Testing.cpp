// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 16:36)

#include "EllipseFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Approximation/EllipseFit2Detail.h"
#include "Mathematics/Objects2D/Ellipse2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EllipseFit2Testing)

void Mathematics::EllipseFit2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::EllipseFit2Testing ::FitTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(0.0, 100.0);
    uniform_int<> secondRandomDistribution(5, 15);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<DoubleVector2D> vertices;
        int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        DoubleEllipseFit2 ellipseFit(vertices);

        DoubleVector2D center = ellipseFit.GetCenter();
        DoubleMatrix2 matrix = ellipseFit.GetRotate();
        double firstExtent = ellipseFit.GetExtent0();
        double secondExtent = ellipseFit.GetExtent1();

        DoubleEllipse2 ellipse(center, matrix * DoubleVector2D::GetUnitX(), matrix * DoubleVector2D::GetUnitY(), firstExtent, secondExtent);

        for (int i = 0; i < size; ++i)
        {
            ASSERT_LESS(ellipse.Evaluate(vertices[i]), 22.0);
        }
    }
}
