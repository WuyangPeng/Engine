///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:13)

#include "StrStrTesting.h"
#include "System/CharacterString/FormatString.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::StrStrTesting::StrStrTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StrStrTesting)

void System::StrStrTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StrStrTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StrStrTest);
}

void System::StrStrTesting::StrStrTest()
{
    const auto str = "asubStra";
    const auto subStr = "subStr";

    auto result = StrStr(str, subStr);

    ASSERT_UNEQUAL_NULL_PTR(result);

    result = StrStr(subStr, str);

    ASSERT_EQUAL_NULL_PTR(result);
}
