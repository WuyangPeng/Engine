// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 13:26)

#include "Query3FilteredTesting.h"
#include "Mathematics/Query/Query3FilteredDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::swap;
using std::vector;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
namespace Mathematics
{
	template class Query3Filtered<double>;
	template class Query3Filtered<float>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Query3FilteredTesting) 

void Mathematics::Query3FilteredTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
	ASSERT_NOT_THROW_EXCEPTION_0(PlaneTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TetrahedronTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CircumspherTest);
	
}

void Mathematics::Query3FilteredTesting
	::VerticesTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(1, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<Vector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int m = 0; m < size; ++m)
		{
			vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		Query3FilteredD query(vertices,0.0);

		ASSERT_ENUM_EQUAL(query.GetType(), QueryType::Filtered);
		ASSERT_EQUAL(query.GetNumVertices(), size);

		for (int m = 0; m < size; ++m)
		{
			ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, query.GetVertice(m), vertices[m], 1e-10);
		}
	}
}
 
void Mathematics::Query3FilteredTesting
	::PlaneTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(1, 50);
	uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<Vector3D> firstVertices;
		std::vector<Vector3D> secondVertices;
		int size = secondRandomDistribution(generator);

		for (int m = 0; m < size; ++m)
		{
			firstVertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
			secondVertices.push_back(Vector3D(thirdRandomDistribution(generator), thirdRandomDistribution(generator), thirdRandomDistribution(generator)));
		}

		uniform_int<> thirdRandomDistribution1(0, size - 1);

		int firstIndex = thirdRandomDistribution1(generator);
		int secondIndex = thirdRandomDistribution1(generator);
		int thirdIndex = thirdRandomDistribution1(generator);
		int fourthIndex = thirdRandomDistribution1(generator);

		Query3FilteredD firstQuery(firstVertices, 0.0);

		ASSERT_ENUM_EQUAL(firstQuery.ToPlane(secondIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
		ASSERT_ENUM_EQUAL(firstQuery.ToPlane(thirdIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
		ASSERT_ENUM_EQUAL(firstQuery.ToPlane(fourthIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);

		if (firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex && thirdIndex != fourthIndex && secondIndex != fourthIndex && firstIndex != fourthIndex)
		{			 
			Vector3D firstVector = firstVertices[firstIndex];
			Vector3D secondVector = firstVertices[secondIndex];
			Vector3D thirdVector = firstVertices[thirdIndex];
			Vector3D fourthVector = firstVertices[fourthIndex];

			Matrix3D matrix(firstVector - secondVector, thirdVector - secondVector, fourthVector - secondVector, MatrixMajorFlags::Column);

			double det = matrix.Determinant();

			if (0.0 < det)
			{
				ASSERT_ENUM_EQUAL(firstQuery.ToPlane(firstVector, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::PositiveSide);

			}
			else if (det < 0.0)
			{
				ASSERT_ENUM_EQUAL(firstQuery.ToPlane(firstVector, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::NegativeSide);

			}
			else
			{
				ASSERT_ENUM_EQUAL(firstQuery.ToPlane(firstVector, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);

			}
		
		}	

		Query3FilteredD secondQuery(secondVertices, 1.0);
		Query3RationalD thirdQuery(secondVertices);
			
		ASSERT_ENUM_EQUAL(secondQuery.ToPlane(firstIndex, secondIndex, thirdIndex, fourthIndex), thirdQuery.ToPlane(firstIndex, secondIndex, thirdIndex, fourthIndex));
	}
}

void Mathematics::Query3FilteredTesting
	::TetrahedronTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(1, 50);
	uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<Vector3D> firstVertices;
		std::vector<Vector3D> secondVertices;
		int size = secondRandomDistribution(generator);

		for (int m = 0; m < size; ++m)
		{
			firstVertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
			secondVertices.push_back(Vector3D(thirdRandomDistribution(generator), thirdRandomDistribution(generator), thirdRandomDistribution(generator)));
		}

		uniform_int<> thirdRandomDistribution1(0, size - 1);

		int firstIndex = thirdRandomDistribution1(generator);
		int secondIndex = thirdRandomDistribution1(generator);
		int thirdIndex = thirdRandomDistribution1(generator);
		int fourthIndex = thirdRandomDistribution1(generator);
		int fifthIndex = thirdRandomDistribution1(generator);

		Query3FilteredD firstQuery(firstVertices, 0.0);

		if (firstQuery.ToPlane(secondIndex, thirdIndex, fourthIndex, fifthIndex) == PlaneQueryType::PositiveSide)
		{
			swap(secondIndex, thirdIndex);
		}

		ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(secondIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
		ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(thirdIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
		ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(fourthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
		ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(fifthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);

		PlaneQueryType sign0 = firstQuery.ToPlane(firstIndex, thirdIndex, fourthIndex, fifthIndex);
		PlaneQueryType sign1 = firstQuery.ToPlane(firstIndex, secondIndex, fourthIndex, fifthIndex);
		PlaneQueryType sign2 = firstQuery.ToPlane(firstIndex, secondIndex, thirdIndex, fifthIndex);
		PlaneQueryType sign3 = firstQuery.ToPlane(firstIndex, secondIndex, thirdIndex, fourthIndex);

		if (sign0 == PlaneQueryType::PositiveSide || sign1 == PlaneQueryType::NegativeSide ||
			sign2 == PlaneQueryType::PositiveSide || sign3 == PlaneQueryType::NegativeSide)
		{
			ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::Outside);
		}
		else if (sign0 == PlaneQueryType::OnPlane || sign1 == PlaneQueryType::OnPlane || sign2 == PlaneQueryType::OnPlane || sign3 == PlaneQueryType::OnPlane)
		{
			ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
		}
		else
		{
			ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::Inside);
		}

		Query3FilteredD secondQuery(secondVertices, 1.0);
		Query3RationalD thirdQuery(secondVertices);

		if (secondQuery.ToPlane(secondIndex, thirdIndex, fourthIndex, fifthIndex) == PlaneQueryType::PositiveSide)
		{
			swap(secondIndex, thirdIndex);
		}

		ASSERT_ENUM_EQUAL(secondQuery.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), thirdQuery.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex));
	}
}

void Mathematics::Query3FilteredTesting
	::CircumspherTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(1, 50);
	uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<Vector3D> firstVertices;
		std::vector<Vector3D> secondVertices;
		int size = secondRandomDistribution(generator);

		for (int m = 0; m < size; ++m)
		{
			firstVertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
			secondVertices.push_back(Vector3D(thirdRandomDistribution(generator), thirdRandomDistribution(generator), thirdRandomDistribution(generator)));
		}

		uniform_int<> thirdRandomDistribution1(0, size - 1);

		int firstIndex = thirdRandomDistribution1(generator);
		int secondIndex = thirdRandomDistribution1(generator);
		int thirdIndex = thirdRandomDistribution1(generator);
		int fourthIndex = thirdRandomDistribution1(generator);
		int fifthIndex = thirdRandomDistribution1(generator);

		Query3FilteredD firstQuery(firstVertices, 0.0);

		ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(secondIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
		ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(thirdIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
		ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(fourthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
		ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(fifthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);

		if (firstIndex != secondIndex && secondIndex != thirdIndex &&
			thirdIndex != fourthIndex && fourthIndex != firstIndex &&
			secondIndex != fourthIndex && firstIndex != thirdIndex &&
			fifthIndex != secondIndex && fifthIndex != thirdIndex &&
			fifthIndex != fourthIndex && firstIndex != fifthIndex)
		{
			 
			Vector3D firstVector = firstVertices[firstIndex];
			Vector3D secondVector = firstVertices[secondIndex];
			Vector3D thirdVector = firstVertices[thirdIndex];
			Vector3D fourthVector = firstVertices[fourthIndex];
			Vector3D fifthVector = firstVertices[fifthIndex];

			Vector4D s0(firstVector - secondVector);
			Vector4D s1(thirdVector - secondVector);
			Vector4D s2(fourthVector - secondVector);
			Vector4D s3(fifthVector - secondVector);

			Vector4D s4(firstVector + secondVector);
			Vector4D s5(thirdVector + secondVector);
			Vector4D s6(fourthVector + secondVector);
			Vector4D s7(fifthVector + secondVector);

			s0[3] = Vector4ToolsD::DotProduct(s0, s4);
			s1[3] = Vector4ToolsD::DotProduct(s1, s5);
			s2[3] = Vector4ToolsD::DotProduct(s2, s6);
			s3[3] = Vector4ToolsD::DotProduct(s3, s7);

			Matrix4D matrix(s0[0], s0[1], s0[2], s0[3], s1[0], s1[1], s1[2], s1[3], s2[0], s2[1], s2[2], s2[3], s3[0], s3[1], s3[2], s3[3]);

			double det = matrix.Determinant();		 

			if (0.0 < det)
			{
				ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::Inside);
			}
			else if (det < 0.0)
			{
				ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::Outside);

			}
			else
			{
				ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);

			}
		}

		Query3FilteredD secondQuery(secondVertices, 1.0);
		Query3RationalD thirdQuery(secondVertices);

		ASSERT_ENUM_EQUAL(secondQuery.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex),thirdQuery.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex));
	}
}