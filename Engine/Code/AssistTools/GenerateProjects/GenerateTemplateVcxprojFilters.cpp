///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/29 13:49)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateVcxprojFilters.h"
#include "Detail/GenerateTemplateVcxprojFiltersImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTemplateVcxprojFilters::GenerateTemplateVcxprojFilters(const System::String& templateFileName, const System::String& solutionName)
    : impl{ templateFileName, solutionName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateVcxprojFilters)

void AssistTools::GenerateTemplateVcxprojFilters::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, newSolutionName);
}
