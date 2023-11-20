///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/13 11:01)

#include "ClientProjectGenerationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/Flags/ProjectGenerationType.h"
#include "AssistTools/GenerateProjects/Flags/ProjectServiceType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/ProjectGeneration.h"
#include "AssistTools/GenerateProjects/Using/ProjectGenerationUsing.h"

AssistTools::ClientProjectGenerationTesting::ClientProjectGenerationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, ClientProjectGenerationTesting)

void AssistTools::ClientProjectGenerationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::ClientProjectGenerationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CallRunBatTest);
}

void AssistTools::ClientProjectGenerationTesting::CallRunBatTest()
{
    const auto analysis = GetGameParameterAnalysis();
    const ProjectGeneration projectGeneration{ ProjectGenerationType::Default,
                                               GetDirectory() + SYSTEM_TEXT("Template/Run/RunAllBat.txt"),
                                               analysis,
                                               GetCodeMappingAnalysis(),
                                               ProjectServiceType::Client };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(callRunBatKey)), System::String::npos);

    std::for_each(analysis.GetModuleBegin(), analysis.GetModuleEnd(), [&content, this](const auto& element) {
        if (element.GetProjectServiceType() == ProjectServiceType::Client)
        {
            ASSERT_UNEQUAL(content.find(element.GetModuleName()), System::String::npos);
        }
        else
        {
            ASSERT_EQUAL(content.find(element.GetModuleName()), System::String::npos);
        }
    });
}
