/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:17)

#include "FormatStringMessageUseVaListAndUseBufferTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatStringMessageUseVaListAndUseBufferTesting::FormatStringMessageUseVaListAndUseBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatStringMessageUseVaListAndUseBufferTesting)

void System::FormatStringMessageUseVaListAndUseBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatStringMessageUseVaListAndUseBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FormatStringMessageUseVaListAndUseBufferTest);
}

void System::FormatStringMessageUseVaListAndUseBufferTesting::FormatStringMessageUseVaListAndUseBufferTest()
{
    const auto message = GetMessageVaList();
    FormatStringMessageUseIndefiniteParameterTest(message.c_str(), 4, 2, SYSTEM_TEXT("Bill"), SYSTEM_TEXT("Bob"), 6, SYSTEM_TEXT("Bill"));
}

void System::FormatStringMessageUseVaListAndUseBufferTesting::FormatStringMessageUseIndefiniteParameterTest(const TChar* message, ...)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26826)

    va_list vaArguments{};
    va_start(vaArguments, message);

    ASSERT_NOT_THROW_EXCEPTION_2(FormatStringMessageUseArgumentsTest, message, vaArguments);

    va_end(vaArguments);

#include SYSTEM_WARNING_POP
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26826)

void System::FormatStringMessageUseVaListAndUseBufferTesting::FormatStringMessageUseArgumentsTest(const TChar* message, va_list vaArguments)
{
    TCharBufferType buffer{};
    const auto size = FormatStringMessage(message, buffer.data(), defaultBufferSize - 1, vaArguments);

    ASSERT_LESS(0u, size);
    ASSERT_LESS(static_cast<int>(size), defaultBufferSize);

    const String testMessage{ buffer.data() };
    ASSERT_EQUAL(testMessage.size(), size);
    ASSERT_EQUAL(testMessage, GetMessageVaListResult());
}

#include SYSTEM_WARNING_POP