﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/13 11:32)

#include "AtomicMinMaxTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/AtomicMinMaxDetail.h"
#include "CoreTools/Threading/ThreadGroupDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::AtomicMinMaxTesting::AtomicMinMaxTesting(const OStreamShared& stream)
    : ParentType{ stream }, atomic{ 12 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AtomicMinMaxTesting)

void CoreTools::AtomicMinMaxTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AtomicMinMaxTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AtomicMinThreadTest);
}

void CoreTools::AtomicMinMaxTesting::AtomicMinThreadTest()
{
    auto threadGroup = ThreadGroup::Create();

    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.AddThread(&ClassType::AtomicMaxTest, this);
    }
}

void CoreTools::AtomicMinMaxTesting::AtomicMaxThreadTest()
{
    auto threadGroup = ThreadGroup::Create();

    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.AddThread(&ClassType::AtomicMaxTest, this);
    }
}

void CoreTools::AtomicMinMaxTesting::AtomicMinTest()
{
    constexpr auto value = 11;
    const int oldValue{ atomic };

    const auto result = AtomicMin(atomic, value);

    ASSERT_TRUE(result == value || result == oldValue);
    ASSERT_EQUAL(atomic, value);
}

void CoreTools::AtomicMinMaxTesting::AtomicMaxTest()
{
    constexpr auto value = 15;
    const int oldValue{ atomic };

    const auto result = AtomicMax(atomic, value);

    ASSERT_TRUE(result == value || result == oldValue);
    ASSERT_EQUAL(atomic, value);
}