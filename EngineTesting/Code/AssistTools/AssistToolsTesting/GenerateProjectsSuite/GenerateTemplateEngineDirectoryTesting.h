// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:07)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_DIRECTORY_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_DIRECTORY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "GenerateTemplateTesting.h"

namespace AssistTools
{
	class GenerateTemplateEngineDirectoryTesting : public GenerateTemplateTesting
	{
        public:
            using ClassType = GenerateTemplateEngineDirectoryTesting;
            using ParentType = GenerateTemplateTesting;

        public:
            explicit GenerateTemplateEngineDirectoryTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
	private:
		void MainTest(); 		
		
		void GenerateToTest(); 

		void SolutionExistTest(); 
		void VcxprojExistTest();
		void VcxprojFiltersExistTest();
		void ModuleVcxprojExistTest();
		void ModuleVcxprojFiltersExistTest(); 
		void LogJsonExistTest();
		void MiddleLayerExistTest(const System::String& managerName);
		void MiddleLayerVcxprojExistTest(const System::String& managerName);
		void MiddleLayerVcxprojFiltersExistTest(const System::String& managerName); 
		void EnvironmentVariableExistTest();
	
		virtual void DoRunUnitTest() override;			
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_DIRECTORY_TESTING_H