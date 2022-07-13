///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 16:40)

#include "Helper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

CMainFunctionHelper::Helper::Helper(int argc, char** argv)
    : ParentType{ argc, argv }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CMainFunctionHelper, Helper)

int CMainFunctionHelper::Helper::DoRun()
{
    cout << "argc = " << GetArgc() << endl;
    for (auto i = 0; i < GetArgc(); ++i)
    {
        cout << "argv = " << GetArgv(i) << endl;
    }

    return 0;
}
