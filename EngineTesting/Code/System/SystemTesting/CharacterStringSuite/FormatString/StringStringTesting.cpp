/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:20)

#include "StringStringTesting.h"
#include "System/CharacterString/FormatString.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::StringStringTesting::StringStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StringStringTesting)

void System::StringStringTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StringStringTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringStringTest);
}

void System::StringStringTesting::StringStringTest()
{
    const auto str = "a_subStr_a";
    const auto subStr = "subStr";

    auto result = StringString(str, subStr);

    ASSERT_UNEQUAL_NULL_PTR(result);

    result = StringString(subStr, str);

    ASSERT_EQUAL_NULL_PTR(result);
}
