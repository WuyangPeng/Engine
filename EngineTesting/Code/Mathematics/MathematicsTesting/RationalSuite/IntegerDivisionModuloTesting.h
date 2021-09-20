// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/23 09:55)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_DIVISION_MODULO_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_DIVISION_MODULO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class IntegerDivisionModuloTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IntegerDivisionModuloTesting); 

	private:
		void MainTest();
		void DenominatorIsLargeTest();
		void SingleTest();
		void MultipleTest();
		void Int32Test();
	
		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_INTEGER_DIVISION_MODULO_TESTING_H