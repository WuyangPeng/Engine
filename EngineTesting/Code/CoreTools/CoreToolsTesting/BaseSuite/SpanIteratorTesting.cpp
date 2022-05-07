///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/27 13:52)

#include "SpanIteratorTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;
using std::vector;

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
    ASSERT_NOT_THROW_EXCEPTION_0(SubtractionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IterSwapTest);
}

void CoreTools::SpanIteratorTesting::BaseTest()
{
    vector<int> test{ 1, 2, 3, 4, 5, 6, 7 };

    using SpanIterator = SpanIterator<vector<int>::iterator>;

    const SpanIterator span{ test.begin(), test.end() };

    ASSERT_EQUAL(span.GetBegin(), test.begin());
    ASSERT_EQUAL(span.GetEnd(), test.end());
    ASSERT_EQUAL(span.GetCurrent(), test.begin());

    ASSERT_EQUAL(span.GetRemainingCount(), boost::numeric_cast<int>(test.size()));
}

void CoreTools::SpanIteratorTesting::DereferenceTest()
{
    vector<string> test{ "1", "2", "3" };

    using SpanIterator = SpanIterator<vector<string>::iterator>;

    const SpanIterator span{ test.begin(), test.end(), test.begin() };

    ASSERT_EQUAL(*span, test.at(0));
    ASSERT_EQUAL(span->size(), test.at(0).size());
}

void CoreTools::SpanIteratorTesting::StepTest()
{
    vector<int> test{ 1, 2, 3, 4, 5, 6, 7 };

    using SpanIterator = SpanIterator<vector<int>::iterator>;

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
    vector<char> test(10);

    using SpanIterator = SpanIterator<vector<char>::iterator>;

    SpanIterator span{ test.begin(), test.end(), test.begin() };
    constexpr int32_t increase{ 5 };

    span.Increase(increase);

    span -= sizeof(increase);

    ASSERT_EQUAL(span.Increase<int32_t>(), increase);
}

void CoreTools::SpanIteratorTesting::SubtractionTest()
{
    vector<int> test{ 1, 2, 3, 4, 5, 6, 7 };

    using SpanIterator = SpanIterator<vector<int>::iterator>;

    const SpanIterator span0{ test.begin(), test.end(), test.begin() };
    SpanIterator span1{ test.begin(), test.end(), test.begin() };

    constexpr auto increase = 5;

    span1 += increase;

    ASSERT_EQUAL(span1 - span0, increase);
}

void CoreTools::SpanIteratorTesting::IterSwapTest()
{
    vector<int> test{ 1, 2, 3, 4, 5, 6, 7 };

    using SpanIterator = SpanIterator<vector<int>::iterator>;

    const SpanIterator span0{ test.begin(), test.end(), test.begin() };
    SpanIterator span1{ test.begin(), test.end(), test.begin() };

    constexpr auto increase = 5;

    span1 += increase;

    IterSwap(span0, span1);

    ASSERT_EQUAL(test.at(0), 6);
    ASSERT_EQUAL(test.at(5), 1);
}