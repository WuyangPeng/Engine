/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 14:43)

#include "SpanIteratorTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::SpanIteratorTesting::SpanIteratorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SpanIteratorTesting)

void CoreTools::SpanIteratorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SpanIteratorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DereferenceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StepTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IncreaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IncreaseArrayTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SubtractionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IterSwapTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetSetValueTest);
}

void CoreTools::SpanIteratorTesting::BaseTest()
{
    std::vector test{ 1, 2, 3, 4, 5, 6, 7 };

    const SpanIterator span{ test.begin(), test.end() };

    ASSERT_EQUAL(span.GetBegin(), test.begin());
    ASSERT_EQUAL(span.GetEnd(), test.end());
    ASSERT_EQUAL(span.GetCurrent(), test.begin());

    ASSERT_EQUAL(span.GetRemainingCount(), boost::numeric_cast<int>(test.size()));

    ASSERT_EQUAL(span.GetData(), test.data());

    ASSERT_EQUAL(span.Get(5), test.begin() + 5);
}

void CoreTools::SpanIteratorTesting::DereferenceTest()
{
    std::vector test{ "1"s, "2"s, "3"s };

    const SpanIterator span{ test.begin(), test.end(), test.begin() };

    ASSERT_EQUAL(*span, test.at(0));
    ASSERT_EQUAL(span->size(), test.at(0).size());
}

void CoreTools::SpanIteratorTesting::StepTest()
{
    std::vector test{ 1, 2, 3, 4, 5, 6, 7 };

    SpanIterator span{ test.begin(), test.end(), test.begin() };

    ASSERT_EQUAL(*span, test.at(0));

    auto result = span++;

    ASSERT_EQUAL(*result, test.at(0));
    ASSERT_EQUAL(*span, test.at(1));

    result = ++span;

    ASSERT_EQUAL(*result, test.at(2));
    ASSERT_EQUAL(*span, test.at(2));

    result = span--;

    ASSERT_EQUAL(*result, test.at(2));
    ASSERT_EQUAL(*span, test.at(1));

    result = --span;

    ASSERT_EQUAL(*result, test.at(0));
    ASSERT_EQUAL(*span, test.at(0));

    span += 3;

    ASSERT_EQUAL(*span, test.at(3));

    span -= 2;

    ASSERT_EQUAL(*span, test.at(1));
}

void CoreTools::SpanIteratorTesting::IncreaseTest()
{
    std::vector<char> test(10);

    SpanIterator span{ test.begin(), test.end(), test.begin() };
    constexpr int32_t increase{ 5 };

    span.Increase(increase);

    span -= sizeof(increase);

    ASSERT_EQUAL(span.Increase<int32_t>(), increase);
}

void CoreTools::SpanIteratorTesting::IncreaseArrayTest()
{
    std::vector test{ 1, 2, 3, 4, 5, 6, 7 };

    SpanIterator span{ test.begin(), test.end() };

    const auto result = span.Increase<int32_t, 5>();
    constexpr std::array testValue{ 1, 2, 3, 4, 5 };

    ASSERT_EQUAL(result, testValue);

    ASSERT_EQUAL(*span.GetCurrent(), 6);

    span.Increase<int32_t, 2>({ 8, 9 });

    ASSERT_EQUAL(span.GetCurrent(), span.GetEnd());

    ASSERT_EQUAL(test.at(5), 8);
    ASSERT_EQUAL(test.at(6), 9);
}

void CoreTools::SpanIteratorTesting::SubtractionTest()
{
    std::vector test{ 1, 2, 3, 4, 5, 6, 7 };

    const SpanIterator span0{ test.begin(), test.end(), test.begin() };
    SpanIterator span1{ test.begin(), test.end(), test.begin() };

    constexpr auto increase = 5;

    span1 += increase;

    ASSERT_EQUAL(span1 - span0, increase);
}

void CoreTools::SpanIteratorTesting::IterSwapTest()
{
    std::vector test{ 1, 2, 3, 4, 5, 6, 7 };

    const SpanIterator span0{ test.begin(), test.end(), test.begin() };
    SpanIterator span1{ test.begin(), test.end(), test.begin() };

    constexpr auto increase = 5;

    span1 += increase;

    IterSwap(span0, span1);

    ASSERT_EQUAL(test.at(0), 6);
    ASSERT_EQUAL(test.at(5), 1);
}

void CoreTools::SpanIteratorTesting::ConstTest()
{
    const std::vector test{ 1, 2, 3, 4, 5, 6, 7 };

    const SpanIterator span{ test.begin(), test.end() };

    ASSERT_EQUAL(span.GetBegin(), test.begin());
    ASSERT_EQUAL(span.GetEnd(), test.end());
    ASSERT_EQUAL(span.GetCurrent(), test.begin());

    ASSERT_EQUAL(span.GetRemainingCount(), boost::numeric_cast<int>(test.size()));
}

void CoreTools::SpanIteratorTesting::GetSetValueTest()
{
    std::vector test{ 1, 2, 3, 4, 5, 6, 7 };

    SpanIterator span{ test.begin(), test.end() };

    const auto value0 = span.GetValue<int32_t>(1);

    ASSERT_EQUAL(value0, 2);

    span.SetValue(2, 8);

    ASSERT_EQUAL(test.at(2), 8);

    const auto value1 = span.GetValue<int32_t, 5>(2);

    constexpr std::array value2{ 8, 4, 5, 6, 7 };

    ASSERT_EQUAL(value1, value2);

    span.SetValue<int32_t, 5>(1, value2);

    const std::vector value3{ 1, 8, 4, 5, 6, 7, 7 };

    ASSERT_EQUAL(test, value3);
}
