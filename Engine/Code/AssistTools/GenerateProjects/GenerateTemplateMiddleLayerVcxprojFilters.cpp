///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateMiddleLayerVcxprojFilters.h"
#include "Detail/GenerateTemplateMiddleLayerVcxprojFiltersImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTemplateMiddleLayerVcxprojFilters::GenerateTemplateMiddleLayerVcxprojFilters(const System::String& templateFileName, const System::String& projectName, const System::String& managerName)
    : impl{ templateFileName, projectName, managerName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateMiddleLayerVcxprojFilters)

void AssistTools::GenerateTemplateMiddleLayerVcxprojFilters::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newManagerName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, solutionName, newManagerName);
}
