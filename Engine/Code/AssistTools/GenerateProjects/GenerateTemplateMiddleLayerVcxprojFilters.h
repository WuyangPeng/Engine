// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:30)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_FILTERS_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_FILTERS_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTemplateMiddleLayerVcxprojFiltersImpl);

namespace AssistTools
{
	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateMiddleLayerVcxprojFilters
	{
	public:
		PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTemplateMiddleLayerVcxprojFilters);

	public:
		GenerateTemplateMiddleLayerVcxprojFilters(const System::String& templateFileName, const System::String& projectName, const System::String& managerName);

		CLASS_INVARIANT_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newManagerName) const;

	private:
		PackageType impl;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_FILTERS_H
