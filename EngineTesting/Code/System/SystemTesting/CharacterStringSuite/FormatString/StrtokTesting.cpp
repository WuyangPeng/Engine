///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/30 14:54)

#include "StrtokTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using namespace std::literals;

System::StrtokTesting::StrtokTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StrtokTesting)

void System::StrtokTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StrtokTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StrtokTest);
}

void System::StrtokTesting::StrtokTest()
{
    const auto separate = " \t\n"s;
    char* next{ nullptr };
    const auto value = "value\tnullptr\0"s;
    std::vector<char> ext{ value.begin(), value.end() };

    char* token = Strtok(ext.data(), separate.c_str(), &next);
    if (next != nullptr)
    {
        ASSERT_UNEQUAL_NULL_PTR(token);

        ASSERT_EQUAL(*next, 'n');

        token = Strtok(nullptr, separate.c_str(), &next);

        ASSERT_UNEQUAL_NULL_PTR(token);

        token = Strtok(nullptr, separate.c_str(), &next);

        ASSERT_EQUAL_NULL_PTR(token);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("next 为空。"s));
    }
}
