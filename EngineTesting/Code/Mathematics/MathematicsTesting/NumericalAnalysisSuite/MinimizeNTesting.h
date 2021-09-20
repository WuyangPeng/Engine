// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 13:53)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZEN_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZEN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <vector>

namespace Mathematics
{
	class MinimizeNTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MinimizeNTesting); 

	private:
		void MainTest(); 
		void GetMinimumTest();

		static double Function(const std::vector<double>& value, const MinimizeNTesting* minimize1Testing);
		double GetValue() const;
		
		virtual void DoRunUnitTest() override;		
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZEN_TESTING_H