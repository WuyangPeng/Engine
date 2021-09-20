// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:44)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateLib.h"
#include "Detail/GenerateTemplateLibImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"  
 
AssistTools::GenerateTemplateLib
	::GenerateTemplateLib(const System::String& templateFileName, const Replace& replace)
	:impl(templateFileName,replace)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateLib)

void AssistTools::GenerateTemplateLib
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData,const System::String& solutionName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;	 

	return impl->GenerateTo(resourceDirectory, newProjectName, copyrightData, solutionName);
}
