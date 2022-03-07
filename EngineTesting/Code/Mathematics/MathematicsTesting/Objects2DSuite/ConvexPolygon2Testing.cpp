// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/22 14:07)

#include "ConvexPolygon2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/ConvexPolygon2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class ConvexPolygon2<float>;
    template class ConvexPolygon2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, ConvexPolygon2Testing)

void Mathematics::ConvexPolygon2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConvexPolygonTest);
}

void Mathematics::ConvexPolygon2Testing ::ConvexPolygonTest()
{
    default_random_engine generator{};
    uniform_real<double> firstRandomDistribution{ 0.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        /*		constexpr int size = 8;*/

        // 		Polygon2d::Vector2Ptr Vector2Ptr(NEW1<Polygon2d::Vector2>(size));
        //
        // 		// x��yֵΪ��
        // 		DoubleVector2 firstVertex(firstRandomDistribution(generator),firstRandomDistribution(generator));
        //
        // 		uniform_real<double> secondRandomDistribution(0.0,firstVertex[0]);
        //
        // 		double firstRandom = secondRandomDistribution(generator);
        // 		double secondRandom = firstRandomDistribution(generator);
        //
        // 		// x��yֵΪ��
        // 		DoubleVector2 secondVertex(firstVertex[0] - firstRandom,firstVertex[1] + secondRandom);
        //
        // 		// xֵΪ����yֵΪ��
        // 		DoubleVector2 thirdVertex(-secondVertex[0],secondVertex[1]);
        //
        // 		// xֵΪ����yֵΪ��
        // 		DoubleVector2 fourthVertex(thirdVertex[0] - firstRandom,thirdVertex[1] - secondRandom);
        //
        // 		// xֵΪ����yֵΪ��
        // 		DoubleVector2 fifthVertex(fourthVertex[0],-fourthVertex[1]);
        //
        // 		// xֵΪ����yֵΪ��
        // 		DoubleVector2 sixthVertex(fifthVertex[0] + firstRandom,fifthVertex[1] - secondRandom);
        //
        // 		// xֵΪ����yֵΪ��
        // 		DoubleVector2 seventhVertex(-sixthVertex[0],sixthVertex[1]);
        //
        // 		// xֵΪ����yֵΪ��
        // 		DoubleVector2 eighthVertex(seventhVertex[0] + firstRandom,seventhVertex[1] + secondRandom);
        //
        // 		// �����ǲ��ԣ�û�ж�Vector2Ptr��linePtr���г�ʼ����
        // 		// ʹ��SetVertex��UpdateLines���м��㡣
        // 		ConvexPolygon2d::LinePtr linePtr(NEW1<ConvexPolygon2d::Line>(size));
        //
        // 		ConvexPolygon2d firstPolygon(size,Vector2Ptr,linePtr);
        // 		firstPolygon.SetVertex(0,firstVertex);
        // 		firstPolygon.SetVertex(1,secondVertex);
        // 		firstPolygon.SetVertex(2,thirdVertex);
        // 		firstPolygon.SetVertex(3,fourthVertex);
        // 		firstPolygon.SetVertex(4,fifthVertex);
        // 		firstPolygon.SetVertex(5,sixthVertex);
        // 		firstPolygon.SetVertex(6,seventhVertex);
        // 		firstPolygon.SetVertex(7,eighthVertex);
        //
        // 		ASSERT_TRUE(firstPolygon.IsUpdateLines());
        //
        // 		firstPolygon.UpdateLines();
        //
        // 		ASSERT_FALSE(firstPolygon.IsUpdateLines());
        // 		ASSERT_TRUE(firstPolygon.IsConvex());
        //
        // 		ConvexPolygon2d secondPolygon(size,firstPolygon.GetVertices(),firstPolygon.GetLines());
        //
        // 		ConvexPolygon2d::LinePtr secondPtr = secondPolygon.GetLines();
        // 		ConvexPolygon2d::LinePtr thirdPtr = firstPolygon.GetLines();
        //
        // 		for(int k = 0;k < size;++k)
        // 		{
        // 			ASSERT_TRUE(DoubleVector2Tools::Approximate(secondPtr[k].first,thirdPtr[k].first));
        // 			ASSERT_APPROXIMATE(secondPtr[k].second,thirdPtr[k].second,1e-10);
        // 			ASSERT_TRUE(DoubleVector2Tools::Approximate(secondPolygon.GetLine(k).first, firstPolygon.GetLine(k).first));
        // 			ASSERT_APPROXIMATE(secondPolygon.GetLine(k).second, firstPolygon.GetLine(k).second,1e-10);
        // 		}
        //
        // 		for(int k = 0;k < 10;++k)
        // 		{
        // 			DoubleVector2 point(firstRandomDistribution(generator), firstRandomDistribution(generator));
        //
        // 			bool contains = true;
        //
        // 			for (int j = 0; j < firstPolygon.GetNumVertices(); ++j)
        // 			{
        // 				double distance = DoubleVector2Tools::DotProduct(firstPolygon.GetLine(j).first,point) - firstPolygon.GetLine(j).second;
        //
        // 				if (distance < 0.0)
        // 				{
        // 					contains =  false;
        // 					break;
        // 				}
        // 			}
        //
        // 			ASSERT_EQUAL(firstPolygon.Contains(point),contains);
        // 		}
    }
}
