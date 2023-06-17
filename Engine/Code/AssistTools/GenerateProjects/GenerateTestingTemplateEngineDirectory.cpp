///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 13:50)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateEngineDirectory.h"
#include "Detail/GenerateTestingTemplateEngineDirectoryImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using std::string;

AssistTools::GenerateTestingTemplateEngineDirectory::GenerateTestingTemplateEngineDirectory(const System::String& directory, const string& configurationFileName)
    : impl{ directory, configurationFileName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTestingTemplateEngineDirectory)

void AssistTools::GenerateTestingTemplateEngineDirectory::GenerateTo(const System::String& resourceDirectory,
                                                                     const System::String& newSolutionName,
                                                                     const System::String& newCoreName,
                                                                     const System::String& newIncludeName,
                                                                     const System::String& newTestingIncludeName,
                                                                     const System::String& newDebugLibName,
                                                                     const System::String& newReleaseLibName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, newSolutionName, newCoreName, newIncludeName, newTestingIncludeName, newDebugLibName, newReleaseLibName);
}
