// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 09:55)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_ANALYSIS_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_ANALYSIS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class IntegerDataAnalysisTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IntegerDataAnalysisTesting); 

	private:
		void MainTest();
		void ToUnsignedIntTest();
		void GetLeadingBitTest();
		void GetTrailingBitTest();
		void OperatorTest();
		void DivisionModuloTest();
	
		virtual void DoRunUnitTest() override;	
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_ANALYSIS_TESTING_H