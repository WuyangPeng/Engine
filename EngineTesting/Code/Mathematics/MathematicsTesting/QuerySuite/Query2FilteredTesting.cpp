// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:51)

#include "Query2FilteredTesting.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Query/Query2FilteredDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Algebra/Vector2DTools.h"

using std::swap;
using std::vector;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine; 

namespace Mathematics
{
	template class Query2Filtered<double>;
	template class Query2Filtered<float>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Query2FilteredTesting) 

void Mathematics::Query2FilteredTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CircumcircleTest);
}

void Mathematics::Query2FilteredTesting
	::VerticesTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(1, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector2D> vertices;
		int size = secondRandomDistribution(generator);

		for (int m = 0; m < size; ++m)
		{
			vertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleQuery2Filtered query(vertices,0.0);

		ASSERT_ENUM_EQUAL(query.GetType(), QueryType::Filtered);
		ASSERT_EQUAL(query.GetNumVertices(), size);

		for (int m = 0; m < size; ++m)
		{
 			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, query.GetVertice(m), vertices[m], 1e-10);
		}
	  
	}
}

void Mathematics::Query2FilteredTesting
	::LineTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(1, 50);
	uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector2D> firstVertices;
		std::vector<DoubleVector2D> secondVertices;
		int size = secondRandomDistribution(generator);

		for (int m = 0; m < size; ++m)
		{
			firstVertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
			secondVertices.push_back(DoubleVector2D(thirdRandomDistribution(generator), thirdRandomDistribution(generator)));
		}

		uniform_int<> thirdRandomDistribution1(0, size - 1);

		int firstIndex = thirdRandomDistribution1(generator);
		int secondIndex = thirdRandomDistribution1(generator);
		int thirdIndex = thirdRandomDistribution1(generator);		

		DoubleQuery2Filtered firstQuery(firstVertices,0.0);

		ASSERT_ENUM_EQUAL(firstQuery.ToLine(secondIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
		ASSERT_ENUM_EQUAL(firstQuery.ToLine(thirdIndex, secondIndex, thirdIndex), LineQueryType::OnLine);

		if(firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex)
		{
			DoubleVector2D firstVector = firstVertices[firstIndex];
			DoubleVector2D secondVector = firstVertices[secondIndex];
			DoubleVector2D thirdVector = firstVertices[thirdIndex];

			double dotPerp = DoubleVector2DTools::DotPerp(firstVector - secondVector,thirdVector - secondVector);

			if(0.0 < dotPerp)
			{
				ASSERT_ENUM_EQUAL(firstQuery.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Right);
			}
			else if(dotPerp < 0.0)
			{
				ASSERT_ENUM_EQUAL(firstQuery.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Left);
			}
			else
			{   
				ASSERT_ENUM_EQUAL(firstQuery.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
			}

		}

		DoubleQuery2Filtered secondQuery(secondVertices, 1.0);
		DoubleQuery2Rational thirdQuery(secondVertices);

		ASSERT_ENUM_EQUAL(secondQuery.ToLine(firstIndex, secondIndex, thirdIndex),thirdQuery.ToLine(firstIndex, secondIndex, thirdIndex));
	}
}

void Mathematics::Query2FilteredTesting
	::TriangleTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(1, 50);
	uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector2D> firstVertices;
		std::vector<DoubleVector2D> secondVertices;
		int size = secondRandomDistribution(generator);

		for (int m = 0; m < size; ++m)
		{
			firstVertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
			secondVertices.push_back(DoubleVector2D(thirdRandomDistribution(generator), thirdRandomDistribution(generator)));
		}

		uniform_int<> thirdRandomDistribution1(0, size - 1);

		int firstIndex = thirdRandomDistribution1(generator);
		int secondIndex = thirdRandomDistribution1(generator);
		int thirdIndex = thirdRandomDistribution1(generator);
		int fourthIndex = thirdRandomDistribution1(generator);

		DoubleQuery2Filtered firstQuery(firstVertices,0.0);
		if (firstQuery.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
		{
			swap(secondIndex, thirdIndex); 
		}

		DoubleVector2D firstVector = firstVertices[firstIndex];
		DoubleVector2D secondVector = firstVertices[secondIndex];
		DoubleVector2D thirdVector = firstVertices[thirdIndex];
		DoubleVector2D fourthVector = firstVertices[fourthIndex]; 		

		ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(secondIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
		ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(thirdIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
		ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(fourthIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);

		LineQueryType sign0 = firstQuery.ToLine(firstIndex, thirdIndex, fourthIndex);
		LineQueryType sign1 = firstQuery.ToLine(firstIndex, secondIndex, fourthIndex);
		LineQueryType sign2 = firstQuery.ToLine(firstIndex, secondIndex, thirdIndex);		
		
		if (sign0 == LineQueryType::Right || sign1 == LineQueryType::Left || sign2 == LineQueryType::Right)
		{
			ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Outside);
		}
		else if (sign0 == LineQueryType::OnLine || sign1 == LineQueryType::OnLine ||  sign2 == LineQueryType::OnLine)
		{
			ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
		}
		else
		{
			ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Inside);
		}

		DoubleQuery2Filtered secondQuery(secondVertices, 1.0);
		DoubleQuery2Rational thirdQuery(secondVertices);

		if (secondQuery.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
		{
			swap(secondIndex, thirdIndex); 
		}

		ASSERT_ENUM_EQUAL(secondQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex),  thirdQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex));
	}
}

