// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:56)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_TRAPEZOID_RULE_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_TRAPEZOID_RULE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class TrapezoidRuleTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TrapezoidRuleTesting); 

	private:
		void MainTest();   
		void ValueTest();
		
		virtual void DoRunUnitTest() override;

		static double Solution(double input, const TrapezoidRuleTesting* userData);
		double  GetUserData() const;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_TRAPEZOID_RULE_TESTING_H