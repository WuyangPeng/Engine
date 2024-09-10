///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:11)

#include "ConvexPolygon2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/ConvexPolygon2Detail.h"

#include <random>

namespace Mathematics
{
    template class ConvexPolygon2<float>;
    template class ConvexPolygon2<double>;
}

Mathematics::ConvexPolygon2Testing::ConvexPolygon2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, ConvexPolygon2Testing)

void Mathematics::ConvexPolygon2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::ConvexPolygon2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConvexPolygonTest);
}

void Mathematics::ConvexPolygon2Testing::ConvexPolygonTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0{ 0.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        constexpr auto size = 8;

        Polygon2D::VerticesType vector2Ptr(size);

        // x��yֵΪ��
        Vector2D firstVertex(randomDistribution0(generator), randomDistribution0(generator));

        std::uniform_real_distribution<double> randomDistribution1(0.0, firstVertex[0]);

        auto firstRandom = randomDistribution1(generator);
        auto secondRandom = randomDistribution0(generator);

        // x��yֵΪ��
        Vector2D secondVertex(firstVertex[0] - firstRandom, firstVertex[1] + secondRandom);

        // xֵΪ����yֵΪ��
        Vector2D thirdVertex(-secondVertex[0], secondVertex[1]);

        // xֵΪ����yֵΪ��
        Vector2D fourthVertex(thirdVertex[0] - firstRandom, thirdVertex[1] - secondRandom);

        // xֵΪ����yֵΪ��
        Vector2D fifthVertex(fourthVertex[0], -fourthVertex[1]);

        // xֵΪ����yֵΪ��
        Vector2D sixthVertex(fifthVertex[0] + firstRandom, fifthVertex[1] - secondRandom);

        // xֵΪ����yֵΪ��
        Vector2D seventhVertex(-sixthVertex[0], sixthVertex[1]);

        // xֵΪ����yֵΪ��
        const Vector2D eighthVertex(seventhVertex[0] + firstRandom, seventhVertex[1] + secondRandom);

        // �����ǲ��ԣ�û�ж�Vector2Ptr��linePtr���г�ʼ����
        // ʹ��SetVertex��UpdateLines���м��㡣
        ConvexPolygon2D::LineType linePtr(size, Line2D{ Vector2D{}, Vector2D::GetUnitX() });

        ConvexPolygon2D firstPolygon{ vector2Ptr, linePtr };
        firstPolygon.SetVertex(0, firstVertex);
        firstPolygon.SetVertex(1, secondVertex);
        firstPolygon.SetVertex(2, thirdVertex);
        firstPolygon.SetVertex(3, fourthVertex);
        firstPolygon.SetVertex(4, fifthVertex);
        firstPolygon.SetVertex(5, sixthVertex);
        firstPolygon.SetVertex(6, seventhVertex);
        firstPolygon.SetVertex(7, eighthVertex);

        ASSERT_TRUE(firstPolygon.IsUpdateLines());
    }
}
