///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/14 15:58)

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
