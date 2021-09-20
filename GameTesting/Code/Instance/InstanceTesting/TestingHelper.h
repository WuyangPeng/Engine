// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑≤‚ ‘∞Ê±æ£∫0.0.0.1 (2019/10/06 21:14)

#ifndef INSTANCE_TESTING_HELPER_H
#define INSTANCE_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace Instance
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // INSTANCE_TESTING_HELPER_H
