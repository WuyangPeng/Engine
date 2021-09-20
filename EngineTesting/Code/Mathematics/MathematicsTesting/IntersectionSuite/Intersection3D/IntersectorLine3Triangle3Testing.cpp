// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:54)

#include "IntersectorLine3Triangle3Testing.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorLine3Triangle3Detail.h"
#include "Mathematics/Intersection/Intersection3D/StaticTestIntersectorLine3Triangle3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>

namespace Mathematics
{
	template class StaticFindIntersectorLine3Triangle3<float>;
	template class StaticFindIntersectorLine3Triangle3<double>;
	template class StaticTestIntersectorLine3Triangle3<float>;
	template class StaticTestIntersectorLine3Triangle3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, IntersectorLine3Triangle3Testing)

void Mathematics::IntersectorLine3Triangle3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FindTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntersectTest);
}

void Mathematics::IntersectorLine3Triangle3Testing
	::FindTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0,100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D origin(randomDistribution(generator),
			             randomDistribution(generator),
						 randomDistribution(generator));

		DoubleVector3D direction(randomDistribution(generator),
			                randomDistribution(generator),
							randomDistribution(generator));

		direction.Normalize();

		DoubleLine3 line(origin,direction);

		DoubleVector3D firstPoint(randomDistribution(generator),
			                 randomDistribution(generator),
							 randomDistribution(generator));

		DoubleVector3D secondPoint(randomDistribution(generator),
			                  randomDistribution(generator),
							  randomDistribution(generator));

		DoubleVector3D thirdPoint(randomDistribution(generator),
			                  randomDistribution(generator),
							  randomDistribution(generator));

		DoubleTriangle3 triangle(firstPoint,secondPoint,thirdPoint);

		DoubleStaticFindIntersectorLine3Triangle3 intersector(line, triangle);

		IntersectionType intersectionType = intersector.GetIntersectionType();

		if(intersectionType == IntersectionType::Point)
			ASSERT_TRUE(intersector.IsIntersection());
		else
			ASSERT_FALSE(intersector.IsIntersection());	

		ASSERT_TRUE(DoubleVector3DTools::Approximate(intersector.GetLine().GetDirection(),
			                                    direction,1e-10));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(intersector.GetLine().GetOrigin(),
			                                    origin,1e-10));

		ASSERT_TRUE(DoubleVector3DTools::Approximate(intersector.GetTriangle().GetVertex(0),
			                                    firstPoint,1e-10));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(intersector.GetTriangle().GetVertex(1),
			                                    secondPoint,1e-10));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(intersector.GetTriangle().GetVertex(2),
			                                    thirdPoint,1e-10));

		
		// ÷µ≤‚ ‘
		DoubleVector3D lineOrigin = line.GetOrigin() - triangle.GetVertex(0);
		DoubleVector3D edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
		DoubleVector3D edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
		DoubleVector3D normal = DoubleVector3DTools::CrossProduct(edge1,edge2);
		 
		double directionDotNormal = 
			DoubleVector3DTools::DotProduct(line.GetDirection(),normal);				

		if(DoubleMath::FAbs(directionDotNormal) <= DoubleMath::GetZeroTolerance())
		{
			ASSERT_ENUM_EQUAL(intersectionType , IntersectionType::Empty);
		}
		else
		{
			NumericalValueSymbol sign = NumericalValueSymbol::Zero;
			if (DoubleMath::GetZeroTolerance() < directionDotNormal)
			{
				sign = NumericalValueSymbol::Positive;
			}
			else if (directionDotNormal < DoubleMath::GetZeroTolerance())
			{
				sign = NumericalValueSymbol::Negative;
				directionDotNormal = -directionDotNormal;
			}

			DoubleVector3D originCrossEdge2 = 
				DoubleVector3DTools::CrossProduct(lineOrigin,edge2);
			double directionDotOriginCrossEdge2 =
				sign * DoubleVector3DTools::DotProduct(line.GetDirection(),
				                                  originCrossEdge2);
			if (0.0 <= directionDotOriginCrossEdge2)
			{
				DoubleVector3D edge1CrossOrigin = 
					DoubleVector3DTools::CrossProduct(edge1,lineOrigin);
				double directionDotEdge1CrossOrigin =
					sign * DoubleVector3DTools::DotProduct(line.GetDirection(),
					                                  edge1CrossOrigin);

				if (0.0 <= directionDotEdge1CrossOrigin)
				{
					if (directionDotOriginCrossEdge2 + directionDotEdge1CrossOrigin <= directionDotNormal)
					{
						ASSERT_ENUM_EQUAL(intersectionType , IntersectionType::Point);		
						double originDotNormal = 
							-sign *  DoubleVector3DTools::DotProduct(lineOrigin,normal);

						double lineParameter = originDotNormal / directionDotNormal;
						double triangleBary1 = directionDotOriginCrossEdge2 / directionDotNormal;
						double triangleBary2 = directionDotEdge1CrossOrigin / directionDotNormal;
						double triangleBary0 = 
							1.0 - triangleBary1 - triangleBary2;

						ASSERT_APPROXIMATE(lineParameter,intersector.GetLineParameter(),1e-10);
						ASSERT_APPROXIMATE(triangleBary0,intersector.GetTriangleBary0(),1e-10);
						ASSERT_APPROXIMATE(triangleBary1,intersector.GetTriangleBary1(),1e-10);
						ASSERT_APPROXIMATE(triangleBary2,intersector.GetTriangleBary2(),1e-10);
					}
					else
					{
						ASSERT_ENUM_EQUAL(intersectionType , IntersectionType::Empty);
					}					
				}
				else
				{
					ASSERT_ENUM_EQUAL(intersectionType , IntersectionType::Empty);
				}				
			}
			else
			{
				ASSERT_ENUM_EQUAL(intersectionType , IntersectionType::Empty);
			}			
		}
	}
}

