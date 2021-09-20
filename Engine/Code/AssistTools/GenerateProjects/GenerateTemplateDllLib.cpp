// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:43)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateDllLib.h"
#include "Detail/GenerateTemplateDllLibImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h" 
 
AssistTools::GenerateTemplateDllLib
	::GenerateTemplateDllLib(const System::String& templateFileName,  const Replace& replace)
	:impl(templateFileName, replace)
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
} 

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateDllLib)

void AssistTools::GenerateTemplateDllLib
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData,  const System::String& solutionName, const System::String& managerName,const System::String& managerChineseName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	return impl->GenerateTo(resourceDirectory, newProjectName, copyrightData, solutionName,managerName,managerChineseName);
}
 