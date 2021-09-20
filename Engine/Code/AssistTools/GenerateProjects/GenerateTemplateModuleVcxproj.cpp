// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateModuleVcxproj.h"
#include "Detail/GenerateTemplateModuleVcxprojImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
 
AssistTools::GenerateTemplateModuleVcxproj
	::GenerateTemplateModuleVcxproj(const System::String& templateFileName, const System::String& projectName, const System::String& moduleName, const System::String& includeName)
	:impl(templateFileName, projectName, moduleName, includeName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateModuleVcxproj)

void AssistTools::GenerateTemplateModuleVcxproj
	::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newModuleName, const System::String& newIncludeName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return impl->GenerateTo(resourceDirectory, solutionName, newModuleName, newIncludeName);
}
