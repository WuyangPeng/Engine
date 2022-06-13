///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 19:05)

#include "SqrtTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/Sqrt.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, SqrtTesting)

void CoreTools::SqrtTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SqrtTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IfThenElseTest);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26812)

void CoreTools::SqrtTesting::SqrtTest()
{
    ASSERT_EQUAL(SqrtFirstAlgorithm<16>::Result, 4);
    ASSERT_EQUAL(SqrtFirstAlgorithm<25>::Result, 5);
    ASSERT_EQUAL(SqrtFirstAlgorithm<42>::Result, 6);
    ASSERT_EQUAL(SqrtFirstAlgorithm<1>::Result, 1);

    ASSERT_EQUAL(SqrtSecondAlgorithm<16>::Result, 4);
    ASSERT_EQUAL(SqrtSecondAlgorithm<25>::Result, 5);
    ASSERT_EQUAL(SqrtSecondAlgorithm<42>::Result, 6);
    ASSERT_EQUAL(SqrtSecondAlgorithm<1>::Result, 1);

    ASSERT_EQUAL(SqrtThirdAlgorithm<16>::Result, 4);
    ASSERT_EQUAL(SqrtThirdAlgorithm<25>::Result, 5);
    ASSERT_EQUAL(SqrtThirdAlgorithm<42>::Result, 7);
    ASSERT_EQUAL(SqrtThirdAlgorithm<48>::Result, 7);
    ASSERT_EQUAL(SqrtThirdAlgorithm<1>::Result, 1);

    ASSERT_EQUAL(SqrtFourthAlgorithm<16>::Result, 4);
    ASSERT_EQUAL(SqrtFourthAlgorithm<25>::Result, 5);
    ASSERT_EQUAL(SqrtFourthAlgorithm<42>::Result, 7);
    ASSERT_EQUAL(SqrtFourthAlgorithm<50>::Result, 8);
    ASSERT_EQUAL(SqrtFourthAlgorithm<1>::Result, 1);
}

#include STSTEM_WARNING_POP

void CoreTools::SqrtTesting::IfThenElseTest()
{
    MAYBE_UNUSED IfThenElse<true, int, string>::ResultType first{ 1 };
    MAYBE_UNUSED IfThenElse<false, int, string>::ResultType second{ "second" };
}
