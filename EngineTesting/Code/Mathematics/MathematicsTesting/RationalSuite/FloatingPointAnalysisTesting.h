// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 09:54)

#ifndef MATHEMATICS_RATIONAL_SUITE_FLOATING_POINT_ANALYSIS_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_FLOATING_POINT_ANALYSIS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class FloatingPointAnalysisTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FloatingPointAnalysisTesting); 

	private:
		void MainTest();
		void NumericalValueSymbolTest();
		void ExponentTest();
		void MantissaTest();
		void FloatTypeTest();
		void DoubleTypeTest();
	
		virtual void DoRunUnitTest() override;	 
	};
}

#endif // MATHEMATICS_RATIONAL_SUITE_FLOATING_POINT_ANALYSIS_TESTING_H