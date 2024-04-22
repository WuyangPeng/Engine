///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:28)

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
    const GameModule::GuidContainer guid{ SYSTEM_TEXT("6E4ADD87-9435-4726-9FA2-0FB79FBE6727"),
                                          SYSTEM_TEXT("CCA2224E-0568-4DAB-9D57-0DD4D20EBD46"),
                                          SYSTEM_TEXT("5B753E23-3BE0-4BEA-88F9-EF9388D1058A"),
                                          SYSTEM_TEXT("4CCECE3C-E703-4694-A0DB-B136CAAEF3D0") };

    const GameModule gameModule{ moduleName, chineseName, projectServiceType, uppercaseName, guid };

    ASSERT_EQUAL(gameModule.GetModuleName(), moduleName);
    ASSERT_EQUAL(gameModule.GetChineseName(), chineseName);
    ASSERT_EQUAL(gameModule.GetProjectServiceType(), projectServiceType);
    ASSERT_EQUAL(gameModule.GetUppercaseName(), uppercaseName);
}