void Mathematics::IntersectorLine3Triangle3Testing
	::IntersectTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstRandomDistribution(-100.0f,100.0f);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector3D origin(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		FloatVector3D direction(firstRandomDistribution(generator),
			                firstRandomDistribution(generator),
							firstRandomDistribution(generator));

		direction.Normalize();

		FloatLine3 line(origin,direction);

		FloatVector3D firstPoint(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		FloatVector3D secondPoint(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		FloatVector3D thirdPoint(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		FloatTriangle3 triangle(firstPoint,secondPoint,thirdPoint);

		FloatStaticTestIntersectorLine3Triangle3  intersector(line, triangle);

		IntersectionType intersectionType = intersector.GetIntersectionType();

		if(intersectionType == IntersectionType::Point)
			ASSERT_TRUE(intersector.IsIntersection());
		else
			ASSERT_FALSE(intersector.IsIntersection());	

		ASSERT_TRUE(FloatVector3DTools::Approximate(intersector.GetLine().GetDirection(),
			                                    direction,1e-8f));
		ASSERT_TRUE(FloatVector3DTools::Approximate(intersector.GetLine().GetOrigin(),
			                                    origin,1e-8f));

		ASSERT_TRUE(FloatVector3DTools::Approximate(intersector.GetTriangle().GetVertex(0),
			                                    firstPoint,1e-8f));
		ASSERT_TRUE(FloatVector3DTools::Approximate(intersector.GetTriangle().GetVertex(1),
			                                    secondPoint,1e-8f));
		ASSERT_TRUE(FloatVector3DTools::Approximate(intersector.GetTriangle().GetVertex(2),
			                                    thirdPoint,1e-8f));

		// ÷µ≤‚ ‘
		FloatVector3D lineOrigin = line.GetOrigin() - triangle.GetVertex(0);
		FloatVector3D edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
		FloatVector3D edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
		FloatVector3D normal = FloatVector3DTools::CrossProduct(edge1,edge2);
		 
		float directionDotNormal = 
			FloatVector3DTools::DotProduct(line.GetDirection(),normal);				

		if(FloatMath::FAbs(directionDotNormal) <= FloatMath::GetZeroTolerance())
		{
			ASSERT_ENUM_EQUAL(intersectionType , IntersectionType::Empty);
		}
		else
		{
			NumericalValueSymbol sign = NumericalValueSymbol::Zero;
			if (FloatMath::GetZeroTolerance() < directionDotNormal)
			{
				sign = NumericalValueSymbol::Positive;
			}
			else if (directionDotNormal < FloatMath::GetZeroTolerance())
			{
				sign = NumericalValueSymbol::Negative;
				directionDotNormal = -directionDotNormal;
			}

			FloatVector3D originCrossEdge2 = 
				FloatVector3DTools::CrossProduct(lineOrigin,edge2);
			float directionDotOriginCrossEdge2 =
				sign * FloatVector3DTools::DotProduct(line.GetDirection(),
				                                  originCrossEdge2);
			if (0.0 <= directionDotOriginCrossEdge2)
			{
				FloatVector3D edge1CrossOrigin = 
					FloatVector3DTools::CrossProduct(edge1,lineOrigin);
				float directionDotEdge1CrossOrigin =
					sign * FloatVector3DTools::DotProduct(line.GetDirection(),
					                                  edge1CrossOrigin);

				if (0.0 <= directionDotEdge1CrossOrigin)
				{
					if (directionDotNormal <=
						directionDotOriginCrossEdge2 + directionDotEdge1CrossOrigin)
					{
						ASSERT_ENUM_EQUAL(intersectionType , IntersectionType::Point);
					}
					else
					{
						ASSERT_ENUM_EQUAL(intersectionType , IntersectionType::Empty);
					}					
				}
				else
				{
					ASSERT_ENUM_EQUAL(intersectionType , IntersectionType::Empty);
				}				
			}
			else
			{
				ASSERT_ENUM_EQUAL(intersectionType , IntersectionType::Empty);
			}			
		}
	}
}

