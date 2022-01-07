// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/03 22:50)

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

CMainFunctionHelper::TestingHelper ::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CMainFunctionHelper, TestingHelper)

int CMainFunctionHelper::TestingHelper ::DoRun()
{
    cout << "argc = " << GetArgc() << endl;
    for (auto i = 0; i < GetArgc(); ++i)
    {
        cout << "argv = " << GetArgv(i) << endl;
    }

    string suiteName{ "suiteName" };
    CoreTools::Suite suite{ suiteName, CoreTools::OStreamShared{ true }, false };
    string testName{ "testName" };
    UnitTestSharedPtr unitTest{ make_shared<UnitTestHelper>() };

    AddTest(suiteName, suite, testName, unitTest);

    return 0;
}
