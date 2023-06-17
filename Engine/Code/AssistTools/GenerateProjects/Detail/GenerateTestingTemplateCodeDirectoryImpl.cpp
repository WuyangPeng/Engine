///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/29 11:20)

#include "AssistTools/AssistToolsExport.h"

#include "GenerateTestingTemplateCodeDirectoryImpl.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/GenerateTestingTemplateEngine.h"

using std::string;
using namespace std::literals;

AssistTools::GenerateTestingTemplateCodeDirectoryImpl::GenerateTestingTemplateCodeDirectoryImpl(const System::String& directory, const string& configurationFileName)
    : ParentType{ directory, configurationFileName }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingTemplateCodeDirectoryImpl)

void AssistTools::GenerateTestingTemplateCodeDirectoryImpl::GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& newCoreName, const System::String& CoreNameCapital) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    GenerateToManager(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT(""s), projectCapital, SYSTEM_TEXT(""s));
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, SYSTEM_TEXT("MiddleLayer"), projectCapital, SYSTEM_TEXT("MIDDLE_LAYER_"s));
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, newCoreName, projectCapital, CoreNameCapital + SYSTEM_TEXT("_"s));
}

void AssistTools::GenerateTestingTemplateCodeDirectoryImpl::GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& projectCapital, const System::String& managerCapital) const
{
    auto libFileName = (aManagerName.empty() ? SYSTEM_TEXT("GameTemplateTestingExeLibCpp.txt"s) : SYSTEM_TEXT("GameTemplateTestingLibCpp.txt"s));

    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapital, SYSTEM_TEXT(".h"s), SYSTEM_TEXT("GameTemplateTestingH.txt"s), SYSTEM_TEXT("Testing"s));
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapital, SYSTEM_TEXT(".h"s), SYSTEM_TEXT("GameTemplateTestingHelperH.txt"s), SYSTEM_TEXT("TestingHelper"s));
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapital, SYSTEM_TEXT(".cpp"s), SYSTEM_TEXT("GameTemplateTestingHelperCpp.txt"s), SYSTEM_TEXT("TestingHelper"s));
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapital, SYSTEM_TEXT(".cpp"s), SYSTEM_TEXT("GameTemplateTestingMainCpp.txt"s), SYSTEM_TEXT("TestingMain"s));
    GenerateToManager(exportDirectory, newSolutionName, copyrightData, aManagerName, projectCapital, managerCapital, SYSTEM_TEXT(".cpp"s), libFileName, SYSTEM_TEXT("TestingLib"s));
}

void AssistTools::GenerateTestingTemplateCodeDirectoryImpl::GenerateToManager(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& aManagerName, const System::String& projectCapital, const System::String& managerCapital, const System::String& extension, const System::String& fileName, const System::String& resultName) const
{
    const System::String fullDirectory{ exportDirectory + GetForwardSlash() + GetCodeDirectory() + GetForwardSlash() + newSolutionName + GetTesting() + GetForwardSlash() + newSolutionName + aManagerName + GetTesting() };

    GenerateTestingTemplateEngine::Replace replace{};
    GenerateTestingTemplateEngine generateTestingTemplateEngine{ GetDirectory() + GetForwardSlash() + fileName, extension, replace };
    generateTestingTemplateEngine.GenerateTo(fullDirectory, resultName, copyrightData, newSolutionName, aManagerName, projectCapital, managerCapital);
}
