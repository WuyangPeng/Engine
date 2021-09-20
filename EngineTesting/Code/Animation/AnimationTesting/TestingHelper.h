// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/09 19:22)

#ifndef ANIMATION_TESTING_TESTING_HELPER_H
#define ANIMATION_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace Animation
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 
	
		int DoRun() override;			

	private:
		void AddSuites();	

		void AddMacroSuite(); 
		void AddConsoleGraphSuite();
		void AddElfAnimationSuite();
		void AddTextureAnimationSuite();
		void AddRigidBodyHierarchyAnimationSuite();
		void AddSkeletonAnimationSuite();
		void AddPerVertexAnimationSuite();
		void AddMorphTargetAnimationSuite();
		void AddGradientAnimationSuite();
		void AddAnimationManagerSuite();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // ANIMATION_TESTING_TESTING_HELPER_H