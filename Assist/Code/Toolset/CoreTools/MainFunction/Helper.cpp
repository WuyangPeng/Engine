///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:48)

#include "Helper.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

CORE_TOOLS_MUTEX_EXTERN(MainFuction);

MainFunction::Helper::Helper(int argc, char** argv)
{
    System::UnusedFunction(argc, argv);

    auto& dllMutex = GetMainFuctionMutex();

    dllMutex.Initialize();
}

MainFunction::Helper::~Helper() noexcept
{
    EXCEPTION_TRY
    {
        auto& dllMutex = GetMainFuctionMutex();

        dllMutex.Delete();
    }
    EXCEPTION_ALL_CATCH(CoreTools)
}

int MainFunction::Helper::Run()
{
    auto& dllMutex = GetMainFuctionMutex();

    dllMutex.Enter();
    dllMutex.Leave();

    return 0;
}
