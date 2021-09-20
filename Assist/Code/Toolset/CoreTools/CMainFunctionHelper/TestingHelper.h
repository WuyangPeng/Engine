// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/03 22:49)

#ifndef C_MAIN_FUNCTION_HELPER_TESTING_HELPER_H
#define C_MAIN_FUNCTION_HELPER_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace CMainFunctionHelper
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = CMainFunctionTestingHelper;

	public:
		TestingHelper(int argc, char** argv);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		  int DoRun() override;
	};
}

#endif // C_MAIN_FUNCTION_HELPER_TESTING_HELPER_H