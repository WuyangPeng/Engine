///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起测试版本：0.8.1.0 (2022/08/03 13:41)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"

RiseOfHistory::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "历史的崛起测试" }
{
    InitSuite();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RiseOfHistory, TestingHelper)

void RiseOfHistory::TestingHelper::InitSuite()
{
    AddVersionSuite();
    AddEngineSuite();
}

void RiseOfHistory::TestingHelper::AddVersionSuite()
{
    auto versionSuite = GenerateSuite("版本");

    ADD_TEST(versionSuite, VersionTesting);

    AddSuite(versionSuite);
}

void RiseOfHistory::TestingHelper::AddEngineSuite()
{
    auto engineSuite = GenerateSuite("引擎");

    ADD_TEST(engineSuite, EngineTesting);

    AddSuite(engineSuite);
}
