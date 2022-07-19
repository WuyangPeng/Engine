///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏测试版本：0.8.0.11 (2022/07/19 15:41)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

ThreadingCoreRenderEngineGame::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "引擎游戏测试" }
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
    auto versionSuite = GenerateSuite("版本");

    ADD_TEST(versionSuite, VersionTesting);

    AddSuite(versionSuite);
}

void ThreadingCoreRenderEngineGame::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("引擎");

    ADD_TEST(engineSuite, EngineTesting);

    AddSuite(engineSuite);
}
