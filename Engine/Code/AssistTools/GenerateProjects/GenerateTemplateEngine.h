// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:29)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Flags/GenerateTemplateReplaceFlags.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <string>
#include <map>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTemplateEngineImpl);

namespace AssistTools
{ 
	class CopyrightData;

	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateEngine
	{
	public:
		PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTemplateEngine);
		typedef std::map<GenerateTemplateReplace, System::String> Replace;

	public:
		GenerateTemplateEngine(const System::String& templateFileName, const System::String& extension, const Replace& replace);

		CLASS_INVARIANT_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, 
			            const System::String& solutionName, const System::String& managerName,const System::String& interfaceName,
						const System::String& projectCapital,const System::String& managerCapital) const;

	private:
		PackageType impl;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_H
