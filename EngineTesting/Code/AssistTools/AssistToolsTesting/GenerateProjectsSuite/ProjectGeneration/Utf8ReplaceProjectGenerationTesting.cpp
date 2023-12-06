///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/13 11:19)

#include "Utf8ReplaceProjectGenerationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/Flags/ProjectGenerationType.h"

AssistTools::Utf8ReplaceProjectGenerationTesting::Utf8ReplaceProjectGenerationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, Utf8ReplaceProjectGenerationTesting)

void AssistTools::Utf8ReplaceProjectGenerationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::Utf8ReplaceProjectGenerationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(GetContentTest, ProjectGenerationType::Utf8);
    ASSERT_NOT_THROW_EXCEPTION_1(CopyrightTest, ProjectGenerationType::Utf8);
    ASSERT_NOT_THROW_EXCEPTION_1(ModuleTest, ProjectGenerationType::Utf8);
    ASSERT_NOT_THROW_EXCEPTION_1(ModuleJsonTest, ProjectGenerationType::Utf8);
    ASSERT_NOT_THROW_EXCEPTION_1(ModuleTestingJsonTest, ProjectGenerationType::Utf8);
    ASSERT_NOT_THROW_EXCEPTION_1(CodeAnalysisTest, ProjectGenerationType::Utf8);
    ASSERT_NOT_THROW_EXCEPTION_1(TestingCodeAnalysisTest, ProjectGenerationType::Utf8);
    ASSERT_NOT_THROW_EXCEPTION_1(MiddleLayerTest, ProjectGenerationType::Utf8);
    ASSERT_NOT_THROW_EXCEPTION_1(MiddleLayerFwdTest, ProjectGenerationType::Utf8);
    ASSERT_NOT_THROW_EXCEPTION_1(CallRunTestingBat, ProjectGenerationType::Utf8);
    ASSERT_NOT_THROW_EXCEPTION_1(GameParameterTest, ProjectGenerationType::Utf8);
}