// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/23 09:56)

#ifndef MATHEMATICS_RATIONAL_SUITE_RATIONAL_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_RATIONAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class RationalTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(RationalTesting); 

	private:
		void MainTest();
		void ConstructionTest();
		void AccessTest();
		void OperatorTest();
		void CompareTest();
		void EliminatePowersOfTwoTest();
	
		virtual void DoRunUnitTest() override;
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_RATIONAL_TESTING_H