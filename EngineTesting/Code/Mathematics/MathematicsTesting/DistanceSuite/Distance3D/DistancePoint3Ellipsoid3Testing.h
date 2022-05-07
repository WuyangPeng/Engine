// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/29 17:49)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT3_ELLIPSOID3_TESTING_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT3_ELLIPSOID3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class DistancePoint3Ellipsoid3Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DistancePoint3Ellipsoid3Testing); 

	private:
		void MainTest();
		void BaseTest();
		void StaticDistanceTest();
		void DynamicDistanceTest();
		void DerivativeDistanceTest();
		void IntervalDistanceTest();
		
		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT3_ELLIPSOID3_TESTING_H