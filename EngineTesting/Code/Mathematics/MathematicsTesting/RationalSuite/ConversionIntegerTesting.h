// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/23 09:54)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_CONVERSION_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_CONVERSION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class ConversionIntegerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ConversionIntegerTesting); 

	private:
		void MainTest();
		void NumericalValueSymbolTest();
		void ExponentTest();
		void MantissaTest();
		void IntegerTest();
		void UnsignedIntegerTest();
	
		void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_INTEGER_CONVERSION_TESTING_H