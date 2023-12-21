/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 20:02)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

TheLastOverlordTesting::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "最后的霸王单元测试" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(TheLastOverlordTesting, TestingHelper)

void TheLastOverlordTesting::TestingHelper::InitSuite()
{
    AddVersionSuite();
    AddEngineSuite();
}

void TheLastOverlordTesting::TestingHelper::AddVersionSuite()
{
    auto versionSuite = GenerateSuite("版本");

    ADD_TEST(versionSuite, VersionTesting);

    AddSuite(versionSuite);
}

void TheLastOverlordTesting::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("引擎");

    ADD_TEST(engineSuite, EngineTesting);

    AddSuite(engineSuite);
}
