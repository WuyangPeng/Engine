///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/13 11:19)

#include "DllFunctionHelperTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/DllFunctionHelper.h"
#include "CoreTools/Threading/DllMutex.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::DllFunctionHelperTesting::DllFunctionHelperTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DllFunctionHelperTesting)

void CoreTools::DllFunctionHelperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
