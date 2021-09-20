// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 13:26)

#ifndef RENDERING_DATA_TYPES_SUITE_HALF_FLOAT_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_HALF_FLOAT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class HalfFloatTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(HalfFloatTesting); 

	private:
		void MainTest();
	    void BigFloatTest();
		void SmallFloatTest();
		void UInt16Test();
		void OperatorTest();

		virtual void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_DATA_TYPES_SUITE_HALF_FLOAT_TESTING_H