/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 17:35)

#include "Helper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <iostream>

CMainFunctionHelper::Helper::Helper(int argc, char** argv)
    : ParentType{ argc, argv }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CMainFunctionHelper, Helper)

int CMainFunctionHelper::Helper::DoRun()
{
    std::cout << "argc = " << GetArgc() << std::endl;
    for (auto i = 0; i < GetArgc(); ++i)
    {
        std::cout << "argv = " << GetArgv(i) << std::endl;
    }

    return 0;
}
