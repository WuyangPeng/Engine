/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:20)

#include "StringCatTesting.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::StringCatTesting::StringCatTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StringCatTesting)

void System::StringCatTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StringCatTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringCatTest);
}

void System::StringCatTesting::StringCatTest()
{
    const auto result = "2strcat4"s;

    CharBufferType buffer{ '2' };

    ASSERT_TRUE(StringCat(buffer.data(), defaultBufferSize, "strcat4"));

    ASSERT_EQUAL(std::string{ buffer.data() }, result);
}
