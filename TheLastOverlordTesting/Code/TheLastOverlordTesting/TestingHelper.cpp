///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	最后的霸王测试版本：0.7.0.1 (2021/02/18 19:04)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

TheLastOverlord::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "最后的霸王测试" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(TheLastOverlord, TestingHelper)

void TheLastOverlord::TestingHelper::InitSuite()
{
    AddVersionSuite();
    AddEngineSuite();
}

void TheLastOverlord::TestingHelper::AddVersionSuite()
{
    auto versionSuite = GenerateSuite("版本");

    ADD_TEST(versionSuite, VersionTesting);

    AddSuite(versionSuite);
}

void TheLastOverlord::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("引擎");

    ADD_TEST(engineSuite, EngineTesting);

    AddSuite(engineSuite);
}
