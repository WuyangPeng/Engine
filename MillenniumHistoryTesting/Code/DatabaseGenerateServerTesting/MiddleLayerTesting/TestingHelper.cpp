///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 22:31)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

DatabaseGenerateServerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成服务器中间层测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerTesting, TestingHelper)

void DatabaseGenerateServerTesting::TestingHelper::InitSuite()
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

void DatabaseGenerateServerTesting::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddArtificialIntelligenceSuite()
{
    auto artificialIntelligenceSuite = GenerateSuite("人工智能");

    AddSuite(artificialIntelligenceSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddAudioSuite()
{
    auto audioSuite = GenerateSuite("音效");

    AddSuite(audioSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddCameraSystemsSuite()
{
    auto cameraSystemsSuite = GenerateSuite("相机系统");

    AddSuite(cameraSystemsSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddEventSuite()
{
    auto eventSuite = GenerateSuite("事件");

    AddSuite(eventSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddGUISuite()
{
    auto guiSuite = GenerateSuite("事件");

    AddSuite(guiSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddInputSuite()
{
    auto inputSuite = GenerateSuite("输入");

    AddSuite(inputSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddMessageSuite()
{
    auto messageSuite = GenerateSuite("消息");

    AddSuite(messageSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddNetworkSuite()
{
    auto networkSuite = GenerateSuite("网络");

    AddSuite(networkSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddObjectLogicSuite()
{
    auto objectLogicSuite = GenerateSuite("对象逻辑");

    AddSuite(objectLogicSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddPhysicalModellingSuite()
{
    auto physicalModellingSuite = GenerateSuite("物理建模");

    AddSuite(physicalModellingSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddRenderingSuite()
{
    auto renderingSuite = GenerateSuite("渲染");

    AddSuite(renderingSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddResourceSuite()
{
    auto resourceSuite = GenerateSuite("资源");

    AddSuite(resourceSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddSystemSuite()
{
    auto systemSuit = GenerateSuite("系统");

    AddSuite(systemSuit);
}
