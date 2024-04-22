///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/08 15:42)

#include "GenerateTestingEngineTesting.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/GenerateTestingEngine.h"
#include "AssistTools/GenerateProjects/Using/ProjectGenerationUsing.h"

AssistTools::GenerateTestingEngineTesting::GenerateTestingEngineTesting(const OStreamShared& stream)
    : ParentType{ stream, SYSTEM_TEXT("Resource/output/TestingTemplate/") }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GenerateTestingEngineTesting)

void AssistTools::GenerateTestingEngineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::GenerateTestingEngineTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GenerateEngineTest);
    ASSERT_NOT_THROW_EXCEPTION_1(ResultTest, GetOutput());
}

void AssistTools::GenerateTestingEngineTesting::GenerateEngineTest()
{
    const GenerateTestingEngine generateTestingEngine{ SYSTEM_TEXT("Resource/GenerateProjectsSuite/TestingTemplate/"), GetOutput() };

    generateTestingEngine.Generate();
}
