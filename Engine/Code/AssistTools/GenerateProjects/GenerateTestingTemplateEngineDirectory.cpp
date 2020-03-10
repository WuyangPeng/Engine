// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateEngineDirectory.h" 
#include "Detail/GenerateTestingTemplateEngineDirectoryImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h" 

using std::string;
 
AssistTools::GenerateTestingTemplateEngineDirectory
	::GenerateTestingTemplateEngineDirectory(const System::String& directory, const string& configurationFileName)	 
	:m_Impl(new ImplType(directory, configurationFileName))
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
} 

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateEngineDirectory)

void AssistTools::GenerateTestingTemplateEngineDirectory
	::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName, 
			     const System::String& newIncludeName, const System::String& newTestingIncludeName,
				 const System::String& newDebugLibName, const System::String& newReleaseLibName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GenerateTo(resourceDirectory, newSolutionName, newCoreName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName);
}
