// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:31)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_SOLUTION_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_SOLUTION_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

ASSIST_TOOLS_EXPORT_SHARED_PTR(GenerateTestingTemplateSolutionImpl);

namespace AssistTools
{
	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTestingTemplateSolution
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(GenerateTestingTemplateSolution);

	public:
		GenerateTestingTemplateSolution(const System::String& templateFileName, const System::String& projectName, const System::String& coreName);

		CLASS_INVARIANT_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newCoreName) const;

	private:
		IMPL_TYPE_DECLARE(GenerateTestingTemplateSolution);
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_SOLUTION_H
