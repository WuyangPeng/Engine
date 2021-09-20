///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/25 18:25)

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
        ScopeExit<ClassType::FunctionType> scopeExit{ &ClassType::AddTestValue };
    }

    ASSERT_EQUAL(testValue, 1);
}

void CoreTools::ScopeExitTesting::AddTestValue() noexcept
{
    ++testValue;
}

int CoreTools::ScopeExitTesting::testValue;
