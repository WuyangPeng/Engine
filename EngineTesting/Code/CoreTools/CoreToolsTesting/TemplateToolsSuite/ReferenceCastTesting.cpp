///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 19:05)

#include "ReferenceCastTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ReferenceCastDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::string;

CoreTools::ReferenceCastTesting::ReferenceCastTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ReferenceCastTesting)

void CoreTools::ReferenceCastTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ReferenceCastTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
}

void CoreTools::ReferenceCastTesting::CastTest()
{
    constexpr auto firstValue = 2;

    ASSERT_EQUAL(ReferenceCast<int>(firstValue), firstValue);

    string secondValue{ "secondValue" };
    auto thirdValue = static_cast<string&>(ReferenceCast<string>(secondValue));

    ASSERT_EQUAL(thirdValue, secondValue);

    string fourthValue{ ReferenceCast<string>(thirdValue) };

    ASSERT_EQUAL(thirdValue, fourthValue);
}
