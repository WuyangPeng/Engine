///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 11:11)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateMainImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

const System::String AssistTools::GenerateTemplateMainImpl::extension{ SYSTEM_TEXT(".cpp"s) };

AssistTools::GenerateTemplateMainImpl::GenerateTemplateMainImpl(const System::String& templateFileName, const Replace& replace)
    : ParentType{ templateFileName, extension, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateMainImpl)

void AssistTools::GenerateTemplateMainImpl::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& solutionName, const System::String& projectName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    auto newVariable = GetCopyrightVariable(copyrightData);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ProjectName), projectName);

    return ParentType::Generate(resourceDirectory, newProjectName, newVariable);
}

/*
示例模板：
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%版本：%Versions% (%Date% %Hour%:%Minute%)

#include "%SolutionName%/%SolutionName%/%SolutionName%Helper.h"
#include "Framework/Macro/MainFunctionMacro.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(%SolutionName%,%SolutionName%Helper,SYSTEM_TEXT("%ProjectName% %SolutionName%"),SYSTEM_TEXT("DefaultEnvironment"),1024,768)
*/