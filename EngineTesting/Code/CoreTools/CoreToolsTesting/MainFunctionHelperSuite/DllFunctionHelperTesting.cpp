///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 18:56)

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
