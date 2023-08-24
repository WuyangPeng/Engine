///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 22:12)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateServerMiddleLayerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成服务器中间层测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerMiddleLayerTesting, TestingHelper)

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::InitSuite()
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

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddArtificialIntelligenceSuite()
{
    auto artificialIntelligenceSuite = GenerateSuite("人工智能");

    ADD_TEST(artificialIntelligenceSuite, ArtificialIntelligenceManagerTesting);

    AddSuite(artificialIntelligenceSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddAudioSuite()
{
    auto audioSuite = GenerateSuite("音效");

    ADD_TEST(audioSuite, AudioManagerTesting);

    AddSuite(audioSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddCameraSystemsSuite()
{
    auto cameraSystemsSuite = GenerateSuite("相机系统");

    ADD_TEST(cameraSystemsSuite, CameraSystemsManagerTesting);

    AddSuite(cameraSystemsSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddEventSuite()
{
    auto eventSuite = GenerateSuite("事件");

    ADD_TEST(eventSuite, EventManagerTesting);

    AddSuite(eventSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddGUISuite()
{
    auto guiSuite = GenerateSuite("GUI");

    ADD_TEST(guiSuite, GUIManagerTesting);

    AddSuite(guiSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddInputSuite()
{
    auto inputSuite = GenerateSuite("输入");

    ADD_TEST(inputSuite, InputManagerTesting);

    AddSuite(inputSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddMessageSuite()
{
    auto messageSuite = GenerateSuite("消息");

    ADD_TEST(messageSuite, MessageManagerTesting);

    AddSuite(messageSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddNetworkSuite()
{
    auto networkSuite = GenerateSuite("网络");

    ADD_TEST(networkSuite, NetworkManagerTesting);

    AddSuite(networkSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddObjectLogicSuite()
{
    auto objectLogicSuite = GenerateSuite("对象逻辑");

    ADD_TEST(objectLogicSuite, ObjectLogicManagerTesting);

    AddSuite(objectLogicSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddPhysicalModellingSuite()
{
    auto physicalModellingSuite = GenerateSuite("物理建模");

    ADD_TEST(physicalModellingSuite, PhysicalModellingManagerTesting);

    AddSuite(physicalModellingSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddRenderingSuite()
{
    auto renderingSuite = GenerateSuite("渲染");

    ADD_TEST(renderingSuite, RenderingManagerTesting);

    AddSuite(renderingSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddResourceSuite()
{
    auto resourceSuite = GenerateSuite("资源");

    ADD_TEST(resourceSuite, ResourceManagerTesting);

    AddSuite(resourceSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddSystemSuite()
{
    auto systemSuit = GenerateSuite("系统");

    ADD_TEST(systemSuit, SystemManagerTesting);

    AddSuite(systemSuit);
}
