// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:37)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_MD5_CONTEXT_TESTING_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_MD5_CONTEXT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class MD5ContextTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MD5ContextTesting);

	private:
		void MainTest();
		void MD5Test();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUITE_MD5_CONTEXT_TESTING_H