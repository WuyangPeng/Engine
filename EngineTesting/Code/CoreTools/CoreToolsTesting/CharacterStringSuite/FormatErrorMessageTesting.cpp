/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 14:39)

#include "FormatErrorMessageTesting.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/CharacterString/FormatErrorMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::FormatErrorMessageTesting::FormatErrorMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FormatErrorMessageTesting)

void CoreTools::FormatErrorMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::FormatErrorMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SucceedMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FindFileErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PlaceholderErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ComErrorTest);
}

void CoreTools::FormatErrorMessageTesting::SucceedMessageTest()
{
    const auto errorDescription = SYSTEM_TEXT("操作成功完成。"s);

    const FormatErrorMessage message{ FormatErrorMessage::WindowError::Success };
    const auto error = message.GetErrorMessage();

    ASSERT_UNEQUAL(error.find(errorDescription), System::String::npos);
}

void CoreTools::FormatErrorMessageTesting::FindFileErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("系统找不到指定的文件。"s);

    const FormatErrorMessage message{ FormatErrorMessage::WindowError::FileNotFound };
    const auto error = message.GetErrorMessage();

    ASSERT_UNEQUAL(error.find(errorDescription), System::String::npos);
}

void CoreTools::FormatErrorMessageTesting::PlaceholderErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("在驱动器 %1 上插入软盘。"s);

    const FormatErrorMessage message{ FormatErrorMessage::WindowError::SemUserLimit };
    const auto error = message.GetErrorMessage();

    ASSERT_UNEQUAL(error.find(errorDescription), System::String::npos);
}

void CoreTools::FormatErrorMessageTesting::NetworkErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("此网络连接不存在。"s);

    const FormatErrorMessage message{ FormatErrorMessage::WindowError{ 2250 } };
    const auto error = message.GetErrorMessage();

    ASSERT_UNEQUAL(error.find(errorDescription), System::String::npos);
}

void CoreTools::FormatErrorMessageTesting::ComErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("灾难性故障"s);

    constexpr auto lastError = System::WindowError::EUnexpected;
    const FormatErrorMessage message{ lastError };
    const auto error = message.GetErrorMessage();

    ASSERT_UNEQUAL(error.find(errorDescription), System::String::npos);
}
