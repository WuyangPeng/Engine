// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:37)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_DEFAULT_MEMORY_TESTING_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_DEFAULT_MEMORY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class DefaultMemoryTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DefaultMemoryTesting);

	private:
		void MainTest();
		void SingleTest();
		void Array1DTest();
		void Array2DTest();
		void Array3DTest();
		void Array4DTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUITE_DEFAULT_MEMORY_TESTING_H