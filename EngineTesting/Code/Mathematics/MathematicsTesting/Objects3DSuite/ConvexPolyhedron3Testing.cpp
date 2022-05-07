// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/22 16:54)

#include "ConvexPolyhedron3Testing.h"
#include "Mathematics/Objects3D/ConvexPolyhedron3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class ConvexPolyhedron3<float>;
	template class ConvexPolyhedron3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, ConvexPolyhedron3Testing) 

void Mathematics::ConvexPolyhedron3Testing
	::MainTest()
{
	//CoreTools::SmartPointerManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(ConvexPolyhedronTest);

	//CoreTools::SmartPointerManager::Destroy();
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::ConvexPolyhedron3Testing
	::ConvexPolyhedronTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ 0.0,100.0 };
	uniform_real<double> secondRandomDistribution(-100.0, 0.0);
	uniform_real<double> thirdRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
// 		double positive = firstRandomDistribution(generator);
// 		double negative = secondRandomDistribution(generator);
// 
// 		DoubleVector3 firstVector(positive,negative,positive);
// 
// 		DoubleVector3 secondVector(positive,negative,negative);
// 
// 		DoubleVector3 thirdVector(positive,positive,negative);
// 
// 		DoubleVector3 fourthVector(positive,positive, positive);
// 
// 		DoubleVector3 fifthVector(negative,negative,positive);
// 
// 		DoubleVector3 sixthVector(negative,negative,negative);
// 
// 		DoubleVector3 seventhVector(negative,positive,negative);
// 
// 		DoubleVector3 eighthVector(negative,positive,positive);
// 
// 		constexpr int numVertices = 8;

