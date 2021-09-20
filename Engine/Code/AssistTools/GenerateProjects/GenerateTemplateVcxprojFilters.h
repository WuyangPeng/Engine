// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:30)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_VCXPROJ_FILTERS_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_VCXPROJ_FILTERS_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTemplateVcxprojFiltersImpl);

namespace AssistTools
{
	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateVcxprojFilters
	{
	public:
		PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTemplateVcxprojFilters);

	public:
		GenerateTemplateVcxprojFilters(const System::String& templateFileName, const System::String& solutionName);

		CLASS_INVARIANT_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName) const;

	private:
		PackageType impl;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_VCXPROJ_FILTERS_H
