///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:46)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTemplateEngineDirectory.h"
#include "Detail/GenerateTemplateEngineDirectoryImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

using std::string;

AssistTools::GenerateTemplateEngineDirectory::GenerateTemplateEngineDirectory(const System::String& directory, const string& configurationFileName)
    : impl{ directory, configurationFileName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTemplateEngineDirectory)

void AssistTools::GenerateTemplateEngineDirectory::GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName, const System::String& newIncludeName) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(resourceDirectory, newSolutionName, newCoreName, newIncludeName);
}
