// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 19:05)

#ifndef MATHEMATICS_MESHES_SUITE_EDGE_KEY_TESTING_H
#define MATHEMATICS_MESHES_SUITE_EDGE_KEY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class EdgeKeyTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(EdgeKeyTesting); 

	private:
		void MainTest();	
		void KeyTest();

		void DoRunUnitTest() override;
	};
}

#endif // MATHEMATICS_MESHES_SUITE_EDGE_KEY_TESTING_H