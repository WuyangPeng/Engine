// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/07/31 15:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateSolution.h"
#include "Detail/GenerateTemplateSolutionImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
 
AssistTools::GenerateTemplateSolution
	::GenerateTemplateSolution(const System::String& templateFileName, const System::String& projectName, const System::String& coreName)
	:impl(templateFileName,projectName,coreName)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools,GenerateTemplateSolution)

void AssistTools::GenerateTemplateSolution
	::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newCoreName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return impl->GenerateTo(resourceDirectory, solutionName, newCoreName);
}
