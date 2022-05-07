// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.4 (2019/09/10 10:10)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_MANAGER_VCXPROJ_FILTERS_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_MANAGER_VCXPROJ_FILTERS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "GenerateTemplateTesting.h"

namespace AssistTools
{
	class GenerateTemplateMiddleLayerVcxprojFiltersTesting : public GenerateTemplateTesting
	{
        public:
            using ClassType = GenerateTemplateMiddleLayerVcxprojFiltersTesting;
            using ParentType = GenerateTemplateTesting;

        public:
            explicit GenerateTemplateMiddleLayerVcxprojFiltersTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
	private:
		void MainTest(); 
		
		void GenerateToTest(); 
	
		void DoRunUnitTest() override;			
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_INPUT_MANAGER_VCXPROJ_FILTERS_TESTING_H