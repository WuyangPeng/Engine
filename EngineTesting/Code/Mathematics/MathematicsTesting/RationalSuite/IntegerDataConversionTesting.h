// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 09:55)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_CONVERSION_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_CONVERSION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class IntegerDataConversionTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IntegerDataConversionTesting); 

	private:
		void MainTest();
		void FloatingPointTest();
		void IntegerTest();
		void UnsignedIntegerTest();
		void FloatOverflowTest();
		void DoubleOverflowTest();
		void IntegerOverflowTest();
		void UnsignedIntegerOverflowTest();
	
		void DoRunUnitTest() override;	
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_CONVERSION_TESTING_H