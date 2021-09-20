// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BRENTS_METHOD_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BRENTS_METHOD_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class BrentsMethodTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BrentsMethodTesting); 

	private:
		void MainTest();
		void BaseTest();
        void HaveSolutionTest();
        void NoSolutionTest();
        void UnknownTest();
		
		virtual void DoRunUnitTest() override;	

		static double FirstSolution(double input, const BrentsMethodTesting* userData);
		static double SecondSolution(double input, const BrentsMethodTesting* userData);
		double GetUserData() const;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BRENTS_METHOD_TESTING_H