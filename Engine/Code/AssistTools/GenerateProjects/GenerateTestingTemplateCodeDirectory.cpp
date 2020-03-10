// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateCodeDirectory.h"
#include "Detail/GenerateTestingTemplateCodeDirectoryImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "System/Helper/UnicodeUsing.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"

using  std::string;
 
AssistTools::GenerateTestingTemplateCodeDirectory
	::GenerateTestingTemplateCodeDirectory(const System::String& directory, const string& configurationFileName)
	:m_Impl(new ImplType(directory, configurationFileName))
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
} 

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateCodeDirectory)

void AssistTools::GenerateTestingTemplateCodeDirectory
	::GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData,const System::String& projectCapital, const System::String& newCoreName, const System::String& CoreNameCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GenerateTo(exportDirectory, newSolutionName, copyrightData, projectCapital, newCoreName, CoreNameCapital);
}
 