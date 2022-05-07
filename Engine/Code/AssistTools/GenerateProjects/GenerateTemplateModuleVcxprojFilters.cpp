///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateModuleVcxprojFilters.h"
#include "Detail/GenerateTemplateModuleVcxprojFiltersImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTemplateModuleVcxprojFilters::GenerateTemplateModuleVcxprojFilters(const System::String& templateFileName, const System::String& projectName, const System::String& moduleName)
    : impl{ templateFileName, projectName, moduleName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateModuleVcxprojFilters)

void AssistTools::GenerateTemplateModuleVcxprojFilters::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newModuleName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, solutionName, newModuleName);
}
