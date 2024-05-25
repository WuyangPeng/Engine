/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 17:33)

#include "SpanIteratorTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <numeric>

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
    ASSERT_NOT_THROW_EXCEPTION_0(PrefixPlusTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SuffixPlusTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PrefixSubtractionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SuffixSubtractionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IncreaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IncreaseArrayTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SubtractionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IterSwapTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetSetValueTest);
}

void CoreTools::SpanIteratorTesting::BaseTest()
{
    IntContainer test(size);
    std::iota(test.begin(), test.end(), 0);

    const SpanIterator span{ test.begin(), test.end() };

    ASSERT_EQUAL(span.GetBegin(), test.begin());
    ASSERT_EQUAL(span.GetEnd(), test.end());
    ASSERT_EQUAL(span.GetCurrent(), test.begin());
    ASSERT_EQUAL(span.GetRemainingCount(), boost::numeric_cast<int>(test.size()));
    ASSERT_EQUAL(span.GetData(), test.data());

    for (auto index = 0; index < size; ++index)
    {
        ASSERT_EQUAL(span.Get(index), test.begin() + index);
    }
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
    IntContainer test(size);
    std::iota(test.begin(), test.end(), 0);

    SpanIterator span{ test.begin(), test.end(), test.begin() };
    ASSERT_EQUAL(*span, test.at(0));

    constexpr auto step0 = 5;
    span += step0;
    ASSERT_EQUAL(*span, test.at(step0));

    constexpr auto step1 = 3;
    span -= step1;
    ASSERT_EQUAL(*span, test.at(step0 - step1));
}

void CoreTools::SpanIteratorTesting::PrefixPlusTest()
{
    IntContainer test(size);
    std::iota(test.begin(), test.end(), 0);

    SpanIterator span0{ test.begin(), test.end(), test.begin() };
    ASSERT_EQUAL(*span0, test.at(0));

    auto span1 = ++span0;

    ASSERT_EQUAL(*span1, test.at(1));
    ASSERT_EQUAL(*span0, test.at(1));
    ASSERT_EQUAL(span1.GetCurrent(), span0.GetCurrent());

    span0 = ++span1;

    ASSERT_EQUAL(*span1, test.at(2));
    ASSERT_EQUAL(*span0, test.at(2));
    ASSERT_EQUAL(span1.GetCurrent(), span0.GetCurrent());
}

void CoreTools::SpanIteratorTesting::SuffixPlusTest()
{
    IntContainer test(size);
    std::iota(test.begin(), test.end(), 0);

    SpanIterator span0{ test.begin(), test.end(), test.begin() };
    ASSERT_EQUAL(*span0, test.at(0));

    auto span1 = span0++;

    ASSERT_EQUAL(*span1, test.at(0));
    ASSERT_EQUAL(*span0, test.at(1));
    ASSERT_UNEQUAL(span1.GetCurrent(), span0.GetCurrent());

    const auto span2 = span1++;

    ASSERT_EQUAL(*span2, test.at(0));
    ASSERT_EQUAL(*span1, test.at(1));
    ASSERT_UNEQUAL(span2.GetCurrent(), span1.GetCurrent());
}

void CoreTools::SpanIteratorTesting::PrefixSubtractionTest()
{
    IntContainer test(size);
    std::iota(test.begin(), test.end(), 0);

    constexpr auto beginStep = 5;
    SpanIterator span0{ test.begin(), test.end(), test.begin() + beginStep };

    auto span1 = --span0;

    ASSERT_EQUAL(*span1, test.at(beginStep - 1));
    ASSERT_EQUAL(*span0, test.at(beginStep - 1));
    ASSERT_EQUAL(span1.GetCurrent(), span0.GetCurrent());

    span0 = --span1;

    ASSERT_EQUAL(*span1, test.at(beginStep - 2));
    ASSERT_EQUAL(*span0, test.at(beginStep - 2));
    ASSERT_EQUAL(span1.GetCurrent(), span0.GetCurrent());
}

