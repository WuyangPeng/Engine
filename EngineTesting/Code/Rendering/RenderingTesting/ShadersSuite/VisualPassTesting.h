// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:24)

#ifndef RENDERING_SHADERS_SUITE_VISUAL_PASS_TESTING_H
#define RENDERING_SHADERS_SUITE_VISUAL_PASS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class VisualPassTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(VisualPassTesting); 

	private:
		void MainTest();
	    void InitTest(); 
		void CopyTest();
		void StreamTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SHADERS_SUITE_VISUAL_PASS_TESTING_H