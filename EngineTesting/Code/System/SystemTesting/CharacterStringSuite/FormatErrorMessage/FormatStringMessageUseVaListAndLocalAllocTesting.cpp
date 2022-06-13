///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:23)

#include "FormatStringMessageUseVaListAndLocalAllocTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/LocalTools.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

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
    ASSERT_NOT_THROW_EXCEPTION_0(FormatStringUseVaListAndLocalAllocTest);
}

void System::FormatStringMessageUseVaListAndLocalAllocTesting::FormatStringUseVaListAndLocalAllocTest()
{
    const auto message = SYSTEM_TEXT("%1!*.*s! %3 %4!*s!"s);
    ExecuteFormatStringUseVaListAndLocalAllocTest(message.c_str(), 4, 2, SYSTEM_TEXT("Bill"), SYSTEM_TEXT("Bob"), 6, SYSTEM_TEXT("Bill"));
}

void System::FormatStringMessageUseVaListAndLocalAllocTesting::ExecuteFormatStringUseVaListAndLocalAllocTest(const TChar* message, ...)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26492)

    va_list arguments{};
    va_start(arguments, message);

    ASSERT_NOT_THROW_EXCEPTION_2(DoExecuteFormatStringUseVaListAndLocalAllocTest, message, arguments);

    va_end(arguments);

#include STSTEM_WARNING_POP
}

void System::FormatStringMessageUseVaListAndLocalAllocTesting::DoExecuteFormatStringUseVaListAndLocalAllocTest(const TChar* message, va_list arguments)
{
    WindowsHLocal resultMessage{ nullptr };
    const auto helperResult = SYSTEM_TEXT("  Bi Bob   Bill"s);

    const auto size = FormatStringMessage(message, resultMessage, &arguments);
    ASSERT_LESS(0u, size);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(resultMessage, "FormatStringMessage 失败。");

    String testMessage{ static_cast<TChar*>(resultMessage) };

    ASSERT_EQUAL(testMessage.size(), size);
    ASSERT_EQUAL(testMessage, helperResult);

    ASSERT_TRUE(LocalMemoryFree(resultMessage));
}
