///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/29 13:49)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateCodeDirectory.h"
#include "Detail/GenerateTestingTemplateCodeDirectoryImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"

using std::string;

AssistTools::GenerateTestingTemplateCodeDirectory::GenerateTestingTemplateCodeDirectory(const System::String& directory, const string& configurationFileName)
    : impl{ directory, configurationFileName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GenerateTestingTemplateCodeDirectory)

void AssistTools::GenerateTestingTemplateCodeDirectory::GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& newCoreName, const System::String& CoreNameCapital) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GenerateTo(exportDirectory, newSolutionName, copyrightData, projectCapital, newCoreName, CoreNameCapital);
}
