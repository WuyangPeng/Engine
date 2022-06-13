///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 18:56)

#include "DllFunctionHelperTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/DllFunctionHelper.h"
#include "CoreTools/Threading/DllMutex.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, DllFunctionHelperTesting)

void CoreTools::DllFunctionHelperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DllMutexTest);
}

void CoreTools::DllFunctionHelperTesting::DllMutexTest()
{
    DllMutex mutex{ CoreTools::MutexCreate::UseCriticalSection };

    DllFunctionHelper::InitializeMutex(&mutex);
    DllFunctionHelper::DeleteMutex(&mutex);
}
