// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 16:31)

#include "EllipseByArcs2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/EllipseByArcs2Detail.h"
#include "Mathematics/Objects2D/Ellipse2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class EllipseByArcs2<float>;
    template class EllipseByArcs2<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EllipseByArcs2Testing)

void Mathematics::EllipseByArcs2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Arcs2Test);
}

void Mathematics::EllipseByArcs2Testing ::Arcs2Test()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(5.0, 100.0);
    uniform_int<> secondRandomDistribution(10, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        int numArcs = secondRandomDistribution(generator);
        double a = firstRandomDistribution(generator);
        double b = firstRandomDistribution(generator);

        EllipseByArcs2D ellipseByArcs2(a, b, numArcs);

        ASSERT_EQUAL(ellipseByArcs2.getNumArcs(), numArcs);

        const std::vector<Vector2D> points = ellipseByArcs2.GetPoints();
        const std::vector<Circle2D> circle2 = ellipseByArcs2.GetCircle2();

        ASSERT_EQUAL(points.size(), static_cast<size_t>(numArcs) + 1);
        ASSERT_EQUAL(circle2.size(), static_cast<size_t>(numArcs));

        for (int i = 0; i < numArcs; ++i)
        {
            Arc2D arc = ellipseByArcs2.GetArc2(i);

            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, arc.GetCenter(), circle2[i].GetCenter(), 1e-10);
            ASSERT_APPROXIMATE(arc.GetRadius(), circle2[i].GetRadius(), 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, arc.GetEnd0(), points[i], 1e-10);
            auto temp = i + 1;
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, arc.GetEnd1(), points[temp], 1e-10);
        }

        Ellipse2D ellipse2(Vector2D(), Vector2D::GetUnitX(), Vector2D::GetUnitY(), a, b);

        for (unsigned i = 0; i < points.size(); ++i)
        {
            ASSERT_TRUE(ellipse2.Contains(points[i]));
        }
    }
}
