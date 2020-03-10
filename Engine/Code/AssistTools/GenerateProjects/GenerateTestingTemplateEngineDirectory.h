// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:31)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h" 

#include <string> 

ASSIST_TOOLS_EXPORT_SHARED_PTR(GenerateTestingTemplateEngineDirectoryImpl);

namespace AssistTools
{
	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTestingTemplateEngineDirectory
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(GenerateTestingTemplateEngineDirectory);

	public:
		GenerateTestingTemplateEngineDirectory(const System::String& directory, const std::string& configurationFileName); 

		CLASS_INVARIANT_DECLARE;

		void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName, 
			            const System::String& newIncludeName, const System::String& newTestingIncludeName,
						const System::String& newDebugLibName, const System::String& newReleaseLibName) const;
	private:
		IMPL_TYPE_DECLARE(GenerateTestingTemplateEngineDirectory);		 
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_H
