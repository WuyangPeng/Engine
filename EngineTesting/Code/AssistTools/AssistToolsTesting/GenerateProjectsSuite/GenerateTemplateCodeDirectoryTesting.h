// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:07)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_CODE_DIRECTORY_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_CODE_DIRECTORY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "GenerateTemplateTesting.h"

namespace AssistTools
{
	class GenerateTemplateCodeDirectoryTesting : public GenerateTemplateTesting
    {
    public:
        using ClassType = GenerateTemplateCodeDirectoryTesting;
        using ParentType = GenerateTemplateTesting;

    public:
        explicit GenerateTemplateCodeDirectoryTesting(const OStreamShared& stream);
        CLASS_INVARIANT_OVERRIDE_DECLARE;
	private:
		void MainTest(); 		
		
		void GenerateToTest(); 
		void HeaderExistTest();
		void HelperExistToTest(const System::String& extension);
		void MessageExistToTest(const System::String& extension);
		void LibExistTest();
		void MainExistTest();
		void ManagerExistTest(const System::String& managerName);
		void ManagerHeaderExistTest(const System::String& managerName, const System::String& resultSuffix);
		void ManagerLibExistTest(const System::String& managerName);
		void DllMainExistTest(const System::String& managerName);
		void DllLibExistTest(const System::String& managerName);
		void MacroExistTest(const System::String& managerName, const System::String& resultSuffix);
		void ManagerEngineExistTest(const System::String& managerName);
		void InputManagerEngineExistTest();
		void CoreEngineExistTest();
		void EngineExistTest(const System::String& managerName, const System::String& resultSuffix);
		void MiddleLayerEngineExistTest(const System::String& managerName, const System::String& resultSuffix);
	
		virtual void DoRunUnitTest() override;			
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_CODE_DIRECTORY_TESTING_H