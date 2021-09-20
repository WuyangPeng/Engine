// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/19 17:05)

#ifndef MATHEMATICS_ALGEBRA_SUITE_A_VECTOR_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_A_VECTOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class AVectorTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AVectorTesting); 

	private:
		void MainTest();	
		void ConstructionTest();
		void AccessTest();
		void ArithmeticCalculateTest();
		void VectorCalculateTest();
		void OtherCalculateTest();	

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_A_VECTOR_TESTING_H