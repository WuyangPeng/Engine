// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:43)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateDllMain.h"
#include "Detail/GenerateTemplateDllMainImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h" 

AssistTools::GenerateTemplateDllMain
	::GenerateTemplateDllMain(const System::String& templateFileName,  const Replace& replace)
	:m_Impl(std::make_shared<ImplType>(templateFileName, replace))
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}  

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTemplateDllMain)

void AssistTools::GenerateTemplateDllMain
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData,  const System::String& solutionName, const System::String& managerName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GenerateTo(resourceDirectory, newProjectName, copyrightData, solutionName, managerName);
}
 