void Mathematics::Query2FilteredTesting
	::CircumcircleTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(1, 50);
	uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector2D> firstVertices;
		std::vector<DoubleVector2D> secondVertices;
		int size = secondRandomDistribution(generator);

		for (int m = 0; m < size; ++m)
		{
			firstVertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
			secondVertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		uniform_int<> thirdRandomDistribution1(0, size - 1);

		int firstIndex = thirdRandomDistribution1(generator);
		int secondIndex = thirdRandomDistribution1(generator);
		int thirdIndex = thirdRandomDistribution1(generator);
		int fourthIndex = thirdRandomDistribution1(generator);

		DoubleQuery2Filtered firstQuery(firstVertices,0.0);

		ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(secondIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
		ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(thirdIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
		ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(fourthIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);

		if(firstIndex != secondIndex && secondIndex != thirdIndex &&
		   thirdIndex != fourthIndex && fourthIndex != firstIndex &&
		   secondIndex != fourthIndex && firstIndex != thirdIndex)
		{
			DoubleVector2D firstVector = firstVertices[firstIndex];
			DoubleVector2D secondVector = firstVertices[secondIndex];
			DoubleVector2D thirdVector = firstVertices[thirdIndex];
			DoubleVector2D fourthVector = firstVertices[fourthIndex];

			DoubleVector2D lhsPlusTest = secondVector + firstVector;
			DoubleVector2D lhsMinusTest = secondVector - firstVector;
			DoubleVector2D mhsPlusTest = thirdVector + firstVector;
			DoubleVector2D mhsMinusTest = thirdVector - firstVector;
			DoubleVector2D rhsPlusTest = fourthVector + firstVector;
			DoubleVector2D rhsMinusTest = fourthVector - firstVector; 
			double z0 = DoubleVector2DTools::DotProduct(lhsPlusTest,lhsMinusTest);
			double z1 = DoubleVector2DTools::DotProduct(mhsPlusTest,mhsMinusTest);
			double z2 = DoubleVector2DTools::DotProduct(rhsPlusTest,rhsMinusTest);

			DoubleVector3D fifthVector(lhsMinusTest[0],lhsMinusTest[1],z0);
			DoubleVector3D sixthVector(mhsMinusTest[0],mhsMinusTest[1],z1);
			DoubleVector3D seventhVector(rhsMinusTest[0],rhsMinusTest[1],z2);

			double dot = DoubleVector3DTools::ScalarTripleProduct(fifthVector,sixthVector,seventhVector);
			if(0.0 < dot)
			{
				ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex,fourthIndex), CircumcircleQueryType::Inside);
			}
			else if(dot < 0.0)
			{
				ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Outside);
			}
			else
			{   
				ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
			}
		}

		DoubleQuery2Filtered secondQuery(secondVertices, 1.0);
		DoubleQuery2Rational thirdQuery(secondVertices);

		ASSERT_ENUM_EQUAL(secondQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex),thirdQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex));
	}
}

