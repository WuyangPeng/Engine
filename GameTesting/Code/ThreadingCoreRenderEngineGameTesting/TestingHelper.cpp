///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ���԰汾��0.8.0.11 (2022/07/19 15:41)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

ThreadingCoreRenderEngineGame::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "������Ϸ����" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngineGame, TestingHelper)

void ThreadingCoreRenderEngineGame::TestingHelper::InitSuite()
{
    AddVersionSuite();
    AddEngineSuite();
}

void ThreadingCoreRenderEngineGame::TestingHelper::AddVersionSuite()
{
    auto versionSuite = GenerateSuite("�汾");

    ADD_TEST(versionSuite, VersionTesting);

    AddSuite(versionSuite);
}

void ThreadingCoreRenderEngineGame::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("����");

    ADD_TEST(engineSuite, EngineTesting);

    AddSuite(engineSuite);
}
