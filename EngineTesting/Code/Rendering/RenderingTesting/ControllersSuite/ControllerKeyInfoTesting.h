// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 14:54)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_KEY_INFO_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_KEY_INFO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class ControllerKeyInfoTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ControllerKeyInfoTesting); 

	private:
		void MainTest();
		void InitTest();	 

		void DoRunUnitTest() override;
	};
}

#endif // RENDERING_CONTROLLERS_SUITE_CONTROLLER_KEY_INFO_TESTING_H