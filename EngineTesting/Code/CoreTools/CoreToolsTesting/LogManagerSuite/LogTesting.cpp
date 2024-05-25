/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/11 14:41)

#include "LogTesting.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/Log.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace
{
    const auto gTraceMessage = SYSTEM_TEXT("traceMessage\n"s);
    const auto gDebugMessage = SYSTEM_TEXT("debugMessage\n"s);
    const auto gInfoMessage = SYSTEM_TEXT("infoMessage\n"s);
    const auto gWarnMessage = SYSTEM_TEXT("warnMessage\n"s);
    const auto gErrorMessage = SYSTEM_TEXT("errorMessage\n"s);
    const auto gFatalMessage = SYSTEM_TEXT("fatalMessage\n"s);
}

CoreTools::LogTesting::LogTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogTesting)

void CoreTools::LogTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadConfigurationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetMinLogLevelTypeTest);
}

void CoreTools::LogTesting::LoadConfigurationTest()
{
    LOG_SINGLETON.LoadConfiguration("Configuration/Log.json");
}

void CoreTools::LogTesting::OutTest() noexcept
{
    LOG_SINGLETON_APPENDER(Trace, CoreTools, SYSTEM_TEXT("日志跟踪信息测试"));

    LOG_SINGLETON_APPENDER(Debug, CoreTools, SYSTEM_TEXT("日志调试信息测试"));

    LOG_SINGLETON_APPENDER(Info, CoreTools, SYSTEM_TEXT("日志一般信息测试"));

    LOG_SINGLETON_APPENDER(Warn, CoreTools, SYSTEM_TEXT("日志警告信息测试"));

    LOG_SINGLETON_APPENDER(Error, CoreTools, SYSTEM_TEXT("日志错误信息测试"));

    LOG_SINGLETON_APPENDER(Fatal, CoreTools, SYSTEM_TEXT("日志致命错误信息测试"));
}

void CoreTools::LogTesting::MessageTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(DoMessageTest, LogLevel::Trace, gTraceMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoMessageTest, LogLevel::Debug, gDebugMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoMessageTest, LogLevel::Info, gInfoMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoMessageTest, LogLevel::Warn, gWarnMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoMessageTest, LogLevel::Error, gErrorMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoMessageTest, LogLevel::Fatal, gFatalMessage);
}

void CoreTools::LogTesting::DoMessageTest(LogLevel logLevel, const String& message)
{
    LogMessage traceMessage(logLevel, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED);
    traceMessage << message;

    LOG_SINGLETON.Write(traceMessage);
}

void CoreTools::LogTesting::GetMinLogLevelTypeTest()
{
    const auto logLevel = LOG_SINGLETON.GetMinLogLevelType(LogFilter::CoreTools);

    ASSERT_LESS(LogLevel::Disabled, logLevel);
}
