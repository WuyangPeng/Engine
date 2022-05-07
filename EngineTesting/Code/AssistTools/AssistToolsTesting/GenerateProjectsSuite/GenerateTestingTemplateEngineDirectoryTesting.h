// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:11)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "GenerateTemplateTesting.h"

namespace AssistTools
{
	class GenerateTestingTemplateEngineDirectoryTesting : public GenerateTemplateTesting
	{
        public:
            using ClassType = GenerateTestingTemplateEngineDirectoryTesting;
            using ParentType = GenerateTemplateTesting;

        public:
            explicit GenerateTestingTemplateEngineDirectoryTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
	private:
		void MainTest(); 		
		
		void GenerateToTest(); 
		void SolutionExistTest();  
		void ModuleExistTest(const System::String& managerName);
		void VcxprojExistTest(const System::String& managerName);
		void VcxprojFiltersExistTest(const System::String& managerName); 
		void LogJsonExistTest(const System::String& managerName);
		void TestingJsonExistTest(const System::String& managerName);
		void EnvironmentVariableExistTest(const System::String& managerName);
	
		void DoRunUnitTest() override;			
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_TESTING_H