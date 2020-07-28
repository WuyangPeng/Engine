// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:44)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateLogJson.h"
#include "Detail/GenerateTemplateLogJsonImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
 
AssistTools::GenerateTemplateLogJson
	::GenerateTemplateLogJson(const System::String& templateFileName, const System::String& projectName)
	:m_Impl(std::make_shared<ImplType>(templateFileName, projectName))
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTemplateLogJson)

void AssistTools::GenerateTemplateLogJson
	::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newFileName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GenerateTo(resourceDirectory, solutionName, newFileName);
}
