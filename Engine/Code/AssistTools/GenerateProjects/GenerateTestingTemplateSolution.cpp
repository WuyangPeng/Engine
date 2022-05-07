///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/29 13:50)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateSolution.h"
#include "Detail/GenerateTemplateSolutionImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTemplateSolution::GenerateTemplateSolution(const System::String& templateFileName, const System::String& projectName, const System::String& coreName)
    : impl{ templateFileName, projectName, coreName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateSolution)

void AssistTools::GenerateTemplateSolution::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newCoreName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, solutionName, newCoreName);
}
