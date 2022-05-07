///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:47)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateLogJson.h"
#include "Detail/GenerateTemplateLogJsonImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTemplateLogJson::GenerateTemplateLogJson(const System::String& templateFileName, const System::String& projectName)
    : impl{ templateFileName, projectName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateLogJson)

void AssistTools::GenerateTemplateLogJson::GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newFileName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, solutionName, newFileName);
}
