///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/13 10:50)

#include "DefaultProjectGenerationTesting.h"
#include "System/Helper/EnumOperator.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"
#include "AssistTools/GenerateProjects/Flags/ProjectGenerationType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/ProjectGeneration.h"

AssistTools::DefaultProjectGenerationTesting::DefaultProjectGenerationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, DefaultProjectGenerationTesting)

void AssistTools::DefaultProjectGenerationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::DefaultProjectGenerationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(GetContentTest, ProjectGenerationType::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(CopyrightTest, ProjectGenerationType::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(ModuleTest, ProjectGenerationType::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(ModuleJsonTest, ProjectGenerationType::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(ModuleTestingJsonTest, ProjectGenerationType::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(CodeAnalysisTest, ProjectGenerationType::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(TestingCodeAnalysisTest, ProjectGenerationType::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(MiddleLayerTest, ProjectGenerationType::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(MiddleLayerFwdTest, ProjectGenerationType::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(CallRunTestingBat, ProjectGenerationType::Default);
    ASSERT_NOT_THROW_EXCEPTION_1(GameParameterTest, ProjectGenerationType::Default);
}
