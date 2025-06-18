/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.1 (2025/04/30 11:30)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

ThreadingCoreRenderEngine::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "引擎测试" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngine, TestingHelper)

void ThreadingCoreRenderEngine::TestingHelper::InitSuite()
{
    AddVersionSuite();
    AddEngineSuite();
}

void ThreadingCoreRenderEngine::TestingHelper::AddVersionSuite()
{
    auto versionSuite = GenerateSuite("版本");

    ADD_TEST(versionSuite, VersionTesting);

    AddSuite(versionSuite);
}

void ThreadingCoreRenderEngine::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("引擎");

    ADD_TEST(engineSuite, EngineTesting);

    AddSuite(engineSuite);
}