void CoreTools::SpanIteratorTesting::SuffixSubtractionTest()
{
    IntContainer test(size);
    std::iota(test.begin(), test.end(), 0);

    constexpr auto beginStep = 5;
    SpanIterator span0{ test.begin(), test.end(), test.begin() + beginStep };

    auto span1 = span0--;

    ASSERT_EQUAL(*span1, test.at(beginStep));
    ASSERT_EQUAL(*span0, test.at(beginStep - 1));
    ASSERT_UNEQUAL(span1.GetCurrent(), span0.GetCurrent());

    const auto span2 = span1--;

    ASSERT_EQUAL(*span2, test.at(beginStep));
    ASSERT_EQUAL(*span1, test.at(beginStep - 1));
    ASSERT_UNEQUAL(span1.GetCurrent(), span2.GetCurrent());
}

void CoreTools::SpanIteratorTesting::IncreaseTest()
{
    std::vector<char> test(size);

    SpanIterator span{ test.begin(), test.end(), test.begin() };
    constexpr int32_t increase{ 5 };

    span.Increase(increase);
    span -= sizeof(increase);

    ASSERT_EQUAL(span.Increase<int32_t>(), increase);
}

void CoreTools::SpanIteratorTesting::IncreaseArrayTest()
{
    IntContainer test0(size);
    std::iota(test0.begin(), test0.end(), 1);

    std::array<int32_t, size / 2> test1{};
    std::iota(test1.begin(), test1.end(), 1);

    SpanIterator span{ test0.begin(), test0.end() };
    const auto result = span.Increase<int32_t, size / 2>();

    ASSERT_EQUAL(result, test1);
    ASSERT_EQUAL(*span.GetCurrent(), 6);

    span.Increase<int32_t, size / 2>(test1);

    ASSERT_EQUAL(span.GetCurrent(), span.GetEnd());
    ASSERT_EQUAL(test0.at(5), 1);
    ASSERT_EQUAL(test0.at(6), 2);
}

void CoreTools::SpanIteratorTesting::SubtractionTest()
{
    IntContainer test(size);
    std::iota(test.begin(), test.end(), 0);

    const SpanIterator span0{ test.begin(), test.end(), test.begin() };
    SpanIterator span1{ test.begin(), test.end(), test.begin() };

    constexpr auto increase = 5;

    span1 += increase;

    ASSERT_EQUAL(span1 - span0, increase);
}

void CoreTools::SpanIteratorTesting::IterSwapTest()
{
    IntContainer test(size);
    std::iota(test.begin(), test.end(), 1);

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
    IntContainer test(size);
    std::iota(test.begin(), test.end(), 0);

    const SpanIterator span{ test.begin(), test.end() };

    ASSERT_EQUAL(span.GetBegin(), test.begin());
    ASSERT_EQUAL(span.GetEnd(), test.end());
    ASSERT_EQUAL(span.GetCurrent(), test.begin());
    ASSERT_EQUAL(span.GetRemainingCount(), boost::numeric_cast<int>(test.size()));
}

void CoreTools::SpanIteratorTesting::GetSetValueTest()
{
    IntContainer test(size);
    std::iota(test.begin(), test.end(), 1);

    SpanIterator span{ test.begin(), test.end() };

    const auto value0 = span.GetValue<int32_t>(1);
    ASSERT_EQUAL(value0, 2);

    constexpr auto modify = 8;
    constexpr auto step = 2;

    span.SetValue(step, modify);
    ASSERT_EQUAL(test.at(step), modify);

    const auto value1 = span.GetValue<int32_t, 5>(step);
    constexpr std::array value2{ modify, 4, 5, 6, 7 };
    ASSERT_EQUAL(value1, value2);

    span.SetValue<int32_t, 5>(1, value2);
    const std::vector value3{ 1, modify, 4, 5, 6, 7, 7, 8, 9, 10 };
    ASSERT_EQUAL(test, value3);
}
