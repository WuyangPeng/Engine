// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/29 17:48)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT2_HYPERBOLA2_TESTING_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT2_HYPERBOLA2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class DistancePoint2Hyperbola2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DistancePoint2Hyperbola2Testing); 

	private:
		void MainTest();		
		void BaseTest();
		void StaticTest();
		void DynamicTest();
		void DerivativeTest();
		void IntervalTest();

		void DoRunUnitTest() override;
	};
}

#endif // MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT2_HYPERBOLA2_TESTING_H