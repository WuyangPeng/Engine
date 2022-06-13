///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 19:27)

#include "Polygon2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Polygon2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Polygon2<float>;
    template class Polygon2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Polygon2Testing)

void Mathematics::Polygon2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PolygonTest);
}

void Mathematics::Polygon2Testing::PolygonTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        constexpr auto size = 8;

        Vector2D firstVertex(MathD::FAbs(firstRandomDistribution(generator)), MathD::FAbs(firstRandomDistribution(generator)));

        const Vector2D secondVertex(firstVertex[0] - MathD::FAbs(firstRandomDistribution(generator)),
                                    firstVertex[1] + MathD::FAbs(firstRandomDistribution(generator)));

        Vector2D thirdVertex(-MathD::FAbs(firstRandomDistribution(generator)), MathD::FAbs(firstRandomDistribution(generator)));

        const Vector2D fourthVertex(thirdVertex[0] - MathD::FAbs(firstRandomDistribution(generator)),
                                    thirdVertex[1] - MathD::FAbs(firstRandomDistribution(generator)));

        Vector2D fifthVertex(-MathD::FAbs(firstRandomDistribution(generator)), -MathD::FAbs(firstRandomDistribution(generator)));

        Vector2D sixthVertex(fifthVertex[0] + MathD::FAbs(firstRandomDistribution(generator)),
                             fifthVertex[1] - MathD::FAbs(firstRandomDistribution(generator)));

        Vector2D seventhVertex(MathD::FAbs(firstRandomDistribution(generator)), -MathD::FAbs(firstRandomDistribution(generator)));

        const Vector2D eighthVertex(seventhVertex[0] + MathD::FAbs(firstRandomDistribution(generator)),
                                    seventhVertex[1] + MathD::FAbs(firstRandomDistribution(generator)));

        Polygon2D::VerticesType ptr{ firstVertex,
                                     secondVertex,
                                     thirdVertex,
                                     fourthVertex,
                                     fifthVertex,
                                     sixthVertex,
                                     seventhVertex,
                                     eighthVertex };

        Polygon2D polygon(ptr);

        ASSERT_EQUAL(polygon.GetNumVertices(), size);

        auto secondPtr = polygon.GetVertices();

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstVertex, secondPtr.at(0)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(secondVertex, secondPtr.at(1)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(thirdVertex, secondPtr.at(2)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(fourthVertex, secondPtr.at(3)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(fifthVertex, secondPtr.at(4)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(sixthVertex, secondPtr.at(5)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(seventhVertex, secondPtr.at(6)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(eighthVertex, secondPtr.at(7)));

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstVertex, polygon.GetVertex(0)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(secondVertex, polygon.GetVertex(1)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(thirdVertex, polygon.GetVertex(2)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(fourthVertex, polygon.GetVertex(3)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(fifthVertex, polygon.GetVertex(4)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(sixthVertex, polygon.GetVertex(5)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(seventhVertex, polygon.GetVertex(6)));
        ASSERT_TRUE(Vector2ToolsD::Approximate(eighthVertex, polygon.GetVertex(7)));

        Vector2D ninthVertex(sixthVertex[0] + MathD::FAbs(firstRandomDistribution(generator)),
                             sixthVertex[1] - MathD::FAbs(firstRandomDistribution(generator)));

        polygon.SetVertex(5, ninthVertex);

        ASSERT_TRUE(Vector2ToolsD::Approximate(ninthVertex, polygon.GetVertex(5)));

        ptr.at(5) = ninthVertex;

        auto average = ptr.at(0);
        for (auto m = 1; m < size; ++m)
        {
            average += ptr.at(m);
        }
        average /= size;

        ASSERT_TRUE(Vector2ToolsD::Approximate(average, polygon.ComputeVertexAverage()));

        constexpr auto last = size - 1;
        auto perimeterLength = Vector2ToolsD::GetLength(ptr.at(0) - ptr.at(last));
        for (auto m = 1; m < size; ++m)
        {
            const auto temp = m - 1;
            auto edge = ptr.at(m) - ptr.at(temp);
            perimeterLength += Vector2ToolsD::GetLength(edge);
        }

        ASSERT_APPROXIMATE(perimeterLength, polygon.ComputePerimeterLength(), 0.00001);

        constexpr auto temp = last - 1;
        auto area = ptr.at(0)[0] * (ptr.at(1)[1] - ptr.at(last)[1]) + ptr.at(last)[0] * (ptr.at(0)[1] - ptr.at(temp)[1]);

        for (auto m = 1; m < last; ++m)
        {
            const auto m1 = m + 1;
            const auto m2 = m - 1;
            area += ptr.at(m)[0] * (ptr.at(m1)[1] - ptr.at(m2)[1]);
        }

        area /= 2.0;

        ASSERT_APPROXIMATE(area, polygon.ComputeArea(), 1e-10);
    }
}
