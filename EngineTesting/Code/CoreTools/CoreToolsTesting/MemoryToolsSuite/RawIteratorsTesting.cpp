///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/13 11:29)

#include "RawIteratorsTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/RawIteratorsDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::RawIteratorsTesting::RawIteratorsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RawIteratorsTesting)

void CoreTools::RawIteratorsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::RawIteratorsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RawConstIteratorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RawIteratorTest);
}

void CoreTools::RawIteratorsTesting::RawConstIteratorTest()
{
    std::vector<int> container{};
    for (auto i = 0; i < 20; ++i)
    {
        container.emplace_back(i);
    }

    RawConstIterator rawConstIterator{ container.data() };

    ASSERT_EQUAL(*rawConstIterator, 0);

    auto result = ++rawConstIterator;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawConstIterator, 1);
    ASSERT_EQUAL(rawConstIterator, result);
    ASSERT_EQUAL(rawConstIterator - result, 0);
    ASSERT_LESS_EQUAL(result, rawConstIterator);

    result = rawConstIterator++;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawConstIterator, 2);
    ASSERT_UNEQUAL(rawConstIterator, result);
    ASSERT_EQUAL(rawConstIterator - result, 1);
    ASSERT_LESS(result, rawConstIterator);

    result = --rawConstIterator;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawConstIterator, 1);
    ASSERT_EQUAL(rawConstIterator, result);
    ASSERT_EQUAL(rawConstIterator - result, 0);
    ASSERT_LESS_EQUAL(result, rawConstIterator);

    result = rawConstIterator--;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawConstIterator, 0);
    ASSERT_UNEQUAL(rawConstIterator, result);
    ASSERT_EQUAL(rawConstIterator - result, -1);
    ASSERT_GREATER(result, rawConstIterator);

    rawConstIterator += 5;
    ASSERT_EQUAL(*rawConstIterator, 5);

    result = rawConstIterator + 5;
    ASSERT_EQUAL(*result, 10);

    rawConstIterator -= 2;
    ASSERT_EQUAL(*rawConstIterator, 3);

    result = rawConstIterator - 1;
    ASSERT_EQUAL(*result, 2);
}

void CoreTools::RawIteratorsTesting::RawIteratorTest()
{
    std::vector<int> container{};
    for (auto i = 0; i < 20; ++i)
    {
        container.emplace_back(i);
    }

    RawIterator rawIterator{ container.data() };

    ASSERT_EQUAL(*rawIterator, 0);

    auto result = ++rawIterator;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawIterator, 1);
    ASSERT_EQUAL(rawIterator, result);
    ASSERT_LESS_EQUAL(result, rawIterator);

    result = rawIterator++;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawIterator, 2);
    ASSERT_UNEQUAL(rawIterator, result);
    ASSERT_LESS(result, rawIterator);

    result = --rawIterator;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawIterator, 1);
    ASSERT_EQUAL(rawIterator, result);
    ASSERT_LESS_EQUAL(result, rawIterator);

    result = rawIterator--;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawIterator, 0);
    ASSERT_UNEQUAL(rawIterator, result);
    ASSERT_GREATER(result, rawIterator);

    rawIterator += 5;
    ASSERT_EQUAL(*rawIterator, 5);

    result = rawIterator + 5;
    ASSERT_EQUAL(*result, 10);

    rawIterator -= 2;
    ASSERT_EQUAL(*rawIterator, 3);

    result = rawIterator - 1;
    ASSERT_EQUAL(*result, 2);
}