// 		Polyhedron3d::Vector3Ptr Vector3Ptr(NEW1<DoubleVector3>(numVertices));
// 
// 		Vector3Ptr[0] = firstVector;
// 		Vector3Ptr[1] = secondVector;
// 		Vector3Ptr[2] = thirdVector;
// 		Vector3Ptr[3] = fourthVector;
// 		Vector3Ptr[4] = fifthVector;
// 		Vector3Ptr[5] = sixthVector;
// 		Vector3Ptr[6] = seventhVector;
// 		Vector3Ptr[7] = eighthVector;
// 
// 		const int numTriangles = 12;
// 
// 		Polyhedron3d::IntPtr intPtr(NEW1<int>(numTriangles * 3));
// 
// 		intPtr[0] = 0;
// 		intPtr[1] = 1;
// 		intPtr[2] = 2;
// 
// 		intPtr[3] = 0;
// 		intPtr[4] = 2;
// 		intPtr[5] = 3;
// 
// 		intPtr[6] = 4;
// 		intPtr[7] = 0;
// 		intPtr[8] = 3;
// 
// 		intPtr[9] = 4;
// 		intPtr[10] = 3;
// 		intPtr[11] = 7;
// 
// 		intPtr[12] = 5;
// 		intPtr[13] = 4;
// 		intPtr[14] = 7;
// 
// 		intPtr[15] = 5;
// 		intPtr[16] = 7;
// 		intPtr[17] = 6;
// 
// 		intPtr[18] = 6;
// 		intPtr[19] = 2;
// 		intPtr[20] = 1;
// 
// 		intPtr[21] = 6;
// 		intPtr[22] = 1;
// 		intPtr[23] = 5;
// 
// 		intPtr[24] = 3;
// 		intPtr[25] = 2;
// 		intPtr[26] = 6;
// 
// 		intPtr[27] = 7;
// 		intPtr[28] = 3;
// 		intPtr[29] = 6;
// 
// 		intPtr[30] = 5;
// 		intPtr[31] = 1;
// 		intPtr[32] = 0;
// 
// 		intPtr[33] = 5;
// 		intPtr[34] = 0;
// 		intPtr[35] = 4;
// 		
// 		ConvexPolyhedron3d polyhedron(numVertices,Vector3Ptr,numTriangles,intPtr,nullptr);
// 
// 		ASSERT_EQUAL(numVertices,polyhedron.GetNumVertices());
// 		ASSERT_EQUAL(Vector3Ptr,polyhedron.GetVertices());
// 		
// 		for(int k = 0;k < numVertices;++k)
// 		{
// 			// �Ƚϵ�ַ��ͬ
// 			ASSERT_EQUAL(&(Vector3Ptr[k]),&(polyhedron.GetVertex(k)));
// 		}
// 
// 		ASSERT_EQUAL(numTriangles,polyhedron.GetNumTriangles());
// 		ASSERT_EQUAL(numTriangles * 3,polyhedron.GetNumIndices());
// 
// 		ASSERT_EQUAL(intPtr,polyhedron.GetIndices());
// 
// 		for(int k = 0;k < numTriangles;++k)
// 		{
// 			// �Ƚϵ�ַ��ͬ
// 			ASSERT_EQUAL(&(intPtr[k * 3]),polyhedron.GetTriangle(k));
// 		}
//  
// 		DoubleVector3 ninthVector(negative,negative,negative);
// 
// 		ASSERT_FALSE(polyhedron.IsUpdatePlanes());
// 		polyhedron.SetVertex(5,ninthVector);
// 		ASSERT_TRUE(polyhedron.IsUpdatePlanes());
// 		polyhedron.UpdatePlanes();	
// 		ASSERT_FALSE(polyhedron.IsUpdatePlanes());
// 
// 		ASSERT_TRUE(DoubleVector3Tools::Approximate(ninthVector,polyhedron.GetVertex(5)));
// 
// 		// Vector3Ptr��ֵҲ��SetVertex�޸���
// 		DoubleVector3 average = Vector3Ptr[0];
// 		for (int m = 1; m < numVertices; ++m)
// 		{
// 			average += Vector3Ptr[m];
// 		}		
// 
// 		average /= static_cast<double>(numVertices);
// 
// 		ASSERT_TRUE(DoubleVector3Tools::Approximate(average,polyhedron.ComputeVertexAverage()));
// 
// 		double surfaceArea = 0.0;
// 		double volume = 0.0;
// 
// 		for (int k = 0; k < numTriangles; ++k)
// 		{
// 			int v0 = intPtr[k * 3];
// 			int v1 = intPtr[k * 3 + 1];
// 			int v2 = intPtr[k * 3 + 2];
// 			DoubleVector3 edge0 = Vector3Ptr[v1] - Vector3Ptr[v0];
// 			DoubleVector3 edge1 = Vector3Ptr[v2] - Vector3Ptr[v0];
// 			DoubleVector3 cross = DoubleVector3Tools::CrossProduct(edge0,edge1);
// 			surfaceArea += DoubleVector3Tools::VectorMagnitude(cross);
// 			volume += DoubleVector3Tools::DotProduct(Vector3Ptr[v0],cross);
// 		}
// 
// 		surfaceArea *= 0.5;
// 		volume /= 6.0;
// 
// 	    ASSERT_APPROXIMATE(surfaceArea,polyhedron.ComputeSurfaceArea(),1e-10);
// 		ASSERT_APPROXIMATE(volume,polyhedron.ComputeVolume(),1e-8f);
// 
// 		ASSERT_TRUE(polyhedron.IsConvex());
// 
// 		ASSERT_UNEQUAL_NULL_PTR(polyhedron.GetPlanes());		
// 
// 		for(int k = 0;k < 2;++k)
// 		{
// 			DoubleVector3 point(thirdRandomDistribution(generator),
// 				            thirdRandomDistribution(generator),
// 							thirdRandomDistribution(generator));
// 
// 			bool contains = true;
// 
// 			for (int j = 0; j < polyhedron.GetNumTriangles(); ++j)
// 			{
// 				const DoublePlane3& plane = polyhedron.GetPlane(j);
// 
// 				double distance = plane.DistanceTo(point);
// 
// 				if (distance < 0.0)
// 				{
// 					contains = false;
// 					break;
// 				}
// 			}			
// 
// 			ASSERT_EQUAL(polyhedron.Contains(point),contains);
// 		}
	}
}
