///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 11:13)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateManagerLibImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

const System::String AssistTools::GenerateTemplateManagerLibImpl::extension{ SYSTEM_TEXT(".h"s) };

AssistTools::GenerateTemplateManagerLibImpl::GenerateTemplateManagerLibImpl(const System::String& templateFileName, const Replace& replace)
    : ParentType{ templateFileName, extension, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTemplateManagerLibImpl)

void AssistTools::GenerateTemplateManagerLibImpl::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& managerCapital, const System::String& solutionName, const System::String& managerName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    auto newVariable = GetCopyrightVariable(copyrightData);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ProjectCapital), projectCapital);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ManagerName), managerName);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::ManagerCapital), managerCapital);
    newVariable.emplace(GetOriginal(GenerateTemplateReplace::SolutionName), solutionName);

    return ParentType::Generate(resourceDirectory, newProjectName, newVariable);
}

/*
示例模板：
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// Copyright (c) 2011-%EndYear%
//
// %ProjectChineseName%版本：%Versions% (%Date% %Hour%:%Minute%)

#ifndef %ProjectCapital%_%ManagerCapital%_LIB_H
#define %ProjectCapital%_%ManagerCapital%_LIB_H

#if defined(_MSC_VER) 

  #ifdef _DEBUG 
    #pragma comment(lib,"%SolutionName%%ManagerName%D.lib")
  #else
    #pragma comment(lib,"%SolutionName%%ManagerName%.lib")
  #endif // _DEBUG

#endif // _MSC_VER

#endif // %ProjectCapital%_%ManagerCapital%_LIB_H
*/