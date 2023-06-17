///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 10:49)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateDllMainImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

const System::String AssistTools::GenerateTemplateDllMainImpl::extension{ SYSTEM_TEXT(".cpp") };

AssistTools::GenerateTemplateDllMainImpl::GenerateTemplateDllMainImpl(const System::String& templateFileName, const Replace& replace)
    : ParentType{ templateFileName, extension, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateDllMainImpl)

void AssistTools::GenerateTemplateDllMainImpl::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& solutionName, const System::String& managerName, const System::String& projectCapital, const System::String& managerCapital) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    auto newVariable = GetCopyrightVariable(copyrightData);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ManagerName), managerName);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ManagerCapital), managerCapital);

    return ParentType::Generate(resourceDirectory, newProjectName, newVariable);
}

/*
示例模板： 
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%版本：%Versions% (%Date% %Hour%:%Minute%)

#include "%SolutionName%%ManagerName%Export.h"

#include "%SolutionName%%ManagerName%Fwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

DLL_MAIN_FUNCTION(%SolutionName%%ManagerName%)
*/