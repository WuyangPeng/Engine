///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/02 15:11)

#include "ThreadGuardTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Threading/ThreadGuardDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ThreadGuardTesting::ThreadGuardTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ThreadGuardTesting)

void CoreTools::ThreadGuardTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ThreadGuardTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadGuardTest);
}

void CoreTools::ThreadGuardTesting::ThreadGuardTest()
{
    CreateThread(&ClassType::CallBack);
}

void CoreTools::ThreadGuardTesting::CreateThread(Function function)
{
    ThreadGuard threadGuard{ function, this };
}

void CoreTools::ThreadGuardTesting::CallBack() noexcept
{
}