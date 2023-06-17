///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2022/04/29 13:49)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateSolution.h"
#include "Detail/GenerateTestingTemplateSolutionImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTestingTemplateSolution::GenerateTestingTemplateSolution(const System::String& templateFileName, const System::String& projectName, const System::String& coreName)
    : impl{ templateFileName, projectName, coreName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTestingTemplateSolution)

void AssistTools::GenerateTestingTemplateSolution::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newCoreName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, solutionName, newCoreName);
}
