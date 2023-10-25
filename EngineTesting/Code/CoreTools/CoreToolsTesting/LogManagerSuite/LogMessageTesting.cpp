///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:26)

#include "LogMessageTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <System/Windows/Flags/PlatformErrorFlags.h>

using namespace std::literals;

CoreTools::LogMessageTesting::LogMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogMessageTesting)

void CoreTools::LogMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void CoreTools::LogMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LogLevelTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogFilterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFileNameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogAppenderIOManageSignTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
}

void CoreTools::LogMessageTesting::LogLevelTest()
{
    LogMessage message{ LogLevel::Error, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    message << SYSTEM_TEXT("抛出异常！"s);

    ASSERT_ENUM_EQUAL(message.GetLogLevel(), LogLevel::Error);
}

void CoreTools::LogMessageTesting::LogFilterTest()
{
    LogMessage message{ LogLevel::Fatal, LogFilter::Rendering, CORE_TOOLS_FUNCTION_DESCRIBED };
    message << SYSTEM_TEXT("图像渲染失败！"s);

    ASSERT_ENUM_EQUAL(message.GetLogFilterType(), LogFilter::Rendering);
}

void CoreTools::LogMessageTesting::MessageTest()
{
    const auto error = SYSTEM_TEXT("连接不上网络！"s);
    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;

    LogMessage message{ LogLevel::Warn, LogFilter::Network, functionDescribed };
    message << error;

    ASSERT_EQUAL(message.GetMessageDescribe(), error);
    ASSERT_EQUAL(message.GetMessageSize(), boost::numeric_cast<int>(error.size()));
    ASSERT_EQUAL(message.GetFunctionDescribed(), functionDescribed);
}

void CoreTools::LogMessageTesting::GetFileNameTest()
{
    const LogFileName logFileName{ SYSTEM_TEXT("logFileName") };

    const LogMessage message{ logFileName, LogLevel::Error, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };

    ASSERT_ENUM_EQUAL(message.GetLogLevel(), LogLevel::Error);
    ASSERT_EQUAL(message.GetFileName(), logFileName.GetFileName());
}

void CoreTools::LogMessageTesting::LogAppenderIOManageSignTest()
{
    LogMessage message{ LogLevel::Warn, LogFilter::Network, CORE_TOOLS_FUNCTION_DESCRIBED };

    ASSERT_FALSE(message.HasAlwaysConsole());
    ASSERT_FALSE(message.HasTriggerAssert());

    message << LogAppenderIOManageSign::AlwaysConsole;

    ASSERT_TRUE(message.HasAlwaysConsole());
    ASSERT_FALSE(message.HasTriggerAssert());

    message << LogAppenderIOManageSign::TriggerAssert;

    ASSERT_TRUE(message.HasAlwaysConsole());
    ASSERT_TRUE(message.HasTriggerAssert());
}

void CoreTools::LogMessageTesting::ExceptionTest()
{
    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;

    const Error error{ functionDescribed, System::WindowError::Success, SYSTEM_TEXT("Error") };

    LogMessage message{ LogLevel::Warn, LogFilter::Network, CORE_TOOLS_FUNCTION_DESCRIBED };
    ASSERT_UNEQUAL(message.GetFunctionDescribed(), functionDescribed);

    message << error;
    ASSERT_EQUAL(message.GetFunctionDescribed(), functionDescribed);

    ASSERT_UNEQUAL(message.GetMessageDescribe().find(error.GetError()), std::string::npos);

    const std::exception exception("exception");

    message << exception;

    ASSERT_UNEQUAL(message.GetMessageDescribe().find(StringConversion::MultiByteConversionStandard(exception.what())), std::string::npos);
}

void CoreTools::LogMessageTesting::StringTest()
{
    LogMessage message{ LogLevel::Warn, LogFilter::Network, CORE_TOOLS_FUNCTION_DESCRIBED };

    message << 'a';
    message << L'b';
    message << "cc";
    message << L"dd";
    message << "ee"s;
    message << L"ff"s;
    message << "gg"sv;
    message << L"hh"sv;

    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT('a')), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT('b')), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT("cc")), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT("dd")), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT("ee")), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT("ff")), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT("gg")), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT("hh")), std::string::npos);
}

void CoreTools::LogMessageTesting::IntegerTest()
{
    LogMessage message{ LogLevel::Warn, LogFilter::Network, CORE_TOOLS_FUNCTION_DESCRIBED };

    message << 1;
    message << 2u;
    message << 3LL;
    message << 4ULL;
    message << 5.0f;
    message << 6.0;

    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT('1')), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT('2')), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT("3")), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT("4")), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT("5")), std::string::npos);
    ASSERT_UNEQUAL(message.GetMessageDescribe().find(SYSTEM_TEXT("6")), std::string::npos);
}
