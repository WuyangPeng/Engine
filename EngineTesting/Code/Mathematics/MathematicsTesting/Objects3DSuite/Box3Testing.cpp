// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 15:52)

#include "Box3Testing.h"
#include "Mathematics/Objects3D/Box3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Algebra/Vector3DTools.h"

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Box3<float>;
	template class Box3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Box3Testing) 

void Mathematics::Box3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BoxTest);
}

void Mathematics::Box3Testing
	::BoxTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop) 
	{
		DoubleVector3D center(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		DoubleVector3D firstAxis(firstRandomDistribution(generator),
			                firstRandomDistribution(generator),
							firstRandomDistribution(generator));

		DoubleVector3D secondAxis(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		DoubleVector3D thirdAxis(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		double firstExtent = DoubleVector3DTools::VectorMagnitude(firstAxis);
		double secondExtent = DoubleVector3DTools::VectorMagnitude(secondAxis);
		double thirdExtent = DoubleVector3DTools::VectorMagnitude(thirdAxis);

		DoubleVector3D fourthAxis(firstAxis);
		DoubleVector3D fifthAxis(secondAxis);
		DoubleVector3D sixthAxis(thirdAxis);

		fourthAxis.Normalize();
		fifthAxis.Normalize();
		sixthAxis.Normalize();

		DoubleBox3 box(center,fourthAxis,fifthAxis,sixthAxis,firstExtent,secondExtent,thirdExtent);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(box.GetCenter(),center));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(box.GetAxis0(),fourthAxis));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(box.GetAxis1(),fifthAxis));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(box.GetAxis2(),sixthAxis));
		ASSERT_APPROXIMATE(box.GetExtent0(),firstExtent,1e-10);
		ASSERT_APPROXIMATE(box.GetExtent1(),secondExtent,1e-10);
		ASSERT_APPROXIMATE(box.GetExtent2(),thirdExtent,1e-10);

		vector<DoubleVector3D> vertex = box.ComputeVertices();

		ASSERT_TRUE(DoubleVector3DTools::Approximate(vertex[0],center - firstAxis - secondAxis - thirdAxis));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(vertex[1],center + firstAxis - secondAxis - thirdAxis));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(vertex[2],center + firstAxis + secondAxis - thirdAxis));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(vertex[3],center - firstAxis + secondAxis - thirdAxis));

		ASSERT_TRUE(DoubleVector3DTools::Approximate(vertex[4],center - firstAxis - secondAxis + thirdAxis));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(vertex[5],center + firstAxis - secondAxis + thirdAxis));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(vertex[6],center + firstAxis + secondAxis + thirdAxis));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(vertex[7],center - firstAxis + secondAxis + thirdAxis));
	}
}

