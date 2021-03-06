// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:24)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MACRO_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MACRO_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateBaseImpl.h" 

namespace AssistTools
{ 
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateMacroImpl : public GenerateTemplateBaseImpl
	{
	public:
		using ClassType = GenerateTemplateMacroImpl ;
		using ParentType = GenerateTemplateBaseImpl ;

	public:
		GenerateTemplateMacroImpl(const System::String& templateFileName, const Replace& replace);
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, 
			            const System::String& solutionName, const System::String& managerName,
						const System::String& projectCapital,const System::String& managerCapital) const;

	private:
		static const System::String sm_Extension;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MACRO_IMPL_H
