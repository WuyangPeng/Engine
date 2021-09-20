///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/02 11:44)

#include "FormatStringMessageUseArgumentArrayAndLocalAllocTesting.h"
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

System::FormatStringMessageUseArgumentArrayAndLocalAllocTesting::FormatStringMessageUseArgumentArrayAndLocalAllocTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatStringMessageUseArgumentArrayAndLocalAllocTesting)

void System::FormatStringMessageUseArgumentArrayAndLocalAllocTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatStringMessageUseArgumentArrayAndLocalAllocTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FormatStringUseArgumentArrayAndLocalAllocTest);
}

void System::FormatStringMessageUseArgumentArrayAndLocalAllocTesting::FormatStringUseArgumentArrayAndLocalAllocTest()
{
    WindowsHLocal resultMessage{ nullptr };
    const auto message = SYSTEM_TEXT("%1!*.*s! %4 %5!*s!"s);

    // "%1!*.*s!"������4 2 "Bill"��ʽ��"  Bi"
    // "%5!*s!"������6 "Bill"��ʽ��"  Bill"
    const auto helperResult = SYSTEM_TEXT("  Bi Bob   Bill"s);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    array<WindowsPtrDWord, 6> arguments{ boost::numeric_cast<WindowsPtrDWord>(4),
                                         boost::numeric_cast<WindowsPtrDWord>(2),
                                         reinterpret_cast<WindowsPtrDWord>(SYSTEM_TEXT("Bill")),
                                         reinterpret_cast<WindowsPtrDWord>(SYSTEM_TEXT("Bob")),
                                         boost::numeric_cast<WindowsPtrDWord>(6),
                                         reinterpret_cast<WindowsPtrDWord>(SYSTEM_TEXT("Bill")) };

#include STSTEM_WARNING_POP

    const auto size = FormatStringMessage(message.c_str(), resultMessage, arguments.data());
    ASSERT_LESS(0u, size);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(resultMessage, "��ʽ��������ʧ�ܡ�"s);

    String testMessage{ static_cast<TChar*>(resultMessage) };

    ASSERT_EQUAL(testMessage.size(), size);
    ASSERT_EQUAL(testMessage, helperResult);

    ASSERT_TRUE(LocalMemoryFree(resultMessage));
}
