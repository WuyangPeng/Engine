// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 15:47)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateMain.h"
#include "Detail/GenerateTemplateMainImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"  
 
AssistTools::GenerateTemplateMain
	::GenerateTemplateMain(const System::String& templateFileName, const Replace& replace)
	:m_Impl(std::make_shared<ImplType>(templateFileName,replace))
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(AssistTools, GenerateTemplateMain)

void AssistTools::GenerateTemplateMain
	::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData,const System::String& solutionName,const System::String& projectName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;	 

	return m_Impl->GenerateTo(resourceDirectory, newProjectName, copyrightData, solutionName, projectName);
}
