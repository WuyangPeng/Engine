// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/02 13:08)

#ifndef RESOURCE_MANAGER_TESTING_TESTING_HELPER_H
#define RESOURCE_MANAGER_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace ResourceManager
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

		virtual int DoRun() override;

	private:
                void AddSuites();	

		void AddMacroSuite(); 
		void AddThreeDimensionalModelSuite();
		void AddTextureSuite();
		void AddMaterialSuite();
		void AddFontSuite();
		void AddSkeletonSuite();
		void AddCollisionSuite();
		void AddPhysicalParametersSuite();
		void AddGameWorldMapSuite();
		void AddMiscellaneousSuite();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // RESOURCE_MANAGER_TESTING_TESTING_HELPER_H