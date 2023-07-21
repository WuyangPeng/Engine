///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/18 18:18)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

GameClientTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "游戏客户端中间层测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClientTesting, TestingHelper)

void GameClientTesting::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddArtificialIntelligenceSuite();
    AddAudioSuite();
    AddCameraSystemsSuite();
    AddEventSuite();
    AddGUISuite();
    AddInputSuite();
    AddMessageSuite();
    AddNetworkSuite();
    AddObjectLogicSuite();
    AddPhysicalModellingSuite();
    AddRenderingSuite();
    AddResourceSuite();
    AddSystemSuite();
}

void GameClientTesting::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void GameClientTesting::TestingHelper::AddArtificialIntelligenceSuite()
{
    auto artificialIntelligenceSuite = GenerateSuite("人工智能");

    AddSuite(artificialIntelligenceSuite);
}

void GameClientTesting::TestingHelper::AddAudioSuite()
{
    auto audioSuite = GenerateSuite("音效");

    AddSuite(audioSuite);
}

void GameClientTesting::TestingHelper::AddCameraSystemsSuite()
{
    auto cameraSystemsSuite = GenerateSuite("相机系统");

    AddSuite(cameraSystemsSuite);
}

void GameClientTesting::TestingHelper::AddEventSuite()
{
    auto eventSuite = GenerateSuite("事件");

    AddSuite(eventSuite);
}

void GameClientTesting::TestingHelper::AddGUISuite()
{
    auto guiSuite = GenerateSuite("事件");

    AddSuite(guiSuite);
}

void GameClientTesting::TestingHelper::AddInputSuite()
{
    auto inputSuite = GenerateSuite("输入");

    AddSuite(inputSuite);
}

void GameClientTesting::TestingHelper::AddMessageSuite()
{
    auto messageSuite = GenerateSuite("消息");

    AddSuite(messageSuite);
}

void GameClientTesting::TestingHelper::AddNetworkSuite()
{
    auto networkSuite = GenerateSuite("网络");

    AddSuite(networkSuite);
}

void GameClientTesting::TestingHelper::AddObjectLogicSuite()
{
    auto objectLogicSuite = GenerateSuite("对象逻辑");

    AddSuite(objectLogicSuite);
}

void GameClientTesting::TestingHelper::AddPhysicalModellingSuite()
{
    auto physicalModellingSuite = GenerateSuite("物理建模");

    AddSuite(physicalModellingSuite);
}

void GameClientTesting::TestingHelper::AddRenderingSuite()
{
    auto renderingSuite = GenerateSuite("渲染");

    AddSuite(renderingSuite);
}

void GameClientTesting::TestingHelper::AddResourceSuite()
{
    auto resourceSuite = GenerateSuite("资源");

    AddSuite(resourceSuite);
}

void GameClientTesting::TestingHelper::AddSystemSuite()
{
    auto systemSuit = GenerateSuite("系统");

    AddSuite(systemSuit);
}
