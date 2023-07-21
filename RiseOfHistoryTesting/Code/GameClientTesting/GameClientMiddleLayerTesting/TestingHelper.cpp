///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/18 18:18)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

GameClientTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "��Ϸ�ͻ����м�����" }
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
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void GameClientTesting::TestingHelper::AddArtificialIntelligenceSuite()
{
    auto artificialIntelligenceSuite = GenerateSuite("�˹�����");

    AddSuite(artificialIntelligenceSuite);
}

void GameClientTesting::TestingHelper::AddAudioSuite()
{
    auto audioSuite = GenerateSuite("��Ч");

    AddSuite(audioSuite);
}

void GameClientTesting::TestingHelper::AddCameraSystemsSuite()
{
    auto cameraSystemsSuite = GenerateSuite("���ϵͳ");

    AddSuite(cameraSystemsSuite);
}

void GameClientTesting::TestingHelper::AddEventSuite()
{
    auto eventSuite = GenerateSuite("�¼�");

    AddSuite(eventSuite);
}

void GameClientTesting::TestingHelper::AddGUISuite()
{
    auto guiSuite = GenerateSuite("�¼�");

    AddSuite(guiSuite);
}

void GameClientTesting::TestingHelper::AddInputSuite()
{
    auto inputSuite = GenerateSuite("����");

    AddSuite(inputSuite);
}

void GameClientTesting::TestingHelper::AddMessageSuite()
{
    auto messageSuite = GenerateSuite("��Ϣ");

    AddSuite(messageSuite);
}

void GameClientTesting::TestingHelper::AddNetworkSuite()
{
    auto networkSuite = GenerateSuite("����");

    AddSuite(networkSuite);
}

void GameClientTesting::TestingHelper::AddObjectLogicSuite()
{
    auto objectLogicSuite = GenerateSuite("�����߼�");

    AddSuite(objectLogicSuite);
}

void GameClientTesting::TestingHelper::AddPhysicalModellingSuite()
{
    auto physicalModellingSuite = GenerateSuite("����ģ");

    AddSuite(physicalModellingSuite);
}

void GameClientTesting::TestingHelper::AddRenderingSuite()
{
    auto renderingSuite = GenerateSuite("��Ⱦ");

    AddSuite(renderingSuite);
}

void GameClientTesting::TestingHelper::AddResourceSuite()
{
    auto resourceSuite = GenerateSuite("��Դ");

    AddSuite(resourceSuite);
}

void GameClientTesting::TestingHelper::AddSystemSuite()
{
    auto systemSuit = GenerateSuite("ϵͳ");

    AddSuite(systemSuit);
}
