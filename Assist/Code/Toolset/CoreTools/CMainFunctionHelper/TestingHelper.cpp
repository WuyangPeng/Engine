///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 16:39)

#include "TestingHelper.h"
#include "UnitTestHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::make_shared;
using std::string;

CMainFunctionHelper::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CMainFunctionHelper, TestingHelper)

int CMainFunctionHelper::TestingHelper::DoRun()
{
    cout << "argc = " << GetArgc() << endl;
    for (auto i = 0; i < GetArgc(); ++i)
    {
        cout << "argv = " << GetArgv(i) << endl;
    }

    string suiteName{ "suiteName" };
    CoreTools::Suite suite{ suiteName, CoreTools::OStreamShared{ true }, false };
    string testName{ "testName" };
    UnitTestSharedPtr unitTest{ make_shared<UnitTestHelper>(true) };

    AddTest(suiteName, suite, testName, unitTest);

    return 0;
}
