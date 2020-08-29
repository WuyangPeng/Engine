// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_VCXPROJ_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_VCXPROJ_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTestingTemplateVcxprojImpl : public GenerateTemplateImpl
	{
	public:
		typedef GenerateTestingTemplateVcxprojImpl ClassType;
		typedef GenerateTemplateImpl ParentType;

	public:
		GenerateTestingTemplateVcxprojImpl(const System::String& templateFileName, const System::String& projectName, const System::String& moduleName, 
			                               const System::String& includeName, const System::String& testingIncludeName,
										   const System::String& debugLibName, const System::String& releaseLibName);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newModuleName, 
			            const System::String& newIncludeName, const System::String& newTestingIncludeName,
						const System::String& newDebugLibName, const System::String& newReleaseLibName) const;

	private:
		static const System::String sm_Extension;

		System::String m_ProjectName;
		System::String m_ModuleName;
		System::String m_IncludeName;
		System::String m_TestingIncludeName;
		System::String m_DebugLibName;
		System::String m_ReleaseLibName;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_VCXPROJ_IMPL_H
