///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/10 14:03)

#include "ReplaceProjectGenerationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/Flags/ProjectGenerationType.h" 
#include "AssistTools/GenerateProjects/ProjectGeneration.h"
#include "AssistTools/GenerateProjects/Replace.h"

AssistTools::ReplaceProjectGenerationTesting::ReplaceProjectGenerationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, ReplaceProjectGenerationTesting)

void AssistTools::ReplaceProjectGenerationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::ReplaceProjectGenerationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReplaceTest);
}

void AssistTools::ReplaceProjectGenerationTesting::ReplaceTest()
{
    const auto levelIndexKey = SYSTEM_TEXT("LevelIndex");
    const auto levelIndex = SYSTEM_TEXT("5");
    const ProjectGeneration::ReplaceContainer replace{ Replace{ levelIndexKey, levelIndex } };

    const ProjectGeneration projectGeneration{ ProjectGenerationType::Default,
                                               GetDirectory() + SYSTEM_TEXT("Template/ProjectNameWindows/Project/Project/Resource/Todo/Level.txt"),
                                               GetGameParameterAnalysis(),
                                               GetCodeMappingAnalysis(),
                                               replace };

    const auto content = projectGeneration.GetContent();

    ASSERT_EQUAL(content.find(GetIdentifier(levelIndexKey)), System::String::npos);
    ASSERT_UNEQUAL(content.find(levelIndex), System::String::npos);
}
