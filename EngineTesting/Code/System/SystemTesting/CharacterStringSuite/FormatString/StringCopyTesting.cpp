/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:20)

#include "StringCopyTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::StringCopyTesting::StringCopyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StringCopyTesting)

void System::StringCopyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StringCopyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringCopyTest);
}

void System::StringCopyTesting::StringCopyTest()
{
    CharBufferType ext{};
    const auto value = "value"s;

    ASSERT_TRUE(StringCopy(ext.data(), value.size() + 1, value.c_str()));

    const std::string result{ ext.data() };

    ASSERT_EQUAL(result, value);
}
