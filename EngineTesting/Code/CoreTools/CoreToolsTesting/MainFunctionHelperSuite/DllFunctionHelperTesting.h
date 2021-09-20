// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 17:05)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_DLL_FUNCTION_HELPER_TESTING_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_DLL_FUNCTION_HELPER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class DllFunctionHelperTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DllFunctionHelperTesting);

	private:
		void MainTest();
		void DllMutexTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_DLL_FUNCTION_HELPER_TESTING_H