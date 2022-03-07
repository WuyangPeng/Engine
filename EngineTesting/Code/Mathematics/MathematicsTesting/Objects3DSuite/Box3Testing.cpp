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
#include "Mathematics/Algebra/Vector3Tools.h"

using std::vector;
using std::uniform_real;
using std::default_random_engine;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
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
		Vector3D center(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		Vector3D firstAxis(firstRandomDistribution(generator),
			                firstRandomDistribution(generator),
							firstRandomDistribution(generator));

		Vector3D secondAxis(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		Vector3D thirdAxis(firstRandomDistribution(generator),
			                 firstRandomDistribution(generator),
							 firstRandomDistribution(generator));

		double firstExtent = Vector3ToolsD::GetLength(firstAxis);
		double secondExtent = Vector3ToolsD::GetLength(secondAxis);
		double thirdExtent = Vector3ToolsD::GetLength(thirdAxis);

		Vector3D fourthAxis(firstAxis);
		Vector3D fifthAxis(secondAxis);
		Vector3D sixthAxis(thirdAxis);

		fourthAxis.Normalize();
		fifthAxis.Normalize();
		sixthAxis.Normalize();

		Box3D box(center,fourthAxis,fifthAxis,sixthAxis,firstExtent,secondExtent,thirdExtent);

		ASSERT_TRUE(Vector3ToolsD::Approximate(box.GetCenter(),center));
		ASSERT_TRUE(Vector3ToolsD::Approximate(box.GetAxis0(),fourthAxis));
		ASSERT_TRUE(Vector3ToolsD::Approximate(box.GetAxis1(),fifthAxis));
		ASSERT_TRUE(Vector3ToolsD::Approximate(box.GetAxis2(),sixthAxis));
		ASSERT_APPROXIMATE(box.GetExtent0(),firstExtent,1e-10);
		ASSERT_APPROXIMATE(box.GetExtent1(),secondExtent,1e-10);
		ASSERT_APPROXIMATE(box.GetExtent2(),thirdExtent,1e-10);

		vector<Vector3D> vertex = box.ComputeVertices();

		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[0],center - firstAxis - secondAxis - thirdAxis));
		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[1],center + firstAxis - secondAxis - thirdAxis));
		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[2],center + firstAxis + secondAxis - thirdAxis));
		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[3],center - firstAxis + secondAxis - thirdAxis));

		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[4],center - firstAxis - secondAxis + thirdAxis));
		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[5],center + firstAxis - secondAxis + thirdAxis));
		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[6],center + firstAxis + secondAxis + thirdAxis));
		ASSERT_TRUE(Vector3ToolsD::Approximate(vertex[7],center - firstAxis + secondAxis + thirdAxis));
	}
}

