// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/30 19:04)

#include "ScribeCircle2CircumscribeTesting.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Containment/ScribeCircle2CircumscribeDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>

namespace Mathematics
{
	template class ScribeCircle2Circumscribe<float>;
	template class ScribeCircle2Circumscribe<double>;
}
#include SYSTEM_WARNING_DISABLE(26496)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, ScribeCircle2CircumscribeTesting) 

void Mathematics::ScribeCircle2CircumscribeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CircumscribeTest);
}

void Mathematics::ScribeCircle2CircumscribeTesting
	::CircumscribeTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector2 v0(firstRandomDistribution(generator),firstRandomDistribution(generator));
		Vector2 v1(firstRandomDistribution(generator),firstRandomDistribution(generator));
		Vector2 v2(firstRandomDistribution(generator),firstRandomDistribution(generator));

		ScribeCircle2CircumscribeD scribeCircle2Circumscribe(v0,v1,v2);
		
		if(scribeCircle2Circumscribe.IsCircleConstructed())
		{
			Circle2D circle = scribeCircle2Circumscribe.GetCircle2();

			ASSERT_APPROXIMATE(Vector2ToolsD::Distance(circle.GetCenter(),v0),circle.GetRadius(),1e-10);
			ASSERT_APPROXIMATE(Vector2ToolsD::Distance(circle.GetCenter(),v1),circle.GetRadius(),1e-10);
			ASSERT_APPROXIMATE(Vector2ToolsD::Distance(circle.GetCenter(),v2),circle.GetRadius(),1e-10);
		}
	}
}
