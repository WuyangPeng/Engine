// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/30 19:02)

#ifndef MATHEMATICS_CONTAINMENT_SUITE_SCRIBE_CIRCLE2_CIRCUMSCRIBE_TESTING_H
#define MATHEMATICS_CONTAINMENT_SUITE_SCRIBE_CIRCLE2_CIRCUMSCRIBE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class ScribeCircle2CircumscribeTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ScribeCircle2CircumscribeTesting); 

	private:
		void MainTest();	
		void CircumscribeTest();

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_CONTAINMENT_SUITE_SCRIBE_CIRCLE2_CIRCUMSCRIBE_TESTING_H