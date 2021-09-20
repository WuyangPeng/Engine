// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.2 (2019/09/28 16:44)

#ifndef BOOK_RENDERING_TECHNOLOGY_TESTING_HELPER_H
#define BOOK_RENDERING_TECHNOLOGY_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookRenderingTechnology
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 		 

		void AddGPUGemsSuite();

		void AddGPUGemsProgrammingTechniquesTipsAndTricksForRealTimeGraphicsSuite(Suite& gpuGemsSuite);

		void AddGPUGemsProgrammingTechniquesForHighPerformanceGraphicsAndGeneralPurposeComputationSuite(Suite& gpuGemsSuite);

		void AddGPUGems3Suite(Suite& gpuGemsSuite);

		void AddGraphicsShadersSuite();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_RENDERING_TECHNOLOGY_TESTING_HELPER_H