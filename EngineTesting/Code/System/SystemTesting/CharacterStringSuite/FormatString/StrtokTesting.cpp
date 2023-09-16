///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:14)

#include "StrTokTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using namespace std::literals;

System::StrTokTesting::StrTokTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StrTokTesting)

void System::StrTokTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StrTokTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StrTokTest);
}

void System::StrTokTesting::StrTokTest()
{
    const auto separate = " \t\n"s;
    char* next{ nullptr };
    const auto value = "value\tnullptr\0"s;
    std::vector<char> ext{ value.begin(), value.end() };

    char* token = StrTok(ext.data(), separate.c_str(), &next);
    if (next != nullptr)
    {
        ASSERT_UNEQUAL_NULL_PTR(token);

        ASSERT_EQUAL(*next, 'n');

        token = StrTok(nullptr, separate.c_str(), &next);

        ASSERT_UNEQUAL_NULL_PTR(token);

        token = StrTok(nullptr, separate.c_str(), &next);

        ASSERT_EQUAL_NULL_PTR(token);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("next 为空。"s));
    }
}
