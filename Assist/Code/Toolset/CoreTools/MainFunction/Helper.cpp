///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/15 11:30)

#include "Helper.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

CORE_TOOLS_MUTEX_EXTERN(MainFuction);

MainFuction::Helper::Helper(MAYBE_UNUSED int argc, MAYBE_UNUSED char** argv)
{
    auto& dllMutex = GetMainFuctionMutex();

    dllMutex.Initialize();
}

MainFuction::Helper::~Helper() noexcept
{
    EXCEPTION_TRY
    {
        auto& dllMutex = GetMainFuctionMutex();

        dllMutex.Delete();
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

int MainFuction::Helper::Run()
{
    auto& dllMutex = GetMainFuctionMutex();

    dllMutex.Enter();
    dllMutex.Leave();

    return 0;
}
