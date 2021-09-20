// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑≤‚ ‘∞Ê±æ£∫0.0.0.1 (2019/10/05 21:30)

#ifndef SCENE_OBJECT_TESTING_HELPER_H
#define SCENE_OBJECT_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace SceneObject
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

#endif // SCENE_OBJECT_TESTING_HELPER_H
