// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 16:36)

#include "EllipseFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/EllipseFit2Detail.h"
#include "Mathematics/Objects2D/Ellipse2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
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
        std::vector<Vector2D> vertices;
        int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        EllipseFit2D ellipseFit(vertices);

        Vector2 center = ellipseFit.GetCenter();
        Matrix2D matrix = ellipseFit.GetRotate();
        double firstExtent = ellipseFit.GetExtent0();
        double secondExtent = ellipseFit.GetExtent1();

        Ellipse2D ellipse(center, matrix * Vector2D::GetUnitX(), matrix * Vector2D::GetUnitY(), firstExtent, secondExtent);

        for (int i = 0; i < size; ++i)
        {
            ASSERT_LESS(ellipse.Evaluate(vertices[i]), 22.0);
        }
    }
}
