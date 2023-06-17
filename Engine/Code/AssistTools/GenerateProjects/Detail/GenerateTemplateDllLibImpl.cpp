///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 10:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateDllLibImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

const System::String AssistTools::GenerateTemplateDllLibImpl::extension{ SYSTEM_TEXT(".cpp") };

AssistTools::GenerateTemplateDllLibImpl::GenerateTemplateDllLibImpl(const System::String& templateFileName, const Replace& replace)
    : ParentType{ templateFileName, extension, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateDllLibImpl)

void AssistTools::GenerateTemplateDllLibImpl::GenerateTo(const System::String& exportDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& solutionName, const System::String& managerName, const System::String& managerChineseName, const System::String& projectCapital, const System::String& managerCapital) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    auto newVariable = GetCopyrightVariable(copyrightData);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ManagerName), managerName);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ManagerChineseName), managerChineseName);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ManagerCapital), managerCapital);

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