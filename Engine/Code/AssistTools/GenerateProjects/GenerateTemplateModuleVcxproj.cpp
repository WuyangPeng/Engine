///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 13:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateModuleVcxproj.h"
#include "Detail/GenerateTemplateModuleVcxprojImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTemplateModuleVcxproj::GenerateTemplateModuleVcxproj(const System::String& templateFileName, const System::String& projectName, const System::String& moduleName, const System::String& includeName)
    : impl{ templateFileName, projectName, moduleName, includeName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateModuleVcxproj)

void AssistTools::GenerateTemplateModuleVcxproj::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newModuleName, const System::String& newIncludeName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, solutionName, newModuleName, newIncludeName);
}
