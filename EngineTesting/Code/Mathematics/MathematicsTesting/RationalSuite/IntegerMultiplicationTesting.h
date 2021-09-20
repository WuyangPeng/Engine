// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 09:56)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_MULTIPLICATION_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_MULTIPLICATION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class IntegerMultiplicationTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IntegerMultiplicationTesting); 

	private:
		void MainTest();
		void MultiplicationTest();
	
		virtual void DoRunUnitTest() override;
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_INTEGER_MULTIPLICATION_TESTING_H