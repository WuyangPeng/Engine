// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:24)

#ifndef RENDERING_SHADERS_SUITE_WIRE_STATE_TESTING_H
#define RENDERING_SHADERS_SUITE_WIRE_STATE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class WireStateTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(WireStateTesting); 

	private:
		void MainTest();
	    void InitTest(); 
		void CopyTest();
		void StreamTest();

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_SHADERS_SUITE_WIRE_STATE_TESTING_H