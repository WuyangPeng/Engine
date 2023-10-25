///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:34)

#include "IncrementScopeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/IncrementScopeDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::IncrementScopeTesting::IncrementScopeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, IncrementScopeTesting)

void CoreTools::IncrementScopeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::IncrementScopeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ScopeTest);
}

void CoreTools::IncrementScopeTesting::ScopeTest()
{
    auto value = 0;

    ASSERT_EQUAL(value, 0);

    {
        IncrementScope incrementScope{ value };

        ASSERT_EQUAL(value, 1);
    }

    ASSERT_EQUAL(value, 0);

    {
        IncrementScope<int, SimpleDecrementer<int>, SimpleIncrementer<int>> incrementScope{ value };

        ASSERT_EQUAL(value, -1);
    }

    ASSERT_EQUAL(value, 0);
}
