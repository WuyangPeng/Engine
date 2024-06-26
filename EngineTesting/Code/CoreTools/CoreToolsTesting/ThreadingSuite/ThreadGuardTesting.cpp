/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 15:23)

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