// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateVcxprojFilters.h"
#include "Detail/GenerateTemplateVcxprojFiltersImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
 
AssistTools::GenerateTemplateVcxprojFilters
	::GenerateTemplateVcxprojFilters(const System::String& templateFileName, const System::String& solutionName)
	:m_Impl(std::make_shared<ImplType>(templateFileName, solutionName))
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTemplateVcxprojFilters)

void AssistTools::GenerateTemplateVcxprojFilters
	::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GenerateTo(resourceDirectory, newSolutionName);
}
