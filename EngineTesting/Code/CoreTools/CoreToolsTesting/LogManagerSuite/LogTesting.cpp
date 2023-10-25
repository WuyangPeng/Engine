///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 11:26)

#include "LogTesting.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
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
    LOG_SINGLETON_APPENDER(Trace, CoreTools, SYSTEM_TEXT("��־������Ϣ����"));

    LOG_SINGLETON_APPENDER(Debug, CoreTools, SYSTEM_TEXT("��־������Ϣ����"));

    LOG_SINGLETON_APPENDER(Info, CoreTools, SYSTEM_TEXT("��־һ����Ϣ����"));

    LOG_SINGLETON_APPENDER(Warn, CoreTools, SYSTEM_TEXT("��־������Ϣ����"));

    LOG_SINGLETON_APPENDER(Error, CoreTools, SYSTEM_TEXT("��־������Ϣ����"));

    LOG_SINGLETON_APPENDER(Fatal, CoreTools, SYSTEM_TEXT("��־����������Ϣ����"));
}

void CoreTools::LogTesting::MessageTest()
{
    LogMessage traceMessage(LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED);
    traceMessage << gTraceMessage;

    LOG_SINGLETON.Write(traceMessage);

    LogMessage debugMessage{ LogLevel::Debug, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    debugMessage << gDebugMessage;

    LOG_SINGLETON.Write(debugMessage);

    LogMessage infoMessage{ LogLevel::Info, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    infoMessage << gInfoMessage;

    LOG_SINGLETON.Write(infoMessage);

    LogMessage warnMessage{ LogLevel::Warn, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    warnMessage << gWarnMessage;

    LOG_SINGLETON.Write(warnMessage);

    LogMessage errorMessage{ LogLevel::Error, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    errorMessage << gErrorMessage;

    LOG_SINGLETON.Write(errorMessage);

    LogMessage fatalMessage{ LogLevel::Fatal, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    fatalMessage << gFatalMessage;

    LOG_SINGLETON.Write(fatalMessage);
}

void CoreTools::LogTesting::GetMinLogLevelTypeTest()
{
    const auto logLevel = LOG_SINGLETON.GetMinLogLevelType(LogFilter::CoreTools);

    ASSERT_LESS(LogLevel::Disabled, logLevel);
}
