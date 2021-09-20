// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 16:06)

#include "ReferenceCastTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ReferenceCastDetail.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, ReferenceCastTesting)

void CoreTools::ReferenceCastTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
}

void CoreTools::ReferenceCastTesting ::CastTest()
{
    constexpr auto firstValue = 2;

    ASSERT_EQUAL(ReferenceCast<int>(firstValue), firstValue);

    string secondValue{ "secondValue" };
    auto thirdValue = static_cast<string&>(ReferenceCast<string>(secondValue));

    ASSERT_EQUAL(thirdValue, secondValue);

    string fourthValue{ ReferenceCast<string>(thirdValue) };

    ASSERT_EQUAL(thirdValue, fourthValue);
}
