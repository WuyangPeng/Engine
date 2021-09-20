// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 09:56)

#ifndef MATHEMATICS_RATIONAL_SUITE_RATIONAL_CONVERSION_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_RATIONAL_CONVERSION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class RationalConversionTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(RationalConversionTesting); 

	private:
		void MainTest();
		void FloatingPointTest();
		void IntegerTest();
		void UnsignedIntegerTest();
		void FloatOverflowTest();
		void DoubleOverflowTest();
		void IntegerOverflowTest();
		void UnsignedIntegerOverflowTest();
	
		virtual void DoRunUnitTest() override;	
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_RATIONAL_CONVERSION_TESTING_H