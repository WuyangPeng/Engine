// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:43)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateHelper.h"
#include "Detail/GenerateTemplateHelperImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"  
 
AssistTools::GenerateTemplateHelper
	::GenerateTemplateHelper(const System::String& templateFileName,const System::String& extension,  const Replace& replace)
	:m_Impl(new ImplType(templateFileName, extension,replace))
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTemplateHelper)

void AssistTools::GenerateTemplateHelper
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital,const System::String& solutionName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;	 

	return m_Impl->GenerateTo(resourceDirectory, newProjectName, copyrightData, projectCapital, solutionName);
}
