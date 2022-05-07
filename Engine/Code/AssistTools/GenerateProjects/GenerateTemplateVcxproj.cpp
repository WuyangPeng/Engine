///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:49)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateVcxproj.h"
#include "Detail/GenerateTemplateVcxprojImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTemplateVcxproj::GenerateTemplateVcxproj(const System::String& templateFileName, const System::String& solutionName, const System::String& includeName)
    : impl{ templateFileName, solutionName, includeName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateVcxproj)

void AssistTools::GenerateTemplateVcxproj::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newIncludeName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, newSolutionName, newIncludeName);
}
