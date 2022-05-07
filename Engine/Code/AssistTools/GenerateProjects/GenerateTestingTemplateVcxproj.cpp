///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:50)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateVcxproj.h"
#include "Detail/GenerateTestingTemplateVcxprojImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::GenerateTestingTemplateVcxproj::GenerateTestingTemplateVcxproj(const System::String& templateFileName,
                                                                            const System::String& projectName,
                                                                            const System::String& moduleName,
                                                                            const System::String& includeName,
                                                                            const System::String& testingIncludeName,
                                                                            const System::String& debugLibName,
                                                                            const System::String& releaseLibName)
    : impl{ templateFileName, projectName, moduleName, includeName, testingIncludeName, debugLibName, releaseLibName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTestingTemplateVcxproj)

void AssistTools::GenerateTestingTemplateVcxproj::GenerateTo(const System::String& resourceDirectory,
                                                             const System::String& solutionName,
                                                             const System::String& newModuleName,
                                                             const System::String& newIncludeName,
                                                             const System::String& newTestingIncludeName,
                                                             const System::String& newDebugLibName,
                                                             const System::String& newReleaseLibName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, solutionName, newModuleName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName);
}
