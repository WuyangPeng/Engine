///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 17:27)

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
    const auto errorDescription = SYSTEM_TEXT("�����ɹ���ɡ�"s);

    const FormatErrorMessage message{ FormatErrorMessage::WindowError::Success };
    const auto error = message.GetErrorMessage();

    ASSERT_UNEQUAL(error.find(errorDescription), System::String::npos);
}

void CoreTools::FormatErrorMessageTesting::FindFileErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("ϵͳ�Ҳ���ָ�����ļ���"s);

    const FormatErrorMessage message{ FormatErrorMessage::WindowError::FileNotFound };
    const auto error = message.GetErrorMessage();

    ASSERT_UNEQUAL(error.find(errorDescription), System::String::npos);
}

void CoreTools::FormatErrorMessageTesting::PlaceholderErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("�������� %1 �ϲ������̡�"s);

    const FormatErrorMessage message{ FormatErrorMessage::WindowError::SemUserLimit };
    const auto error = message.GetErrorMessage();

    ASSERT_UNEQUAL(error.find(errorDescription), System::String::npos);
}

void CoreTools::FormatErrorMessageTesting::NetworkErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("���������Ӳ����ڡ�"s);

    const FormatErrorMessage message{ FormatErrorMessage::WindowError{ 2250 } };
    const auto error = message.GetErrorMessage();

    ASSERT_UNEQUAL(error.find(errorDescription), System::String::npos);
}

void CoreTools::FormatErrorMessageTesting::ComErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("�����Թ���"s);

    constexpr auto lastError = System::WindowError::EUnexpected;
    const FormatErrorMessage message{ lastError };
    const auto error = message.GetErrorMessage();

    ASSERT_UNEQUAL(error.find(errorDescription), System::String::npos);
}
