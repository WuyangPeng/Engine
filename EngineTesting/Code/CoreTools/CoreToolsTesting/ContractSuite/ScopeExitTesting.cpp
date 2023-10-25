///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 16:56)

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
