/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 14:51)

#include "SlnProjectGenerationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/Flags/ProjectGenerationType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/ProjectGeneration.h"
#include "AssistTools/GenerateProjects/Using/ProjectGenerationUsing.h"

AssistTools::SlnProjectGenerationTesting::SlnProjectGenerationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, SlnProjectGenerationTesting)

void AssistTools::SlnProjectGenerationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::SlnProjectGenerationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ToolProjectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TestingToolProjectTest);
}

void AssistTools::SlnProjectGenerationTesting::ToolProjectTest()
{
    const auto analysis = GetGameParameterAnalysis();
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Sln,
                                               GetDirectory() + SYSTEM_TEXT("Template/ProjectNameWindows/Project/ProjectSln.txt"),
                                               analysis,
                                               GetCodeMappingAnalysis() };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(toolDirectoryKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(toolProjectKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(toolsProjectConfigurationPlatformsKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(guidIndexKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(staticDescribeKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(configurationKey)), System::String::npos);
}

void AssistTools::SlnProjectGenerationTesting::TestingToolProjectTest()
{
    const auto analysis = GetGameParameterAnalysis();
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Sln,
                                               GetDirectory() + SYSTEM_TEXT("Template/ProjectNameWindows/Project/ProjectSln.txt"),
                                               analysis,
                                               GetCodeMappingAnalysis() };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(toolDirectoryKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(testingToolProjectKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(toolsProjectConfigurationPlatformsKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(guidIndexKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(staticDescribeKey)), System::String::npos);
    ASSERT_EQUAL(content.find(GetIdentifier(configurationKey)), System::String::npos);
}
