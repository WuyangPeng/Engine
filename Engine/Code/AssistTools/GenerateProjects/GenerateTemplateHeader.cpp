// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:43)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateHeader.h"
#include "Detail/GenerateTemplateHeaderImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"  
 
AssistTools::GenerateTemplateHeader
	::GenerateTemplateHeader(const System::String& templateFileName, const Replace& replace)
	:m_Impl(std::make_shared<ImplType>(templateFileName,replace)) 
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTemplateHeader)

void AssistTools::GenerateTemplateHeader
	::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;	 

	return m_Impl->GenerateTo(resourceDirectory, newSolutionName, copyrightData, projectCapital);
}
