///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/10 14:13)

#include "ProjectGenerationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/MiddleLayerModule.h"
#include "AssistTools/GenerateProjects/ProjectGeneration.h"
#include "AssistTools/GenerateProjects/Using/ProjectGenerationUsing.h"

using System::operator++;

AssistTools::ProjectGenerationTesting::ProjectGenerationTesting(const OStreamShared& stream)
    : ParentType{ stream },
      gameParameterAnalysis{ "Configuration/GameParameter0.json" },
      codeMappingAnalysis{ SYSTEM_TEXT("Resource/GenerateProjectsSuite/Template/GenerateProjects.json") },
      directory{ SYSTEM_TEXT("Resource/GenerateProjectsSuite/") }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, ProjectGenerationTesting)

AssistTools::GameParameterAnalysis AssistTools::ProjectGenerationTesting::GetGameParameterAnalysis() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return gameParameterAnalysis;
}

CoreTools::CodeMappingAnalysis AssistTools::ProjectGenerationTesting::GetCodeMappingAnalysis() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return codeMappingAnalysis;
}

System::String AssistTools::ProjectGenerationTesting::GetIdentifier(const StringView& original)
{
    return String{ dollar } + original.data() + dollar.data();
}

AssistTools::ProjectGenerationTesting::String AssistTools::ProjectGenerationTesting::GetDirectory() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return directory;
}

void AssistTools::ProjectGenerationTesting::GetContentTest(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("Template/ProjectNameWindows/Project/ProjectSln.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    ASSERT_FALSE(content.empty());
}

void AssistTools::ProjectGenerationTesting::CopyrightTest(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("Template/Code/Module/Core/DllLibH.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(copyrightKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(dataKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(hourKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(minuteKey)), System::String::npos);

    ASSERT_UNEQUAL(content.find(SYSTEM_TEXT("Copyright")), System::String::npos);
    ASSERT_UNEQUAL(content.find(SYSTEM_TEXT("Threading Core Render Engine")), System::String::npos);
}

void AssistTools::ProjectGenerationTesting::ModuleTest(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("Template/ReadMeMd.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(moduleCountKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(moduleDescribeKey)), System::String::npos);

    ASSERT_UNEQUAL(content.find(System::ToString(gameParameterAnalysis.GetModuleCount())), System::String::npos);

    for (auto iter = gameParameterAnalysis.GetModuleBegin();
         iter != gameParameterAnalysis.GetModuleEnd();
         ++iter)
    {
        ASSERT_UNEQUAL(content.find(iter->GetModuleName()), System::String::npos);
        ASSERT_UNEQUAL(content.find(iter->GetChineseName()), System::String::npos);
    }
}

void AssistTools::ProjectGenerationTesting::ModuleJsonTest(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("Template/Generate/Configuration/ProjectJson.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(moduleNameKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(moduleJsonKey)), System::String::npos);

    for (auto iter = gameParameterAnalysis.GetModuleBegin();
         iter != gameParameterAnalysis.GetModuleEnd();
         ++iter)
    {
        ASSERT_UNEQUAL(content.find(iter->GetModuleName()), System::String::npos);
    }
}

void AssistTools::ProjectGenerationTesting::ModuleTestingJsonTest(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("TestingTemplate/Generate/Configuration/ProjectTestingJson.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(moduleNameKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(moduleTestingJsonKey)), System::String::npos);

    for (auto iter = gameParameterAnalysis.GetModuleBegin();
         iter != gameParameterAnalysis.GetModuleEnd();
         ++iter)
    {
        ASSERT_UNEQUAL(content.find(iter->GetModuleName()), System::String::npos);
    }
}

void AssistTools::ProjectGenerationTesting::CodeAnalysisTest(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("Template/Code/ReadMeMd.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(codeAnalysisKey)), System::String::npos);

    for (auto iter = gameParameterAnalysis.GetModuleBegin();
         iter != gameParameterAnalysis.GetModuleEnd();
         ++iter)
    {
        ASSERT_UNEQUAL(content.find(iter->GetModuleName()), System::String::npos);
    }
}

void AssistTools::ProjectGenerationTesting::TestingCodeAnalysisTest(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("TestingTemplate/Code/ReadMeMd.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(testingCodeAnalysisKey)), System::String::npos);

    for (auto iter = gameParameterAnalysis.GetModuleBegin();
         iter != gameParameterAnalysis.GetModuleEnd();
         ++iter)
    {
        ASSERT_UNEQUAL(content.find(iter->GetModuleName()), System::String::npos);
    }
}

void AssistTools::ProjectGenerationTesting::MiddleLayerTest(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("Template/Code/Module/MiddleLayer/ModuleMiddleLayerH.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(middleLayerIncludeKey)), System::String::npos);

    for (auto iter = gameParameterAnalysis.GetMiddleLayerBegin();
         iter != gameParameterAnalysis.GetMiddleLayerEnd();
         ++iter)
    {
        ASSERT_UNEQUAL(content.find(iter->GetMiddleLayerName()), System::String::npos);
    }
}

void AssistTools::ProjectGenerationTesting::MiddleLayerFwdTest(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("Template/Code/Module/MiddleLayer/ModuleMiddleLayerFwdH.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(middleLayerFwdIncludeKey)), System::String::npos);

    for (auto iter = gameParameterAnalysis.GetMiddleLayerBegin();
         iter != gameParameterAnalysis.GetMiddleLayerEnd();
         ++iter)
    {
        ASSERT_UNEQUAL(content.find(iter->GetMiddleLayerName()), System::String::npos);
    }
}

void AssistTools::ProjectGenerationTesting::CallRunTestingBat(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("TestingTemplate/Run/RunAllTestingBat.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(callRunTestingBatKey)), System::String::npos);

    for (auto iter = gameParameterAnalysis.GetModuleBegin();
         iter != gameParameterAnalysis.GetModuleEnd();
         ++iter)
    {
        ASSERT_UNEQUAL(content.find(iter->GetModuleName()), System::String::npos);
    }
}

void AssistTools::ProjectGenerationTesting::GameParameterTest(ProjectGenerationType projectGenerationType)
{
    const ProjectGeneration projectGeneration{ projectGenerationType,
                                               directory + SYSTEM_TEXT("Template/ProjectNameWindows/Project/ProjectSln.txt"),
                                               gameParameterAnalysis,
                                               codeMappingAnalysis };

    const auto content = projectGeneration.GetContent();

    for (auto gameParameter = GameParameterType::Begin; gameParameter < GameParameterType::Count; ++gameParameter)
    {
        ASSERT_EQUAL(content.find(GetIdentifier(ToString(gameParameter))), System::String::npos);
    }
}
