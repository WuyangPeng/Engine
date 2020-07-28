// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:27)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_FILTERS_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_FILTERS_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateModuleVcxprojFiltersImpl : public GenerateTemplateImpl
	{
	public:
		typedef GenerateTemplateModuleVcxprojFiltersImpl ClassType;
		typedef GenerateTemplateImpl ParentType;

	public:
		GenerateTemplateModuleVcxprojFiltersImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& moduleName);
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newModuleName) const;

	private:
		static const System::String sm_Extension;
		System::String m_SolutionName;
		System::String m_ModuleName;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_FILTERS_IMPL_H
