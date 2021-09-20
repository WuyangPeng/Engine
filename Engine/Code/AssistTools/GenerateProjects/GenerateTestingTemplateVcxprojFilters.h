// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:31)

#ifndef ASSIST_TOOLS_GENERATE_PROJECT_SGENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_H
#define ASSIST_TOOLS_GENERATE_PROJECT_SGENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTestingTemplateVcxprojFiltersImpl);

namespace AssistTools
{
	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTestingTemplateVcxprojFilters
	{
	public:
		PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTestingTemplateVcxprojFilters);

	public:
		GenerateTestingTemplateVcxprojFilters(const System::String& templateFileName, const System::String& projectName, const System::String& moduleName);

		CLASS_INVARIANT_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const System::String& newModuleName) const;

	private:
		PackageType impl;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECT_SGENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_IMPL_H
