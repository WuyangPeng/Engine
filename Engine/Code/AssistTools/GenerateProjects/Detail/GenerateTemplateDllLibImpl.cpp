// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 15:33)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateDllLibImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String AssistTools::GenerateTemplateDllLibImpl
	::sm_Extension(SYSTEM_TEXT(".cpp"));
 #include STSTEM_WARNING_POP
AssistTools::GenerateTemplateDllLibImpl
	::GenerateTemplateDllLibImpl(const System::String& templateFileName,  const Replace& replace)
	:ParentType(templateFileName, sm_Extension,replace) 
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateDllLibImpl)

void AssistTools::GenerateTemplateDllLibImpl
	::GenerateTo(const System::String& exportDirectory, const System::String& newProjectName, const CopyrightData& copyrightData,  const System::String& solutionName, const System::String& managerName,const System::String& managerChineseName) const
{
	ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

	VariableType newVariable = GetCopyrightVariable(copyrightData);
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ManagerName), managerName));
	newVariable.insert(make_pair(GetOriginal(GenerateTemplateReplace::ManagerChineseName), managerChineseName));

	return ParentType::Generate(exportDirectory, newProjectName, newVariable);
}

/*
示例模板： 
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%版本：%Versions% (%Date% %Hour%:%Minute%)

// %ManagerChineseName%管理器包含以下模块：
// 1.   Macro（宏）
// 2.   Engine（引擎）

#include "%SolutionName%%ManagerName%Export.h"

#include "%SolutionName%%ManagerName%.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"
*/