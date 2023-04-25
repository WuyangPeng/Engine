///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 15:35)

#include "ScopeExitTesting.h"
#include "CoreTools/Contract/ScopeExitDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ScopeExitTesting::ScopeExitTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ScopeExitTesting)

void CoreTools::ScopeExitTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ScopeExitTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ScopeExitTest);
}

void CoreTools::ScopeExitTesting::ScopeExitTest()
{
    testValue = 0;

    {
        ScopeExit<FunctionType> scopeExit{ &ClassType::AddTestValue };
    }

    ASSERT_EQUAL(testValue, 1);
}

void CoreTools::ScopeExitTesting::AddTestValue() noexcept
{
    ++testValue;
}

int CoreTools::ScopeExitTesting::testValue;
