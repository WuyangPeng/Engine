///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/29 13:48)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateManagerLib.h"
#include "Detail/GenerateTemplateManagerLibImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

AssistTools::GenerateTemplateManagerLib::GenerateTemplateManagerLib(const System::String& templateFileName, const Replace& replace)
    : impl{ templateFileName, replace }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateManagerLib)

void AssistTools::GenerateTemplateManagerLib::GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& managerCapital, const System::String& solutionName, const System::String& managerName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, newProjectName, copyrightData, projectCapital, managerCapital, solutionName, managerName);
}
