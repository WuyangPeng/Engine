// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:30)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_VCXPROJ_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_VCXPROJ_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTemplateVcxprojImpl);

namespace AssistTools
{
	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateVcxproj
	{
	public:
		PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTemplateVcxproj);

	public:
		GenerateTemplateVcxproj(const System::String& templateFileName, const System::String& solutionName, const System::String& includeName);

		CLASS_INVARIANT_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newIncludeName) const;

	private:
		PackageType impl;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_VCXPROJ_H
