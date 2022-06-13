///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:23)

#include "FormatStringMessageUseArgumentArrayAndBufferTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/LocalTools.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;
using namespace std::literals;

System::FormatStringMessageUseArgumentArrayAndBufferTesting::FormatStringMessageUseArgumentArrayAndBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatStringMessageUseArgumentArrayAndBufferTesting)

void System::FormatStringMessageUseArgumentArrayAndBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatStringMessageUseArgumentArrayAndBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FormatStringUseArgumentArrayAndBufferTest);
}

void System::FormatStringMessageUseArgumentArrayAndBufferTesting::FormatStringUseArgumentArrayAndBufferTest()
{
    const auto message = SYSTEM_TEXT("%1!*.*s! %4 %5!*s!"s);

    // "%1!*.*s!"，根据4 3 "Bill"格式化" Bil"
    // "%5!*s!"，根据6 "Bill"格式化"  Bill"
    const auto helperResult = SYSTEM_TEXT(" Bil Bob   Bill"s);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    array<WindowsPtrDWord, 6> arguments{ boost::numeric_cast<WindowsPtrDWord>(4),
                                         boost::numeric_cast<WindowsPtrDWord>(3),
                                         reinterpret_cast<WindowsPtrDWord>(SYSTEM_TEXT("Bill")),
                                         reinterpret_cast<WindowsPtrDWord>(SYSTEM_TEXT("Bob")),
                                         boost::numeric_cast<WindowsPtrDWord>(6),
                                         reinterpret_cast<WindowsPtrDWord>(SYSTEM_TEXT("Bill")) };

#include STSTEM_WARNING_POP

    constexpr auto bufferSize = 256;
    array<TChar, bufferSize> buffer{};

    const auto size = FormatStringMessage(message.c_str(), buffer.data(), boost::numeric_cast<WindowsDWord>(buffer.size()), arguments.data());
    ASSERT_LESS(0u, size);

    String testMessage{ buffer.data() };

    ASSERT_EQUAL(testMessage.size(), size);
    ASSERT_EQUAL(testMessage, helperResult);
}
