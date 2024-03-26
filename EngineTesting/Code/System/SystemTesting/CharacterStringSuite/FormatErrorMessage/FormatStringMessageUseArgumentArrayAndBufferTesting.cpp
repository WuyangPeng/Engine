/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:16)

#include "FormatStringMessageUseArgumentArrayAndBufferTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    ASSERT_NOT_THROW_EXCEPTION_0(FormatStringMessageUseArgumentArrayAndBufferTest);
}

void System::FormatStringMessageUseArgumentArrayAndBufferTesting::FormatStringMessageUseArgumentArrayAndBufferTest()
{
    const auto message = GetMessageFormat();

    TCharBufferType buffer{};
    const auto size = FormatStringMessage(message.c_str(), buffer.data(), defaultBufferSize - 1, GetArgumentsData());
    ASSERT_LESS(0u, size);
    ASSERT_LESS(boost::numeric_cast<int>(size), defaultBufferSize);

    const String testMessage{ buffer.data() };
    ASSERT_EQUAL(testMessage.size(), size);
    ASSERT_EQUAL(testMessage, GetMessageFormatResult());
}
