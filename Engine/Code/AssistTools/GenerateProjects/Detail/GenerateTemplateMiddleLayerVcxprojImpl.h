// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:27)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateMiddleLayerVcxprojImpl : public GenerateTemplateImpl
	{
	public:
		typedef GenerateTemplateMiddleLayerVcxprojImpl ClassType;
		typedef GenerateTemplateImpl ParentType;

	public:
		GenerateTemplateMiddleLayerVcxprojImpl(const System::String& templateFileName, const System::String& projectName, const System::String& managerName, const System::String& includeName);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newManagerName, const System::String& newIncludeName) const;

	private:
		static const System::String sm_Extension;

		System::String m_ProjectName;
		System::String m_ManagerName;
		System::String m_IncludeName;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_IMPL_H
