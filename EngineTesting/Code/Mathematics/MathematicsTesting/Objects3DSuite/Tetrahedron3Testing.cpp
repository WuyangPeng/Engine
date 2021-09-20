// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:58)

#include "Tetrahedron3Testing.h"
#include "Mathematics/Objects3D/Tetrahedron3Detail.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Tetrahedron3<float>;
	template class Tetrahedron3<double>;
}
 
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Tetrahedron3Testing) 

void Mathematics::Tetrahedron3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(TetrahedronTest);
}

void Mathematics::Tetrahedron3Testing
	::TetrahedronTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D firstPoint(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 -DoubleMath::FAbs(firstRandomDistribution(generator)));

		DoubleVector3D secondPoint(DoubleMath::FAbs(firstRandomDistribution(generator)),
			                  -DoubleMath::FAbs(firstRandomDistribution(generator)),
							  0.0);

		DoubleVector3D thirdPoint(firstRandomDistribution(generator),
			                 DoubleMath::FAbs(firstRandomDistribution(generator)),
							 0.0);

		DoubleVector3D fourthPoint(-DoubleMath::FAbs(firstRandomDistribution(generator)),
			                  -DoubleMath::FAbs(firstRandomDistribution(generator)),
							  0.0);

		DoubleTetrahedron3 tetrahedron(firstPoint,secondPoint,thirdPoint,fourthPoint);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(tetrahedron.GetVertex(0),firstPoint));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(tetrahedron.GetVertex(1),secondPoint));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(tetrahedron.GetVertex(2),thirdPoint));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(tetrahedron.GetVertex(3),fourthPoint));

		vector<DoubleVector3D> vector3DdVector;
		vector3DdVector.push_back(firstPoint);
		vector3DdVector.push_back(secondPoint);
		vector3DdVector.push_back(thirdPoint);
		vector3DdVector.push_back(fourthPoint);

		DoubleTetrahedron3 secondTetrahedron(vector3DdVector);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(secondTetrahedron.GetVertex(0),firstPoint));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(secondTetrahedron.GetVertex(1),secondPoint));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(secondTetrahedron.GetVertex(2),thirdPoint));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(secondTetrahedron.GetVertex(3),fourthPoint));
	
	    vector<int> faceIndices = DoubleTetrahedron3::GetFaceIndices(0);

		ASSERT_EQUAL(faceIndices.size(),3u);

		ASSERT_EQUAL(faceIndices[0],0);
		ASSERT_EQUAL(faceIndices[1],2);
		ASSERT_EQUAL(faceIndices[2],1);

		faceIndices = DoubleTetrahedron3::GetFaceIndices(1);

		ASSERT_EQUAL(faceIndices.size(),3u);

		ASSERT_EQUAL(faceIndices[0],0);
		ASSERT_EQUAL(faceIndices[1],1);
		ASSERT_EQUAL(faceIndices[2],3);

		faceIndices = DoubleTetrahedron3::GetFaceIndices(2);

		ASSERT_EQUAL(faceIndices.size(),3u);

		ASSERT_EQUAL(faceIndices[0],0);
		ASSERT_EQUAL(faceIndices[1],3);
		ASSERT_EQUAL(faceIndices[2],2);

		faceIndices = DoubleTetrahedron3::GetFaceIndices(3);

		ASSERT_EQUAL(faceIndices.size(),3u);

		ASSERT_EQUAL(faceIndices[0],1);
		ASSERT_EQUAL(faceIndices[1],2);
		ASSERT_EQUAL(faceIndices[2],3);

		vector<DoublePlane3> firstPlaneVector = secondTetrahedron.GetPlanes();
		vector<DoublePlane3> secondPlaneVector = tetrahedron.GetPlanes();

		ASSERT_EQUAL(firstPlaneVector.size(),4u);
		ASSERT_EQUAL(secondPlaneVector.size(),4u);

		for(int m = 0; m < 4;++m)
		{
			ASSERT_APPROXIMATE(firstPlaneVector[m].GetConstant(), secondPlaneVector[m].GetConstant(), 1e-10);
			ASSERT_TRUE(DoubleVector3DTools::Approximate(firstPlaneVector[m].GetNormal(), secondPlaneVector[m].GetNormal()));


			faceIndices = DoubleTetrahedron3::GetFaceIndices(m);

			ASSERT_ENUM_EQUAL(firstPlaneVector[m].WhichSide  (tetrahedron.GetVertex(faceIndices[0])), NumericalValueSymbol::Zero);

			ASSERT_ENUM_EQUAL(firstPlaneVector[m].WhichSide (tetrahedron.GetVertex(faceIndices[1])), NumericalValueSymbol::Zero);

			ASSERT_ENUM_EQUAL(firstPlaneVector[m].WhichSide (tetrahedron.GetVertex(faceIndices[2])),  NumericalValueSymbol::Zero);
		}

		ASSERT_ENUM_EQUAL(firstPlaneVector[0].WhichSide (tetrahedron.GetVertex(3)), NumericalValueSymbol::Negative);

		ASSERT_ENUM_EQUAL(firstPlaneVector[1].WhichSide (tetrahedron.GetVertex(2)), NumericalValueSymbol::Negative);

		ASSERT_ENUM_EQUAL(firstPlaneVector[2].WhichSide (tetrahedron.GetVertex(1)), NumericalValueSymbol::Negative);

		ASSERT_ENUM_EQUAL(firstPlaneVector[3].WhichSide (tetrahedron.GetVertex(0)), NumericalValueSymbol::Negative);
	}
}

