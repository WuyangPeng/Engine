///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/29 22:34)

#include "FormatStringMessageUseArgumentArrayAndLocalAllocTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    WindowsHLocal resultMessage{ nullptr };

    ASSERT_NOT_THROW_EXCEPTION_1(FormatStringMessageUseArgumentArrayAndLocalAllocTest, resultMessage);

    ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, resultMessage);
}

void System::FormatStringMessageUseArgumentArrayAndLocalAllocTesting::FormatStringMessageUseArgumentArrayAndLocalAllocTest(WindowsHLocal& resultMessage)
{
    const auto message = GetMessageFormat();

    const auto size = FormatStringMessage(message.c_str(), resultMessage, GetArgumentsData());
    ASSERT_LESS(0u, size);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(resultMessage, "格式化错误码失败。"s);

    String testMessage{ static_cast<TChar*>(resultMessage) };

    ASSERT_EQUAL(testMessage.size(), size);
    ASSERT_EQUAL(testMessage, GetMessageFormatResult());
}
