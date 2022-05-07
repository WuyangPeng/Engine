// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/19 17:08)

#ifndef MATHEMATICS_ALGEBRA_SUITE_QUATERNION_CONSTRAINTS_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_QUATERNION_CONSTRAINTS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class QuaternionConstraintsTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(QuaternionConstraintsTesting); 

	private:
		void MainTest();	
		void ConstraintsTest();
		
		void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_QUATERNION_CONSTRAINTS_TESTING_H