// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:58)

#include "Query2Int64Testing.h"
#include "Mathematics/Query/QuerySortTools.h" 
#include "Mathematics/Query/Query2Int64Detail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::swap;
using std::vector;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class Query2Int64<double>;
	template class Query2Int64<float>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Query2Int64Testing) 

void Mathematics::Query2Int64Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CircumcircleTest);
}

void Mathematics::Query2Int64Testing
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

		DoubleQuery2Int64 query(vertices);

		ASSERT_ENUM_EQUAL(query.GetType(), QueryType::Int64);
		ASSERT_EQUAL(query.GetNumVertices(), size);

		for (int m = 0; m < size; ++m)
		{
 			ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, query.GetVertice(m), vertices[m], 1e-10);
		}
	  
	}
}

void Mathematics::Query2Int64Testing
	::LineTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(1, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector2D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		uniform_int<> thirdRandomDistribution(0, size - 1);

		int firstIndex = thirdRandomDistribution(generator);
		int secondIndex = thirdRandomDistribution(generator);
		int thirdIndex = thirdRandomDistribution(generator);		

		DoubleQuery2Int64 query(vertices);

		ASSERT_ENUM_EQUAL(query.ToLine(secondIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
		ASSERT_ENUM_EQUAL(query.ToLine(thirdIndex, secondIndex, thirdIndex), LineQueryType::OnLine);

		if(firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex)
		{
// 			Vector2D<int64_t> firstVector = vertices[firstIndex];
// 			Vector2D<int64_t> secondVector = vertices[secondIndex];
// 			Vector2D<int64_t> thirdVector = vertices[thirdIndex];
// 
// 			double dotPerp = Vector2DTools<double>::DotPerp(firstVector - secondVector, thirdVector - secondVector);
// 
// 			if(0 < dotPerp)
// 			{
// 				ASSERT_ENUM_EQUAL(query.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Right);
// 			}
// 			else if(dotPerp < 0)
// 			{
// 				ASSERT_ENUM_EQUAL(query.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Left);
// 			}
// 			else
// 			{   
// 				ASSERT_ENUM_EQUAL(query.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
// 			}

		}
		
	}
}

void Mathematics::Query2Int64Testing
	::TriangleTest()
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

		uniform_int<> thirdRandomDistribution(0, size - 1);

		int firstIndex = thirdRandomDistribution(generator);
		int secondIndex = thirdRandomDistribution(generator);
		int thirdIndex = thirdRandomDistribution(generator);
		int fourthIndex = thirdRandomDistribution(generator);

		DoubleQuery2Int64 query(vertices);
		if (query.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
		{
			swap(secondIndex, thirdIndex); 
		}

		DoubleVector2D firstVector = vertices[firstIndex];
		DoubleVector2D secondVector = vertices[secondIndex];
		DoubleVector2D thirdVector = vertices[thirdIndex];
		DoubleVector2D fourthVector = vertices[fourthIndex]; 		

		ASSERT_ENUM_EQUAL(query.ToTriangle(secondIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
		ASSERT_ENUM_EQUAL(query.ToTriangle(thirdIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
		ASSERT_ENUM_EQUAL(query.ToTriangle(fourthIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);

		LineQueryType sign0 = query.ToLine(firstIndex, thirdIndex, fourthIndex);
		LineQueryType sign1 = query.ToLine(firstIndex, secondIndex, fourthIndex);
		LineQueryType sign2 = query.ToLine(firstIndex, secondIndex, thirdIndex);		
		
		if (sign0 == LineQueryType::Right || sign1 == LineQueryType::Left ||
			sign2 == LineQueryType::Right)
		{
			ASSERT_ENUM_EQUAL(query.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Outside);
		}
		else if (sign0 == LineQueryType::OnLine ||
			     sign1 == LineQueryType::OnLine ||
				 sign2 == LineQueryType::OnLine)
		{
			ASSERT_ENUM_EQUAL(query.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
		}
		else
		{
			ASSERT_ENUM_EQUAL(query.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Inside);
		}
	}
}

void Mathematics::Query2Int64Testing
	::CircumcircleTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(1, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector2D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		uniform_int<> thirdRandomDistribution(0, size - 1);

		int firstIndex = thirdRandomDistribution(generator);
		int secondIndex = thirdRandomDistribution(generator);
		int thirdIndex = thirdRandomDistribution(generator);
		int fourthIndex = thirdRandomDistribution(generator);

		DoubleQuery2Int64 query(vertices);

		ASSERT_ENUM_EQUAL(query.ToCircumcircle(secondIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
		ASSERT_ENUM_EQUAL(query.ToCircumcircle(thirdIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
		ASSERT_ENUM_EQUAL(query.ToCircumcircle(fourthIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);

		if(firstIndex != secondIndex && secondIndex != thirdIndex &&
		   thirdIndex != fourthIndex && fourthIndex != firstIndex &&
		   secondIndex != fourthIndex && firstIndex != thirdIndex)
		{
// 			Vector2D<int64_t> firstVector = vertices[firstIndex];
// 			Vector2D<int64_t> secondVector = vertices[secondIndex];
// 			Vector2D<int64_t> thirdVector = vertices[thirdIndex];
// 			Vector2D<int64_t> fourthVector = vertices[fourthIndex];
// 
// 			Vector2D<int64_t> lhsPlusTest = secondVector + firstVector;
// 			Vector2D<int64_t> lhsMinusTest = secondVector - firstVector;
// 			Vector2D<int64_t> mhsPlusTest = thirdVector + firstVector;
// 			Vector2D<int64_t> mhsMinusTest = thirdVector - firstVector;
// 			Vector2D<int64_t> rhsPlusTest = fourthVector + firstVector;
// 			Vector2D<int64_t> rhsMinusTest = fourthVector - firstVector;
// 			int64_t z0 = boost::numeric_cast<int64_t>(Vector2DTools<double>::DotProduct(lhsPlusTest, lhsMinusTest));
// 			int64_t z1 = boost::numeric_cast<int64_t>(Vector2DTools<double>::DotProduct(mhsPlusTest, mhsMinusTest));
// 			int64_t z2 = boost::numeric_cast<int64_t>(Vector2DTools<double>::DotProduct(rhsPlusTest, rhsMinusTest));
// 
// 			Vector3D<int64_t> fifthVector(lhsMinusTest[0], lhsMinusTest[1], z0);
// 			Vector3D<int64_t> sixthVector(mhsMinusTest[0], mhsMinusTest[1], z1);
// 			Vector3D<int64_t> seventhVector(rhsMinusTest[0], rhsMinusTest[1], z2);
// 
// 			double dot = Vector3DTools<double>::ScalarTripleProduct(fifthVector, sixthVector, seventhVector);
// 			if(0 < dot)
// 			{
// 				ASSERT_ENUM_EQUAL(query.ToCircumcircle(firstIndex, secondIndex, thirdIndex,fourthIndex), CircumcircleQueryType::Inside);
// 			}
// 			else if(dot < 0)
// 			{
// 				ASSERT_ENUM_EQUAL(query.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Outside);
// 			}
// 			else
// 			{   
// 				ASSERT_ENUM_EQUAL(query.ToCircumcircle(firstIndex, secondIndex, thirdIndex,fourthIndex), CircumcircleQueryType::OnCircumcircle);
			//}
		}
	}
}

