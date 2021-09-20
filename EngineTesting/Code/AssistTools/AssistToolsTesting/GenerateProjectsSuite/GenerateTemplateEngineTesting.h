// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:07)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "GenerateTemplateTesting.h"

namespace AssistTools
{
	class GenerateTemplateEngineTesting : public GenerateTemplateTesting
	{
        public:
            using ClassType = GenerateTemplateEngineTesting;
            using ParentType = GenerateTemplateTesting;

        public:
            explicit GenerateTemplateEngineTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
	private:
		void MainTest(); 		
		
		void GenerateToTest();
		void DefaultEventManagerHeaderGenerateToTest(const System::String& testFileName, const System::String& resultName); 
		void DefaultEventManagerCppGenerateToTest(const System::String& testFileName, const System::String& resultName);
		void DefaultInputManagerHeaderGenerateToTest(const System::String& testFileName, const System::String& resultName);
		void DefaultInputManagerCppGenerateToTest(const System::String& testFileName, const System::String& resultName);
	
		virtual void DoRunUnitTest() override;			
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_ENGINE_TESTING_H