/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 22:59)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

DatabaseGenerateMiddleLayerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���ݿ������м�㵥Ԫ����" }
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
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddArtificialIntelligenceSuite()
{
    auto artificialIntelligenceSuite = GenerateSuite("�˹�����");

    ADD_TEST(artificialIntelligenceSuite, AIManagerTesting);

    AddSuite(artificialIntelligenceSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddAudioSuite()
{
    auto audioSuite = GenerateSuite("��Ч");

    ADD_TEST(audioSuite, AudioManagerTesting);

    AddSuite(audioSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddCameraSystemsSuite()
{
    auto cameraSystemsSuite = GenerateSuite("���ϵͳ");

    ADD_TEST(cameraSystemsSuite, CameraSystemsManagerTesting);

    AddSuite(cameraSystemsSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddEventSuite()
{
    auto eventSuite = GenerateSuite("�¼�");

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
    auto inputSuite = GenerateSuite("����");

    ADD_TEST(inputSuite, InputManagerTesting);

    AddSuite(inputSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddMessageSuite()
{
    auto messageSuite = GenerateSuite("��Ϣ");

    ADD_TEST(messageSuite, MessageManagerTesting);

    AddSuite(messageSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddNetworkSuite()
{
    auto networkSuite = GenerateSuite("����");

    ADD_TEST(networkSuite, NetworkManagerTesting);

    AddSuite(networkSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddObjectLogicSuite()
{
    auto objectLogicSuite = GenerateSuite("�����߼�");

    ADD_TEST(objectLogicSuite, ObjectLogicManagerTesting);

    AddSuite(objectLogicSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddPhysicalModellingSuite()
{
    auto physicalModellingSuite = GenerateSuite("����ģ");

    ADD_TEST(physicalModellingSuite, PhysicalModellingManagerTesting);

    AddSuite(physicalModellingSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddRenderingSuite()
{
    auto renderingSuite = GenerateSuite("��Ⱦ");

    ADD_TEST(renderingSuite, RenderingManagerTesting);

    AddSuite(renderingSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddResourceSuite()
{
    auto resourceSuite = GenerateSuite("��Դ");

    ADD_TEST(resourceSuite, ResourceManagerTesting);

    AddSuite(resourceSuite);
}

void DatabaseGenerateMiddleLayerTesting::TestingHelper::AddSystemSuite()
{
    auto systemSuit = GenerateSuite("ϵͳ");

    ADD_TEST(systemSuit, SystemManagerTesting);

    AddSuite(systemSuit);
}
