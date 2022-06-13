///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 19:02)

#include "IncrementScopeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/IncrementScopeDetail.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, IncrementScopeTesting)

void CoreTools::IncrementScopeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ScopeTest);
}

void CoreTools::IncrementScopeTesting::ScopeTest()
{
    auto value = 0;

    ASSERT_EQUAL(value, 0);

    {
        IncrementScope<int> incrementScope(value);

        ASSERT_EQUAL(value, 1);
    }

    ASSERT_EQUAL(value, 0);

    {
        IncrementScope<int, SimpleDecrementer<int>, SimpleIncrementer<int>> incrementScope(value);

        ASSERT_EQUAL(value, -1);
    }

    ASSERT_EQUAL(value, 0);
}
