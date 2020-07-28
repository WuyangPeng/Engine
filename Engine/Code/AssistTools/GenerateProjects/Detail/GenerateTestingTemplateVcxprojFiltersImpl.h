// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECT_SGENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECT_SGENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTestingTemplateVcxprojFiltersImpl : public GenerateTemplateImpl
	{
	public:
		typedef GenerateTestingTemplateVcxprojFiltersImpl ClassType;
		typedef GenerateTemplateImpl ParentType;

	public:
		GenerateTestingTemplateVcxprojFiltersImpl(const System::String& templateFileName, const System::String& projectName,const System::String& moduleName);
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const System::String& newModuleName) const;

	private:
		static const System::String sm_Extension;
		System::String m_ProjectName;
		System::String m_ModuleName;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECT_SGENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_IMPL_H
