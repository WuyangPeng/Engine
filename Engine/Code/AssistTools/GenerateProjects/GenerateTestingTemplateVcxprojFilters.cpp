///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 13:50)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateVcxprojFilters.h"
#include "Detail/GenerateTestingTemplateVcxprojFiltersImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTestingTemplateVcxprojFilters::GenerateTestingTemplateVcxprojFilters(const System::String& templateFileName, const System::String& projectName, const System::String& moduleName)
    : impl{ templateFileName, projectName, moduleName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTestingTemplateVcxprojFilters)

void AssistTools::GenerateTestingTemplateVcxprojFilters::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newModuleName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, solutionName, newModuleName);
}
