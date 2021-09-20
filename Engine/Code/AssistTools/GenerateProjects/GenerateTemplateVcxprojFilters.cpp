// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateVcxprojFilters.h"
#include "Detail/GenerateTemplateVcxprojFiltersImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
 
AssistTools::GenerateTemplateVcxprojFilters
	::GenerateTemplateVcxprojFilters(const System::String& templateFileName, const System::String& solutionName)
	:impl(templateFileName, solutionName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateVcxprojFilters)

void AssistTools::GenerateTemplateVcxprojFilters
	::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return impl->GenerateTo(resourceDirectory, newSolutionName);
}
