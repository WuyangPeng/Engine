// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/22 17:48)

#include "Polyhedron3Testing.h"
#include "Mathematics/Objects3D/Polyhedron3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Polyhedron3<float>;
	template class Polyhedron3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Polyhedron3Testing) 

void Mathematics::Polyhedron3Testing
	::MainTest()
{
	CoreTools::SmartPointerManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(PolyhedronTest);

	CoreTools::SmartPointerManager::Destroy();
}

void Mathematics::Polyhedron3Testing
	::PolyhedronTest()
{ 
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution(0.0, 100.0);
	uniform_real<double> secondRandomDistribution(-100.0, 0.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D firstVector(firstRandomDistribution(generator),
			                  secondRandomDistribution(generator),
							  firstRandomDistribution(generator));

		DoubleVector3D secondVector(firstRandomDistribution(generator),
			                   secondRandomDistribution(generator),
							   secondRandomDistribution(generator));

		DoubleVector3D thirdVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  secondRandomDistribution(generator));

		DoubleVector3D fourthVector(firstRandomDistribution(generator),
			                   firstRandomDistribution(generator),
							   firstRandomDistribution(generator));

		DoubleVector3D fifthVector(secondRandomDistribution(generator),
			                  secondRandomDistribution(generator),
							  firstRandomDistribution(generator));

		DoubleVector3D sixthVector(secondRandomDistribution(generator),
			                   secondRandomDistribution(generator),
							   secondRandomDistribution(generator));

		DoubleVector3D seventhVector(secondRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  secondRandomDistribution(generator));

		DoubleVector3D eighthVector(secondRandomDistribution(generator),
			                   firstRandomDistribution(generator),
							   firstRandomDistribution(generator));

/*		const int numVertices = 8;*/

// 		Polyhedron3d::Vector3DPtr vector3DPtr(NEW1<DoubleVector3D>(numVertices));
// 
// 		vector3DPtr[0] = firstVector;
// 		vector3DPtr[1] = secondVector;
// 		vector3DPtr[2] = thirdVector;
// 		vector3DPtr[3] = fourthVector;
// 		vector3DPtr[4] = fifthVector;
// 		vector3DPtr[5] = sixthVector;
// 		vector3DPtr[6] = seventhVector;
// 		vector3DPtr[7] = eighthVector;
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
// 		Polyhedron3d polyhedron(numVertices,vector3DPtr,numTriangles,intPtr);
// 
// 		ASSERT_EQUAL(numVertices,polyhedron.GetNumVertices());
// 		ASSERT_EQUAL(vector3DPtr,polyhedron.GetVertices());
// 		
// 		for(int k = 0;k < numVertices;++k)
// 		{
// 			// 比较地址相同
// 			ASSERT_EQUAL(&(vector3DPtr[k]),&(polyhedron.GetVertex(k)));
// 		}
// 
// 		ASSERT_EQUAL(numTriangles,polyhedron.GetNumTriangles());
// 		ASSERT_EQUAL(numTriangles * 3,polyhedron.GetNumIndices());
// 
// 		ASSERT_EQUAL(intPtr,polyhedron.GetIndices());
// 
// 		for(int k = 0;k < numTriangles;++k)
// 		{
// 			// 比较地址相同
// 			ASSERT_EQUAL(&(intPtr[k * 3]),polyhedron.GetTriangle(k));
// 		}
//  
// 		DoubleVector3D ninthVector(secondRandomDistribution(generator),secondRandomDistribution(generator),secondRandomDistribution(generator));
// 
// 		polyhedron.SetVertex(5,ninthVector);
// 
// 		ASSERT_TRUE(DoubleVector3DTools::Approximate(ninthVector,polyhedron.GetVertex(5)));
// 
// 		// vector3DPtr的值也被SetVertex修改了
// 		DoubleVector3D average = vector3DPtr[0];
// 		for (int m = 1; m < numVertices; ++m)
// 		{
// 			average += vector3DPtr[m];
// 		}		
// 
// 		average /= static_cast<double>(numVertices);
// 
// 		ASSERT_TRUE(DoubleVector3DTools::Approximate(average,polyhedron.ComputeVertexAverage()));
// 
// 		double surfaceArea = 0.0;
// 		double volume = 0.0;
// 
// 		for (int k = 0; k < numTriangles; ++k)
// 		{
// 			int v0 = intPtr[k * 3];
// 			int v1 = intPtr[k * 3 + 1];
// 			int v2 = intPtr[k * 3 + 2];
// 			DoubleVector3D edge0 = vector3DPtr[v1] - vector3DPtr[v0];
// 			DoubleVector3D edge1 = vector3DPtr[v2] - vector3DPtr[v0];
// 			DoubleVector3D cross = DoubleVector3DTools::CrossProduct(edge0,edge1);
// 			surfaceArea += DoubleVector3DTools::VectorMagnitude(cross);
// 			volume += DoubleVector3DTools::DotProduct(vector3DPtr[v0],cross);
// 		}
// 
// 		surfaceArea *= 0.5;
// 		volume /= 6.0;
// 
// 	    ASSERT_APPROXIMATE(surfaceArea,polyhedron.ComputeSurfaceArea(),1e-10);
// 		ASSERT_APPROXIMATE(volume,polyhedron.ComputeVolume(),1e-9);
	}
}

