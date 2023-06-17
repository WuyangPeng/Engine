///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2022/04/29 13:45)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateDllMain.h"
#include "Detail/GenerateTemplateDllMainImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTemplateDllMain::GenerateTemplateDllMain(const System::String& templateFileName, const Replace& replace)
    : impl{ templateFileName, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateDllMain)

void AssistTools::GenerateTemplateDllMain::GenerateTo(const System::String& resourceDirectory,
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
