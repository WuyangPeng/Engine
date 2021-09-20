// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 13:26)

#ifndef RENDERING_DATA_TYPES_SUITE_TRANSFORM_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_TRANSFORM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class TransformTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TransformTesting); 

	private:
		void MainTest();
	    void BaseTest();
	    void OperatorTest();
	    void InverseTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_DATA_TYPES_SUITE_TRANSFORM_TESTING_H