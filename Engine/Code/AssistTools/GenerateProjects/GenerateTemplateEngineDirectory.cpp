// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:43)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateEngineDirectory.h"
#include "Detail/GenerateTemplateEngineDirectoryImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"  

using std::string;
 
AssistTools::GenerateTemplateEngineDirectory
	::GenerateTemplateEngineDirectory(const System::String& directory, const string& configurationFileName)	 
	:m_Impl(std::make_shared<ImplType>(directory, configurationFileName))
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
} 
 
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTemplateEngineDirectory)

void AssistTools::GenerateTemplateEngineDirectory
	::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName, const System::String& newIncludeName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GenerateTo(resourceDirectory, newSolutionName, newCoreName, newIncludeName);
}
 