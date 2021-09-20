// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 16:06)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_GUASS_POINTS_FIT3_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_GUASS_POINTS_FIT3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class GaussPointsFit3Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(GaussPointsFit3Testing); 

	private:
		void MainTest();	
		void FitTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_APPROXIMATION_SUITE_GUASS_POINTS_FIT3_TESTING_H