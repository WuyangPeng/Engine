/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 15:23)

#include "ToStringTesting.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define OPEN_TO_STRING_ERROR
#undef OPEN_TO_STRING_ERROR

using namespace std::literals;

System::ToStringTesting::ToStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ToStringTesting)

void System::ToStringTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ToStringTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ToStringTest);
}

void System::ToStringTesting::ToStringTest()
{
    const auto value = ToString(2);

    ASSERT_EQUAL(value, SYSTEM_TEXT("2"s));

#ifdef OPEN_TO_STRING_ERROR

    const auto error = ToString("2");

#endif  // OPEN_TO_STRING_ERROR
}
