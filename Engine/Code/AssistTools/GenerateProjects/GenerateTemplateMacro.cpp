///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:47)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateMacro.h"
#include "Detail/GenerateTemplateMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTemplateMacro::GenerateTemplateMacro(const System::String& templateFileName, const Replace& replace)
    : impl{ templateFileName, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateMacro)

void AssistTools::GenerateTemplateMacro::GenerateTo(const System::String& resourceDirectory,
                                                    const System::String& newProjectName,
                                                    const CopyrightData& copyrightData,
                                                    const System::String& solutionName,
                                                    const System::String& managerName,
                                                    const System::String& projectCapital,
                                                    const System::String& managerCapital) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, newProjectName, copyrightData, solutionName, managerName, projectCapital, managerCapital);
}
