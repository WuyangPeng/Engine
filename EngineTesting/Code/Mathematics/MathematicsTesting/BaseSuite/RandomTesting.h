// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 12:49)

#ifndef MATHEMATICS_BASE_SUITE_RANDOM_TESTING_H
#define MATHEMATICS_BASE_SUITE_RANDOM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class RandomTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(RandomTesting); 

	private:
		void MainTest();	
		
		// Random≤‚ ‘
		void FloatRandomTest();
		void DoubleRandomTest();		

		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_BASE_SUITE_RANDOM_TESTING_H