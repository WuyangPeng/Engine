///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 22:12)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateServerMiddleLayerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���ݿ����ɷ������м�����" }
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
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddArtificialIntelligenceSuite()
{
    auto artificialIntelligenceSuite = GenerateSuite("�˹�����");

    ADD_TEST(artificialIntelligenceSuite, ArtificialIntelligenceManagerTesting);

    AddSuite(artificialIntelligenceSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddAudioSuite()
{
    auto audioSuite = GenerateSuite("��Ч");

    ADD_TEST(audioSuite, AudioManagerTesting);

    AddSuite(audioSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddCameraSystemsSuite()
{
    auto cameraSystemsSuite = GenerateSuite("���ϵͳ");

    ADD_TEST(cameraSystemsSuite, CameraSystemsManagerTesting);

    AddSuite(cameraSystemsSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddEventSuite()
{
    auto eventSuite = GenerateSuite("�¼�");

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
    auto inputSuite = GenerateSuite("����");

    ADD_TEST(inputSuite, InputManagerTesting);

    AddSuite(inputSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddMessageSuite()
{
    auto messageSuite = GenerateSuite("��Ϣ");

    ADD_TEST(messageSuite, MessageManagerTesting);

    AddSuite(messageSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddNetworkSuite()
{
    auto networkSuite = GenerateSuite("����");

    ADD_TEST(networkSuite, NetworkManagerTesting);

    AddSuite(networkSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddObjectLogicSuite()
{
    auto objectLogicSuite = GenerateSuite("�����߼�");

    ADD_TEST(objectLogicSuite, ObjectLogicManagerTesting);

    AddSuite(objectLogicSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddPhysicalModellingSuite()
{
    auto physicalModellingSuite = GenerateSuite("����ģ");

    ADD_TEST(physicalModellingSuite, PhysicalModellingManagerTesting);

    AddSuite(physicalModellingSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddRenderingSuite()
{
    auto renderingSuite = GenerateSuite("��Ⱦ");

    ADD_TEST(renderingSuite, RenderingManagerTesting);

    AddSuite(renderingSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddResourceSuite()
{
    auto resourceSuite = GenerateSuite("��Դ");

    ADD_TEST(resourceSuite, ResourceManagerTesting);

    AddSuite(resourceSuite);
}

void DatabaseGenerateServerMiddleLayerTesting::TestingHelper::AddSystemSuite()
{
    auto systemSuit = GenerateSuite("ϵͳ");

    ADD_TEST(systemSuit, SystemManagerTesting);

    AddSuite(systemSuit);
}
