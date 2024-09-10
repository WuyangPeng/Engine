///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:14)

#include "EllipseByArcs2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/EllipseByArcs2Detail.h"
#include "Mathematics/Objects2D/Ellipse2Detail.h"

#include <random>

namespace Mathematics
{
    template class EllipseByArcs2<float>;
    template class EllipseByArcs2<double>;
}

Mathematics::EllipseByArcs2Testing::EllipseByArcs2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EllipseByArcs2Testing)

void Mathematics::EllipseByArcs2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::EllipseByArcs2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Arcs2Test);
}

void Mathematics::EllipseByArcs2Testing::Arcs2Test()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0(5.0, 100.0);
    std::uniform_int_distribution<> randomDistribution1(10, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const int numArcs = randomDistribution1(generator);
        const double a = randomDistribution0(generator);
        const double b = randomDistribution0(generator);

        EllipseByArcs2D ellipseByArcs2(a, b, numArcs);

        ASSERT_EQUAL(ellipseByArcs2.GetNumArcs(), numArcs);

        const std::vector<Vector2D> points = ellipseByArcs2.GetPoints();
        const std::vector<Circle2D> circle2 = ellipseByArcs2.GetCircle2();

        ASSERT_EQUAL(points.size(), static_cast<size_t>(numArcs) + 1);
        ASSERT_EQUAL(circle2.size(), static_cast<size_t>(numArcs));

        for (int i = 0; i < numArcs; ++i)
        {
            const Arc2D arc = ellipseByArcs2.GetArc2(i);

            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, arc.GetCenter(), circle2.at(i).GetCenter(), 1e-10);
            ASSERT_APPROXIMATE(arc.GetRadius(), circle2.at(i).GetRadius(), 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, arc.GetEnd0(), points.at(i), 1e-10);
            const auto temp = i + 1;
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, arc.GetEnd1(), points.at(temp), 1e-10);
        }

        const Ellipse2D ellipse2(Vector2D(), Vector2D::GetUnitX(), Vector2D::GetUnitY(), a, b);

        for (unsigned i = 0; i < points.size(); ++i)
        {
            ASSERT_TRUE(ellipse2.Contains(points.at(i)));
        }
    }
}
