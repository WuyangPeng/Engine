// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:49)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateVcxprojFilters.h"
#include "Detail/GenerateTestingTemplateVcxprojFiltersImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "System/Helper/UnicodeUsing.h"
 
AssistTools::GenerateTestingTemplateVcxprojFilters
	::GenerateTestingTemplateVcxprojFilters(const System::String& templateFileName, const System::String& projectName,const System::String& moduleName)
	:m_Impl(new ImplType(templateFileName, projectName, moduleName))
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
} 

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateVcxprojFilters)

void AssistTools::GenerateTestingTemplateVcxprojFilters
	::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName,const System::String& newModuleName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GenerateTo(resourceDirectory, solutionName, newModuleName);
}
 