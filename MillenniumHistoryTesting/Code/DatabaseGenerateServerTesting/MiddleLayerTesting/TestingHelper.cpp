///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/19 22:31)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

DatabaseGenerateServerTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���ݿ����ɷ������м�����" }
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
    auto helperSuite = GenerateSuite("����");

    AddSuite(helperSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddArtificialIntelligenceSuite()
{
    auto artificialIntelligenceSuite = GenerateSuite("�˹�����");

    AddSuite(artificialIntelligenceSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddAudioSuite()
{
    auto audioSuite = GenerateSuite("��Ч");

    AddSuite(audioSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddCameraSystemsSuite()
{
    auto cameraSystemsSuite = GenerateSuite("���ϵͳ");

    AddSuite(cameraSystemsSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddEventSuite()
{
    auto eventSuite = GenerateSuite("�¼�");

    AddSuite(eventSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddGUISuite()
{
    auto guiSuite = GenerateSuite("�¼�");

    AddSuite(guiSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddInputSuite()
{
    auto inputSuite = GenerateSuite("����");

    AddSuite(inputSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddMessageSuite()
{
    auto messageSuite = GenerateSuite("��Ϣ");

    AddSuite(messageSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddNetworkSuite()
{
    auto networkSuite = GenerateSuite("����");

    AddSuite(networkSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddObjectLogicSuite()
{
    auto objectLogicSuite = GenerateSuite("�����߼�");

    AddSuite(objectLogicSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddPhysicalModellingSuite()
{
    auto physicalModellingSuite = GenerateSuite("����ģ");

    AddSuite(physicalModellingSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddRenderingSuite()
{
    auto renderingSuite = GenerateSuite("��Ⱦ");

    AddSuite(renderingSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddResourceSuite()
{
    auto resourceSuite = GenerateSuite("��Դ");

    AddSuite(resourceSuite);
}

void DatabaseGenerateServerTesting::TestingHelper::AddSystemSuite()
{
    auto systemSuit = GenerateSuite("ϵͳ");

    AddSuite(systemSuit);
}
