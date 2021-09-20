// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateMiddleLayerVcxprojFilters.h"
#include "Detail/GenerateTemplateMiddleLayerVcxprojFiltersImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
 
AssistTools::GenerateTemplateMiddleLayerVcxprojFilters
	::GenerateTemplateMiddleLayerVcxprojFilters(const System::String& templateFileName, const System::String& projectName, const System::String& managerName)
	:impl(templateFileName, projectName, managerName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateMiddleLayerVcxprojFilters)

void AssistTools::GenerateTemplateMiddleLayerVcxprojFilters
	::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newManagerName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return impl->GenerateTo(resourceDirectory, solutionName, newManagerName);
}
