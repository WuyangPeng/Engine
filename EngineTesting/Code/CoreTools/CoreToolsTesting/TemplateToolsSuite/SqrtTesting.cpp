// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:07)

#include "SqrtTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/Sqrt.h"

using std::string;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26812)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, SqrtTesting)

void CoreTools::SqrtTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SqrtTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IfThenElseTest);
}

void CoreTools::SqrtTesting ::SqrtTest()
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

void CoreTools::SqrtTesting ::IfThenElseTest()
{
    [[maybe_unused]] IfThenElse<true, int, string>::ResultType first{ 1 };
    [[maybe_unused]] IfThenElse<false, int, string>::ResultType second{ "second" };
}

#include STSTEM_WARNING_POP