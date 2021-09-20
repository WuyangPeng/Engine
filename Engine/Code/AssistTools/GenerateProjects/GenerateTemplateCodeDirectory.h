// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:28)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_CODE_DIRECTORY_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_CODE_DIRECTORY_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Flags/GenerateTemplateReplaceFlags.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <string>
#include <map>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTemplateCodeDirectoryImpl);

namespace AssistTools
{
	class CopyrightData;

	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateCodeDirectory
	{
	public:
		PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTemplateCodeDirectory);

	public:
		GenerateTemplateCodeDirectory(const System::String& directory, const std::string& configurationFileName);

		CLASS_INVARIANT_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& projectName, const System::String& newCoreName, const System::String& CoreNameCapital) const;
			 
	private: 
		PackageType impl;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_CODE_DIRECTORY_H
