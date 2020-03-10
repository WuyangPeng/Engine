// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:43)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateCodeDirectory.h"
#include "Detail/GenerateTemplateCodeDirectoryImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"  

using std::string;
using std::make_shared;
 
AssistTools::GenerateTemplateCodeDirectory
	::GenerateTemplateCodeDirectory(const System::String& directory, const string& configurationFileName)	 
	:m_Impl{ make_shared<ImplType>(directory, configurationFileName) }
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
} 
 
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTemplateCodeDirectory)

void AssistTools::GenerateTemplateCodeDirectory
	::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& projectName, const System::String& newCoreName, const System::String& CoreNameCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GenerateTo(resourceDirectory, newSolutionName, copyrightData, projectCapital, projectName, newCoreName,CoreNameCapital);
}
 