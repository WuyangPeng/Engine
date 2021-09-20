// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:11)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_ENGINE_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_ENGINE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "GenerateTemplateTesting.h"

namespace AssistTools
{
	class GenerateTestingTemplateEngineTesting : public GenerateTemplateTesting
	{
        public:
            using ClassType = GenerateTestingTemplateEngineTesting;
            using ParentType = GenerateTemplateTesting;

        public:
            explicit GenerateTestingTemplateEngineTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
	private:
		void MainTest(); 		
		
		void GenerateToTest();
		void DefaultManagerHeaderGenerateToTest(const System::String& testFileName, const System::String& resultName); 
		void DefaultManagerCppGenerateToTest(const System::String& testFileName, const System::String& resultName); 
	
		virtual void DoRunUnitTest() override;			
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TESTING_TEMPLATE_ENGINE_TESTING_H