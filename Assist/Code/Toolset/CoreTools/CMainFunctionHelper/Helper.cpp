// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/03 22:49)

#include "Helper.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

CMainFunctionHelper::Helper ::Helper(int argc, char** argv)
    : ParentType{ argc, argv }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CMainFunctionHelper, Helper)

int CMainFunctionHelper::Helper ::DoRun()
{
    cout << "argc = " << GetArgc() << endl;
    for (auto i = 0; i < GetArgc(); ++i)
    {
        cout << "argv = " << GetArgv(i) << endl;
    }

    return 0;
}
