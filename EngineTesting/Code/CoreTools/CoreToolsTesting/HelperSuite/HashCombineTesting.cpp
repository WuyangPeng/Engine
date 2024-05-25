/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/06 19:59)

#include "HashCombineTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::HashCombineTesting::HashCombineTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, HashCombineTesting)

void CoreTools::HashCombineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::HashCombineTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HashCombineTest);
}

void CoreTools::HashCombineTesting::HashCombineTest()
{
    UnorderedMap container{};

    const TestHashKey testHashKey{ "TestHashKey0" };

    ASSERT_NOT_THROW_EXCEPTION_2(SizeTest, container, testHashKey);
    ASSERT_NOT_THROW_EXCEPTION_2(FindTest, container, testHashKey);
}

void CoreTools::HashCombineTesting::SizeTest(UnorderedMap& container, const TestHashKey& testHashKey)
{
    container.emplace(testHashKey, 1);

    ASSERT_EQUAL(container.size(), 1u);

    container.emplace(TestHashKey{ "TestHashKey1" }, 2);

    ASSERT_EQUAL(container.size(), 2u);
}

void CoreTools::HashCombineTesting::FindTest(UnorderedMap& container, const TestHashKey& testHashKey)
{
    auto iter = container.find(testHashKey);

    ASSERT_UNEQUAL_FAILURE_THROW(iter, container.cend(), "TestHashKey0值未找到。");

    ASSERT_EQUAL(iter->second, 1);

    container.erase(testHashKey);

    ASSERT_EQUAL(container.size(), 1u);

    iter = container.find(testHashKey);

    ASSERT_EQUAL(iter, container.cend());
}