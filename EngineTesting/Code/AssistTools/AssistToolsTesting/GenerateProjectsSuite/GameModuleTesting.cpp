///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/08 15:28)

#include "GameModuleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "AssistTools/GenerateProjects/Flags/ProjectServiceType.h"
#include "AssistTools/GenerateProjects/GameModule.h"

AssistTools::GameModuleTesting::GameModuleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AssistTools, GameModuleTesting)

void AssistTools::GameModuleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AssistTools::GameModuleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GameModuleReadTest);
}

void AssistTools::GameModuleTesting::GameModuleReadTest()
{
    const auto moduleName = SYSTEM_TEXT("ModuleName");
    const auto chineseName = SYSTEM_TEXT("ChineseName");
    const auto uppercaseName = SYSTEM_TEXT("UppercaseName");
    constexpr auto projectServiceType = ProjectServiceType::Server;

    const GameModule gameModule{ moduleName, chineseName, projectServiceType, uppercaseName };

    ASSERT_EQUAL(gameModule.GetModuleName(), moduleName);
    ASSERT_EQUAL(gameModule.GetChineseName(), chineseName);
    ASSERT_ENUM_EQUAL(gameModule.GetProjectServiceType(), projectServiceType);
    ASSERT_EQUAL(gameModule.GetUppercaseName(), uppercaseName);
}
