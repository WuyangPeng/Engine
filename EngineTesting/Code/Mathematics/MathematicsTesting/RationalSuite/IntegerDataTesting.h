// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 09:55)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class IntegerDataTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IntegerDataTesting); 

	private:
		void MainTest();
		void CopyTest();	
		void BitTest();
		void ExceptionTest();
		void ConversionTest(); 
		void FloatingPointConversionTest();
		void ConversionExceptionTest();	
		void CompareTest();
	
		virtual void DoRunUnitTest() override;	
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_TESTING_H