// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:10)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_MODULE_VCXPROJ_FILTERS_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_MODULE_VCXPROJ_FILTERS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "GenerateTemplateTesting.h"

namespace AssistTools
{
	class GenerateTemplateModuleVcxprojFiltersTesting : public GenerateTemplateTesting
	{
        public:
            using ClassType = GenerateTemplateModuleVcxprojFiltersTesting;
            using ParentType = GenerateTemplateTesting;

        public:
            explicit GenerateTemplateModuleVcxprojFiltersTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
	private:
		void MainTest(); 
		
		void GenerateToTest(); 
	
		virtual void DoRunUnitTest() override;			
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_MODULE_VCXPROJ_FILTERS_TESTING_H