/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:16)

#include "FormatStringMessageUseVaListAndLocalAllocTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <cstdarg>

System::FormatStringMessageUseVaListAndLocalAllocTesting::FormatStringMessageUseVaListAndLocalAllocTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatStringMessageUseVaListAndLocalAllocTesting)

void System::FormatStringMessageUseVaListAndLocalAllocTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatStringMessageUseVaListAndLocalAllocTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FormatStringMessageUseVaListAndLocalAllocTest);
}

void System::FormatStringMessageUseVaListAndLocalAllocTesting::FormatStringMessageUseVaListAndLocalAllocTest()
{
    const auto message = GetMessageVaList();
    FormatStringMessageUseIndefiniteParameterTest(message.c_str(), 4, 2, SYSTEM_TEXT("Bill"), SYSTEM_TEXT("Bob"), 6, SYSTEM_TEXT("Bill"));
}

void System::FormatStringMessageUseVaListAndLocalAllocTesting::FormatStringMessageUseIndefiniteParameterTest(const TChar* message, ...)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26826)

    va_list vaArguments{};
    va_start(vaArguments, message);

    WindowsHLocal resultMessage{ nullptr };

    ASSERT_NOT_THROW_EXCEPTION_3(FormatStringMessageUseArgumentsTest, resultMessage, message, vaArguments);

    ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, resultMessage);

    va_end(vaArguments);

#include SYSTEM_WARNING_POP
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26826)

void System::FormatStringMessageUseVaListAndLocalAllocTesting::FormatStringMessageUseArgumentsTest(WindowsHLocal& resultMessage, const TChar* message, va_list vaArguments)
{
    const auto size = System::FormatStringMessage(message, resultMessage, vaArguments);
    ASSERT_LESS(0u, size);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(resultMessage, "FormatStringMessage 失败。");

    const String testMessage{ static_cast<TChar*>(resultMessage) };

    ASSERT_EQUAL(testMessage.size(), size);
    ASSERT_EQUAL(testMessage, GetMessageVaListResult());
}

#include SYSTEM_WARNING_POP