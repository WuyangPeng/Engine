// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:31)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h" 

#include <string> 

ASSIST_TOOLS_EXPORT_SHARED_PTR(GenerateTestingTemplateCodeDirectoryImpl);

namespace AssistTools
{ 
	class CopyrightData;

	class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTestingTemplateCodeDirectory 
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(GenerateTestingTemplateCodeDirectory);

	public:
		GenerateTestingTemplateCodeDirectory(const System::String& directory, const std::string& configurationFileName); 

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData,const System::String& projectCapital, const System::String& newCoreName, const System::String& CoreNameCapital) const;	 
	
	private:
		IMPL_TYPE_DECLARE(GenerateTestingTemplateCodeDirectory);
	};
} 
#endif // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_H
