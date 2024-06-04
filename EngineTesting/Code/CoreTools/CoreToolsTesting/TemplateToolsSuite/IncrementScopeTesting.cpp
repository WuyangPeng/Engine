/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:36)

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

    ASSERT_NOT_THROW_EXCEPTION_1(Scope0Test, value);

    ASSERT_EQUAL(value, 0);

    ASSERT_NOT_THROW_EXCEPTION_1(Scope1Test, value);

    ASSERT_EQUAL(value, 0);
}

void CoreTools::IncrementScopeTesting::Scope0Test(int& value)
{
    IncrementScope incrementScope{ value };

    ASSERT_EQUAL(value, 1);
}

void CoreTools::IncrementScopeTesting::Scope1Test(int& value)
{
    IncrementScope<int, SimpleDecrementer<int>, SimpleIncrementer<int>> incrementScope{ value };

    ASSERT_EQUAL(value, -1);
}
