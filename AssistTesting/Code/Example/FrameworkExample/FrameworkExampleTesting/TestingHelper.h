// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.3 (2020/05/01 14:23)

#ifndef FRAMEWORK_EXAMPLE_TESTING_HELPER_H
#define FRAMEWORK_EXAMPLE_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace FrameworkExample
{
	class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = CMainFunctionTestingHelper;

	public:
		TestingHelper(int argc, char** argv);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void InitSuite() noexcept;
	};
}

#endif // FRAMEWORK_EXAMPLE_TESTING_HELPER_H
