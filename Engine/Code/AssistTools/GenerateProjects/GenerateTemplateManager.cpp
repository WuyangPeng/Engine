// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:47)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateManager.h"
#include "Detail/GenerateTemplateManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"   
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h"  
 
AssistTools::GenerateTemplateManager
	::GenerateTemplateManager(const System::String& templateFileName, const Replace& replace)
	:m_Impl(std::make_shared<ImplType>(templateFileName,replace))
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTemplateManager)

void AssistTools::GenerateTemplateManager
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& managerCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GenerateTo(resourceDirectory, newProjectName, copyrightData, projectCapital, managerCapital);
}
