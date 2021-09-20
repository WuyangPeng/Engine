// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 16:40)

#ifndef RENDERING_DETAIL_SUITE_SWITCH_NODE_TESTING_H
#define RENDERING_DETAIL_SUITE_SWITCH_NODE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class SwitchNodeTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SwitchNodeTesting); 

	private:
		void MainTest();
	    void InitTest();
	    void CopyTest();
	    void TransformTest();
	    void ChildTest();
	    void StreamTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // RENDERING_DETAIL_SUITE_SWITCH_NODE_TESTING_H