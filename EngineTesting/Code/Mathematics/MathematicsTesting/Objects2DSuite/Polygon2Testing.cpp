// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 14:39)

#include "Polygon2Testing.h"
#include "Mathematics/Objects2D/Polygon2Detail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SmartPointerManager.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Polygon2<float>;
	template class Polygon2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Polygon2Testing) 

void Mathematics::Polygon2Testing
	::MainTest()
{
	CoreTools::SmartPointerManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(PolygonTest);

	CoreTools::SmartPointerManager::Destroy();
}

void Mathematics::Polygon2Testing
	::PolygonTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
/*		constexpr int size = 8;*/

// 		Polygon2d::Vector2DPtr ptr(NEW1<Polygon2d::Vector2D>(size));
// 
// 		DoubleVector2D firstVertex(DoubleMath::FAbs(firstRandomDistribution(generator)),DoubleMath::FAbs(firstRandomDistribution(generator)));
// 
// 		
// 		DoubleVector2D secondVertex(firstVertex[0] - DoubleMath::FAbs(firstRandomDistribution(generator)),
// 			                   firstVertex[1] + DoubleMath::FAbs(firstRandomDistribution(generator)));
// 		
// 		DoubleVector2D thirdVertex(-DoubleMath::FAbs(firstRandomDistribution(generator)),DoubleMath::FAbs(firstRandomDistribution(generator)));
// 
// 		DoubleVector2D fourthVertex(thirdVertex[0] - DoubleMath::FAbs(firstRandomDistribution(generator)),
// 			                   thirdVertex[1] - DoubleMath::FAbs(firstRandomDistribution(generator)));
// 
// 		DoubleVector2D fifthVertex(-DoubleMath::FAbs(firstRandomDistribution(generator)),-DoubleMath::FAbs(firstRandomDistribution(generator)));
// 
// 		DoubleVector2D sixthVertex(fifthVertex[0] + DoubleMath::FAbs(firstRandomDistribution(generator)),
// 			                  fifthVertex[1] -  DoubleMath::FAbs(firstRandomDistribution(generator)));
// 
// 		DoubleVector2D seventhVertex(DoubleMath::FAbs(firstRandomDistribution(generator)),-DoubleMath::FAbs(firstRandomDistribution(generator)));
// 
// 		DoubleVector2D eighthVertex(seventhVertex[0] + DoubleMath::FAbs(firstRandomDistribution(generator)),
// 			                   seventhVertex[1] + DoubleMath::FAbs(firstRandomDistribution(generator)));
// 
// 		ptr[0] = firstVertex;
// 		ptr[1] = secondVertex;
// 		ptr[2] = thirdVertex;
// 		ptr[3] = fourthVertex;
// 		ptr[4] = fifthVertex;
// 		ptr[5] = sixthVertex;
// 		ptr[6] = seventhVertex;
// 		ptr[7] = eighthVertex;
// 
// 		Polygon2d polygon(size,ptr);
// 
// 		ASSERT_EQUAL(polygon.GetNumVertices(),size);
// 
// 		Polygon2d::Vector2DPtr secondPtr = polygon.GetVertices();
// 
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(firstVertex,secondPtr[0]));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(secondVertex,secondPtr[1]));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(thirdVertex,secondPtr[2]));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(fourthVertex,secondPtr[3]));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(fifthVertex,secondPtr[4]));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(sixthVertex,secondPtr[5]));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(seventhVertex,secondPtr[6]));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(eighthVertex,secondPtr[7]));
// 
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(firstVertex,polygon.GetVertex(0)));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(secondVertex,polygon.GetVertex(1)));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(thirdVertex,polygon.GetVertex(2)));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(fourthVertex,polygon.GetVertex(3)));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(fifthVertex,polygon.GetVertex(4)));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(sixthVertex,polygon.GetVertex(5)));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(seventhVertex,polygon.GetVertex(6)));
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(eighthVertex,polygon.GetVertex(7)));
// 
// 		DoubleVector2D ninthVertex(sixthVertex[0] + DoubleMath::FAbs(firstRandomDistribution(generator)),
// 			                  sixthVertex[1] - DoubleMath::FAbs(firstRandomDistribution(generator)));
// 
// 		polygon.SetVertex(5,ninthVertex);
// 
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(ninthVertex,polygon.GetVertex(5)));
// 
// 		ptr[5] = ninthVertex;
// 
// 		DoubleVector2D average = ptr[0];
// 		for (size_t m = 1; m < size; ++m)
// 		{
// 			average += ptr[m];
// 		}
// 		average /= size;
// 		
// 		ASSERT_TRUE(DoubleVector2DTools::Approximate(average,polygon.ComputeVertexAverage()));
// 	
// 	
// 		double perimeterLength = DoubleVector2DTools::VectorMagnitude(ptr[0] - ptr[size - 1]);
// 		for (size_t m = 1; m < size; ++m)
// 		{
// 			DoubleVector2D edge = ptr[m] - ptr[m - 1];
// 			perimeterLength += DoubleVector2DTools::VectorMagnitude(edge);
// 		}
// 
// 		ASSERT_APPROXIMATE(perimeterLength,polygon.ComputePerimeterLength(),0.00001);
// 
// 		const int last = size - 1;
// 		double area = ptr[0][0] * (ptr[1][1] - ptr[last][1]) + ptr[last][0] * (ptr[0][1] - ptr[last - 1][1]);
// 		
// 		for (int m = 1; m < last;++m)
// 		{
// 			area += ptr[m][0] * (ptr[m + 1][1] - ptr[m - 1][1]);
// 		}
// 		
// 		area /= 2.0;
// 		
// 		ASSERT_APPROXIMATE(area,polygon.ComputeArea(),1e-10);	
	}
}

