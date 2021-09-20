// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:43)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateEngine.h"
#include "Detail/GenerateTemplateEngineImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
 
AssistTools::GenerateTemplateEngine
	::GenerateTemplateEngine(const System::String& templateFileName, const System::String& extension, const Replace& replace)
	:impl(templateFileName, extension,replace)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateEngine)

void AssistTools::GenerateTemplateEngine
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, 
	             const System::String& solutionName, const System::String& managerName,const System::String& interfaceName,
				 const System::String& projectCapital, const System::String& managerCapital) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return impl->GenerateTo(resourceDirectory, newProjectName, copyrightData, solutionName, managerName, interfaceName, projectCapital, managerCapital);
}
 