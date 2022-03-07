// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:58)

#include "Tetrahedron3Testing.h"
#include "Mathematics/Objects3D/Tetrahedron3Detail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
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
		Vector3D firstPoint(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 -MathD::FAbs(firstRandomDistribution(generator)));

		Vector3D secondPoint(MathD::FAbs(firstRandomDistribution(generator)),
			                  -MathD::FAbs(firstRandomDistribution(generator)),
							  0.0);

		Vector3D thirdPoint(firstRandomDistribution(generator),
			                 MathD::FAbs(firstRandomDistribution(generator)),
							 0.0);

		Vector3D fourthPoint(-MathD::FAbs(firstRandomDistribution(generator)),
			                  -MathD::FAbs(firstRandomDistribution(generator)),
							  0.0);

		Tetrahedron3D tetrahedron(firstPoint,secondPoint,thirdPoint,fourthPoint);

		ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(0),firstPoint));
		ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(1),secondPoint));
		ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(2),thirdPoint));
		ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedron.GetVertex(3),fourthPoint));

		vector<Vector3D> Vector3dVector;
		Vector3dVector.push_back(firstPoint);
		Vector3dVector.push_back(secondPoint);
		Vector3dVector.push_back(thirdPoint);
		Vector3dVector.push_back(fourthPoint);

		Tetrahedron3D secondTetrahedron(Vector3dVector);

		ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(0),firstPoint));
		ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(1),secondPoint));
		ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(2),thirdPoint));
		ASSERT_TRUE(Vector3ToolsD::Approximate(secondTetrahedron.GetVertex(3),fourthPoint));
	
	    vector<int> faceIndices = Tetrahedron3D::GetFaceIndices(0);

		ASSERT_EQUAL(faceIndices.size(),3u);

		ASSERT_EQUAL(faceIndices[0],0);
		ASSERT_EQUAL(faceIndices[1],2);
		ASSERT_EQUAL(faceIndices[2],1);

		faceIndices = Tetrahedron3D::GetFaceIndices(1);

		ASSERT_EQUAL(faceIndices.size(),3u);

		ASSERT_EQUAL(faceIndices[0],0);
		ASSERT_EQUAL(faceIndices[1],1);
		ASSERT_EQUAL(faceIndices[2],3);

		faceIndices = Tetrahedron3D::GetFaceIndices(2);

		ASSERT_EQUAL(faceIndices.size(),3u);

		ASSERT_EQUAL(faceIndices[0],0);
		ASSERT_EQUAL(faceIndices[1],3);
		ASSERT_EQUAL(faceIndices[2],2);

		faceIndices = Tetrahedron3D::GetFaceIndices(3);

		ASSERT_EQUAL(faceIndices.size(),3u);

		ASSERT_EQUAL(faceIndices[0],1);
		ASSERT_EQUAL(faceIndices[1],2);
		ASSERT_EQUAL(faceIndices[2],3);

		vector<Plane3D> firstPlaneVector = secondTetrahedron.GetPlanes();
		vector<Plane3D> secondPlaneVector = tetrahedron.GetPlanes();

		ASSERT_EQUAL(firstPlaneVector.size(),4u);
		ASSERT_EQUAL(secondPlaneVector.size(),4u);

		for(int m = 0; m < 4;++m)
		{
			ASSERT_APPROXIMATE(firstPlaneVector[m].GetConstant(), secondPlaneVector[m].GetConstant(), 1e-10);
			ASSERT_TRUE(Vector3ToolsD::Approximate(firstPlaneVector[m].GetNormal(), secondPlaneVector[m].GetNormal()));


			faceIndices = Tetrahedron3D::GetFaceIndices(m);

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

