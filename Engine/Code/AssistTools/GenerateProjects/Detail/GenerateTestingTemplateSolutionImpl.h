// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_SOLUTION_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_SOLUTION_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
	class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTestingTemplateSolutionImpl : public GenerateTemplateImpl
	{
	public:
		typedef GenerateTestingTemplateSolutionImpl ClassType;
		typedef GenerateTemplateImpl ParentType;

	public:
		GenerateTestingTemplateSolutionImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& coreName);
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName) const;

	private: 
		static const System::String sm_Extension;

		System::String m_SolutionName;
		System::String m_CoreName;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_SOLUTION_IMPL_H
