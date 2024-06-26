/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 17:35)

#include "TestingHelper.h"
#include "UnitTestHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"

#include <iostream>

CMainFunctionHelper::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CMainFunctionHelper, TestingHelper)

int CMainFunctionHelper::TestingHelper::DoRun()
{
    std::cout << "argc = " << GetArgc() << '\n';
    for (auto i = 0; i < GetArgc(); ++i)
    {
        std::cout << "argv = " << GetArgv(i) << '\n';
    }

    const std::string suiteName{ "suiteName" };
    CoreTools::Suite aSuite{ suiteName, CoreTools::OStreamShared{ true }, false };
    const std::string testName{ "testName" };
    const auto unitTest = std::make_shared<UnitTestHelper>(true);

    AddTest(suiteName, aSuite, testName, unitTest);

    return 0;
}
