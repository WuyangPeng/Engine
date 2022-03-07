// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 19:02)

#ifndef MATHEMATICS_CONTAINMENT_SUITE_CONT_BOX2_TESTING_H
#define MATHEMATICS_CONTAINMENT_SUITE_CONT_BOX2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class ContBox2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ContBox2Testing); 

	private:
		void MainTest();	
		void ContAlignedBoxTest();
		void ContOrientedBoxTest();
		void MergeBoxesTest();

		void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_CONTAINMENT_SUITE_CONT_BOX2_TESTING_H