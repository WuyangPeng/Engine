// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:11)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "GenerateTemplateTesting.h"

namespace AssistTools
{
	class GenerateTestingTemplateCodeDirectoryTesting : public GenerateTemplateTesting
	{
        public:
            using ClassType = GenerateTestingTemplateCodeDirectoryTesting;
            using ParentType = GenerateTemplateTesting;

        public:
            explicit GenerateTestingTemplateCodeDirectoryTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
	private:
		void MainTest(); 		
		
		void GenerateToTest();  
		void ManagerExistTest(const System::String& managerName);
		void ManagerHeaderExistTest(const System::String& managerName, const System::String& resultName);
		void ManagerCppExistTest(const System::String& managerName, const System::String& resultName);
	
		void DoRunUnitTest() override;			
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_TESTING_H