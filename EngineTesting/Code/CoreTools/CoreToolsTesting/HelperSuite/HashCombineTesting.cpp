///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/18 18:15)

#include "HashCombineTesting.h"
#include "Detail/TestHash.h"
#include "Detail/TestHashKey.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <unordered_map>

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
    std::unordered_map<TestHashKey, int, TestHash> container{};

    const TestHashKey testHashKey{ "TestHashKey1" };
    container.emplace(testHashKey, 1);

    ASSERT_EQUAL(container.size(), 1);

    container.emplace(TestHashKey{ "TestHashKey2" }, 2);

    ASSERT_EQUAL(container.size(), 2);

    auto iter = container.find(testHashKey);

    ASSERT_UNEQUAL_FAILURE_THROW(iter, container.cend(), "TestHashKey1值未找到。");

    ASSERT_EQUAL(iter->second, 1);

    container.erase(testHashKey);

    ASSERT_EQUAL(container.size(), 1);

    iter = container.find(testHashKey);

    ASSERT_EQUAL(iter, container.cend());
}
