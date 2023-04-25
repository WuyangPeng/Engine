///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/13 11:19)

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
