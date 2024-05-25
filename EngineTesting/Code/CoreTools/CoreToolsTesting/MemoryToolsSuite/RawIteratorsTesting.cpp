/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/18 20:15)

#include "RawIteratorsTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/RawIteratorsDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <numeric>

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
    ContainerType container(size);
    std::iota(container.begin(), container.end(), 0);

    RawConstIterator rawConstIterator{ container.data() };

    ASSERT_EQUAL(*rawConstIterator, 0);

    ASSERT_NOT_THROW_EXCEPTION_1(ConstPrefixAdditionOperatorTest, rawConstIterator);
    ASSERT_NOT_THROW_EXCEPTION_1(ConstSuffixAdditionOperatorTest, rawConstIterator);
    ASSERT_NOT_THROW_EXCEPTION_1(ConstPrefixSubtractionOperatorTest, rawConstIterator);
    ASSERT_NOT_THROW_EXCEPTION_1(ConstSuffixSubtractionOperatorTest, rawConstIterator);
    ASSERT_NOT_THROW_EXCEPTION_1(ConstAdditionOperatorTest, rawConstIterator);
    ASSERT_NOT_THROW_EXCEPTION_1(ConstSubtractionOperatorTest, rawConstIterator);
}

void CoreTools::RawIteratorsTesting::ConstPrefixAdditionOperatorTest(RawConstIteratorType& rawConstIterator)
{
    const auto result = ++rawConstIterator;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawConstIterator, 1);
    ASSERT_EQUAL(rawConstIterator, result);
    ASSERT_EQUAL(rawConstIterator - result, 0);
    ASSERT_LESS_EQUAL(result, rawConstIterator);
}

void CoreTools::RawIteratorsTesting::ConstSuffixAdditionOperatorTest(RawConstIteratorType& rawConstIterator)
{
    const auto result = rawConstIterator++;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawConstIterator, 2);
    ASSERT_UNEQUAL(rawConstIterator, result);
    ASSERT_EQUAL(rawConstIterator - result, 1);
    ASSERT_LESS(result, rawConstIterator);
}

void CoreTools::RawIteratorsTesting::ConstPrefixSubtractionOperatorTest(RawConstIteratorType& rawConstIterator)
{
    const auto result = --rawConstIterator;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawConstIterator, 1);
    ASSERT_EQUAL(rawConstIterator, result);
    ASSERT_EQUAL(rawConstIterator - result, 0);
    ASSERT_LESS_EQUAL(result, rawConstIterator);
}

void CoreTools::RawIteratorsTesting::ConstSuffixSubtractionOperatorTest(RawConstIteratorType& rawConstIterator)
{
    const auto result = rawConstIterator--;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawConstIterator, 0);
    ASSERT_UNEQUAL(rawConstIterator, result);
    ASSERT_EQUAL(rawConstIterator - result, -1);
    ASSERT_GREATER(result, rawConstIterator);
}

void CoreTools::RawIteratorsTesting::ConstAdditionOperatorTest(RawConstIteratorType& rawConstIterator)
{
    rawConstIterator += 5;
    ASSERT_EQUAL(*rawConstIterator, 5);

    const auto result = rawConstIterator + 5;
    ASSERT_EQUAL(*result, 10);
}

void CoreTools::RawIteratorsTesting::ConstSubtractionOperatorTest(RawConstIteratorType& rawConstIterator)
{
    rawConstIterator -= 2;
    ASSERT_EQUAL(*rawConstIterator, 3);

    const auto result = rawConstIterator - 1;
    ASSERT_EQUAL(*result, 2);
}

void CoreTools::RawIteratorsTesting::RawIteratorTest()
{
    ContainerType container(size);
    std::iota(container.begin(), container.end(), 0);

    RawIterator rawIterator{ container.data() };

    ASSERT_EQUAL(*rawIterator, 0);

    ASSERT_NOT_THROW_EXCEPTION_1(PrefixAdditionOperatorTest, rawIterator);
    ASSERT_NOT_THROW_EXCEPTION_1(SuffixAdditionOperatorTest, rawIterator);
    ASSERT_NOT_THROW_EXCEPTION_1(PrefixSubtractionOperatorTest, rawIterator);
    ASSERT_NOT_THROW_EXCEPTION_1(SuffixSubtractionOperatorTest, rawIterator);
    ASSERT_NOT_THROW_EXCEPTION_1(AdditionOperatorTest, rawIterator);
    ASSERT_NOT_THROW_EXCEPTION_1(SubtractionOperatorTest, rawIterator);
}

void CoreTools::RawIteratorsTesting::PrefixAdditionOperatorTest(RawIteratorType& rawIterator)
{
    auto result = ++rawIterator;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawIterator, 1);
    ASSERT_EQUAL(rawIterator, result);
    ASSERT_LESS_EQUAL(result, rawIterator);
    ASSERT_EQUAL(rawIterator - result, 0);
}

void CoreTools::RawIteratorsTesting::SuffixAdditionOperatorTest(RawIteratorType& rawIterator)
{
    auto result = rawIterator++;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawIterator, 2);
    ASSERT_UNEQUAL(rawIterator, result);
    ASSERT_LESS(result, rawIterator);
    ASSERT_EQUAL(rawIterator - result, 1);
}

void CoreTools::RawIteratorsTesting::PrefixSubtractionOperatorTest(RawIteratorType& rawIterator)
{
    auto result = --rawIterator;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawIterator, 1);
    ASSERT_EQUAL(rawIterator, result);
    ASSERT_LESS_EQUAL(result, rawIterator);
    ASSERT_EQUAL(rawIterator - result, 0);
}

void CoreTools::RawIteratorsTesting::SuffixSubtractionOperatorTest(RawIteratorType& rawIterator)
{
    auto result = rawIterator--;

    ASSERT_EQUAL(*result, 1);
    ASSERT_EQUAL(*rawIterator, 0);
    ASSERT_UNEQUAL(rawIterator, result);
    ASSERT_GREATER(result, rawIterator);
    ASSERT_EQUAL(rawIterator - result, -1);
}

void CoreTools::RawIteratorsTesting::AdditionOperatorTest(RawIteratorType& rawIterator)
{
    rawIterator += 5;
    ASSERT_EQUAL(*rawIterator, 5);

    auto result = rawIterator + 5;
    ASSERT_EQUAL(*result, 10);
}

void CoreTools::RawIteratorsTesting::SubtractionOperatorTest(RawIteratorType& rawIterator)
{
    rawIterator -= 2;
    ASSERT_EQUAL(*rawIterator, 3);

    auto result = rawIterator - 1;
    ASSERT_EQUAL(*result, 2);
}