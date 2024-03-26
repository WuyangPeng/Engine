/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:21)

#include "StringTokenTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using namespace std::literals;

System::StringTokenTesting::StringTokenTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StringTokenTesting)

void System::StringTokenTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StringTokenTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringTokenTest);
}

void System::StringTokenTesting::StringTokenTest()
{
    const auto separate = " \t\n"s;
    char* next{ nullptr };
    const auto value = "value\tnullptr\0"s;
    std::vector<char> ext{ value.begin(), value.end() };

    char* token = StringToken(ext.data(), separate.c_str(), &next);
    ASSERT_NOT_THROW_EXCEPTION_3(DoStringTokenTest, separate, next, token);
}

void System::StringTokenTesting::DoStringTokenTest(const std::string& separate, char* next, char* token)
{
    if (next != nullptr)
    {
        ASSERT_UNEQUAL_NULL_PTR(token);

        ASSERT_EQUAL(*next, 'n');

        token = StringToken(nullptr, separate.c_str(), &next);

        ASSERT_UNEQUAL_NULL_PTR(token);

        token = StringToken(nullptr, separate.c_str(), &next);

        ASSERT_EQUAL_NULL_PTR(token);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("next 为空。"s));
    }
}