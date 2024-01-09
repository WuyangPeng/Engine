/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 22:59)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateMiddleLayerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库生成中间层单元测试" }
{
    InitSuite();

    USER_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateMiddleLayerTesting, TestingHelper)

void DatabaseGenerateMiddleLayerTesting::TestingHelper::InitSuite()
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

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddArtificialIntelligenceSuite()
{
    auto artificialIntelligenceSuite = GenerateSuite("人工智能");

    ADD_TEST(artificialIntelligenceSuite, AIManagerTesting);

    AddSuite(artificialIntelligenceSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddAudioSuite()
{
    auto audioSuite = GenerateSuite("音效");

    ADD_TEST(audioSuite, AudioManagerTesting);

    AddSuite(audioSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddCameraSystemsSuite()
{
    auto cameraSystemsSuite = GenerateSuite("相机系统");

    ADD_TEST(cameraSystemsSuite, CameraSystemsManagerTesting);

    AddSuite(cameraSystemsSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddEventSuite()
{
    auto eventSuite = GenerateSuite("事件");

    ADD_TEST(eventSuite, EventManagerTesting);

    AddSuite(eventSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddGUISuite()
{
    auto guiSuite = GenerateSuite("GUI");

    ADD_TEST(guiSuite, GUIManagerTesting);

    AddSuite(guiSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddInputSuite()
{
    auto inputSuite = GenerateSuite("输入");

    ADD_TEST(inputSuite, InputManagerTesting);

    AddSuite(inputSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddMessageSuite()
{
    auto messageSuite = GenerateSuite("消息");

    ADD_TEST(messageSuite, MessageManagerTesting);

    AddSuite(messageSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddNetworkSuite()
{
    auto networkSuite = GenerateSuite("网络");

    ADD_TEST(networkSuite, NetworkManagerTesting);

    AddSuite(networkSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddObjectLogicSuite()
{
    auto objectLogicSuite = GenerateSuite("对象逻辑");

    ADD_TEST(objectLogicSuite, ObjectLogicManagerTesting);

    AddSuite(objectLogicSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddPhysicalModellingSuite()
{
    auto physicalModellingSuite = GenerateSuite("物理建模");

    ADD_TEST(physicalModellingSuite, PhysicalModellingManagerTesting);

    AddSuite(physicalModellingSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddRenderingSuite()
{
    auto renderingSuite = GenerateSuite("渲染");

    ADD_TEST(renderingSuite, RenderingManagerTesting);

    AddSuite(renderingSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddResourceSuite()
{
    auto resourceSuite = GenerateSuite("资源");

    ADD_TEST(resourceSuite, ResourceManagerTesting);

    AddSuite(resourceSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddSystemSuite()
{
    auto systemSuit = GenerateSuite("系统");

    ADD_TEST(systemSuit, SystemManagerTesting);

    AddSuite(systemSuit);
}
