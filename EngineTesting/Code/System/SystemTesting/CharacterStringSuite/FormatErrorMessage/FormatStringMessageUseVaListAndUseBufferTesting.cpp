///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/02 15:10)

#include "FormatStringMessageUseVaListAndUseBufferTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/LocalTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using namespace std::literals;

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
    ASSERT_NOT_THROW_EXCEPTION_0(FormatStringUseVaListAndUseBufferTest);
}

void System::FormatStringMessageUseVaListAndUseBufferTesting::FormatStringUseVaListAndUseBufferTest()
{
    const auto message = SYSTEM_TEXT("%1!*.*s! %3 %4!*s!"s);
    ExecuteFormatStringUseVaListAndUseBufferTest(message.c_str(), 4, 2, SYSTEM_TEXT("Bill"), SYSTEM_TEXT("Bob"), 6, SYSTEM_TEXT("Bill"));
}

void System::FormatStringMessageUseVaListAndUseBufferTesting::ExecuteFormatStringUseVaListAndUseBufferTest(const TChar* message, ...)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26492)

    va_list arguments{};
    va_start(arguments, message);

    ASSERT_NOT_THROW_EXCEPTION_2(DoExecuteFormatStringUseVaListAndUseBufferTest, message, arguments);

    va_end(arguments);

#include STSTEM_WARNING_POP
}

void System::FormatStringMessageUseVaListAndUseBufferTesting::DoExecuteFormatStringUseVaListAndUseBufferTest(const TChar* message, va_list arguments)
{
    constexpr auto bufferSize = 256;

    array<TChar, bufferSize> buffer{};
    String helperResult{ SYSTEM_TEXT("  Bi Bob   Bill") };

    const auto size = FormatStringMessage(message, buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), &arguments);

    ASSERT_TRUE(0 < size && size < bufferSize);

    String testMessage{ buffer.data() };
    ASSERT_EQUAL(testMessage.size(), size);
    ASSERT_EQUAL(testMessage, helperResult);
}
