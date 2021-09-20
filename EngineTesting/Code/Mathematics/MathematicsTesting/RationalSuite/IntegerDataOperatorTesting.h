// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 09:55)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_OPERATOR_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_OPERATOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class IntegerDataOperatorTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IntegerDataOperatorTesting); 

	private:
		void MainTest();
		void AdditionTest();
		void SubtractionTest();
		void MultiplicationTest();
		void LeftShiftTest();
		void RightShiftTest();
		void DivisionModuloTest();
	
		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_OPERATOR_TESTING_H