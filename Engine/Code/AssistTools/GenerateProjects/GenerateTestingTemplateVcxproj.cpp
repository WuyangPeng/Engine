// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:49)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateVcxproj.h"
#include "Detail/GenerateTestingTemplateVcxprojImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"    
 
AssistTools::GenerateTestingTemplateVcxproj
	::GenerateTestingTemplateVcxproj(const System::String& templateFileName, const System::String& projectName, const System::String& moduleName,
                                     const System::String& includeName, const System::String& testingIncludeName,
									 const System::String& debugLibName, const System::String& releaseLibName)
	:impl(templateFileName,projectName,moduleName,includeName,testingIncludeName,debugLibName,releaseLibName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTestingTemplateVcxproj)

void AssistTools::GenerateTestingTemplateVcxproj
	::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newModuleName, const System::String& newIncludeName, 
                 const System::String& newTestingIncludeName,const System::String& newDebugLibName, const System::String& newReleaseLibName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return impl->GenerateTo(resourceDirectory, solutionName, newModuleName,newIncludeName,newTestingIncludeName,newDebugLibName,newReleaseLibName);
}
  