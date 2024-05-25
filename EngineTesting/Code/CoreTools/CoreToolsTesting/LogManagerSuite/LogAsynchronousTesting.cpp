/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/11 14:11)

#include "LogAsynchronousTesting.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogAsynchronous.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/Logger.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace
{
    const auto gLogAsynchronousTestingPathName = SYSTEM_TEXT("Log/"s);

    const auto gLogAsynchronousTestingFileName = SYSTEM_TEXT("LogAsynchronousTestingFileName"s);
    const auto gExtensionName = SYSTEM_TEXT("log"s);

    const auto gTraceMessage = SYSTEM_TEXT("traceMessage\n"s);
    const auto gDebugMessage = SYSTEM_TEXT("debugMessage\n"s);
    const auto gInfoMessage = SYSTEM_TEXT("infoMessage\n"s);
    const auto gWarnMessage = SYSTEM_TEXT("warnMessage\n"s);
    const auto gErrorMessage = SYSTEM_TEXT("errorMessage\n"s);
    const auto gFatalMessage = SYSTEM_TEXT("fatalMessage\n"s);
}

CoreTools::LogAsynchronousTesting::LogAsynchronousTesting(const OStreamShared& stream)
    : ParentType{ stream },
      logAsynchronousTestingName{ gLogAsynchronousTestingPathName + gLogAsynchronousTestingFileName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) },
      logAsynchronousTestingFullName{ logAsynchronousTestingName + SYSTEM_TEXT("."s) + gExtensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogAsynchronousTesting)

void CoreTools::LogAsynchronousTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogAsynchronousTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteMessageToFileTest);

    LOG_ASYNCHRONOUS_SINGLETON.Stop();
    LOG_ASYNCHRONOUS_SINGLETON.Run();

    ASSERT_NOT_THROW_EXCEPTION_0(FileContentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WriteMessageToDefaultFileTest);

    LOG_ASYNCHRONOUS_SINGLETON.Stop();
    LOG_ASYNCHRONOUS_SINGLETON.Run();

    ASSERT_NOT_THROW_EXCEPTION_0(FileContentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);

    LOG_ASYNCHRONOUS_SINGLETON.Wait();
}

void CoreTools::LogAsynchronousTesting::WriteMessageToFileTest()
{
    const Appender appender{ gLogAsynchronousTestingPathName, gLogAsynchronousTestingFileName, AppenderPrint::All, LogLevel::Trace, 100000, true, SYSTEM_TEXT("log"s) };

    const Logger logger{ LogFilter::CoreTools, LogLevel::Trace };

    const auto manager = AppenderManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_3(InitAppenderManager, appender, logger, *manager);

    ASSERT_NOT_THROW_EXCEPTION_1(WriteMessageToFileRegisteredTest, manager);
}

void CoreTools::LogAsynchronousTesting::WriteMessageToFileRegisteredTest(const AppenderManagerSharedPtr& manager)
{
    ASSERT_NOT_THROW_EXCEPTION_3(RegisteredTest, manager, LogLevel::Trace, gTraceMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(RegisteredTest, manager, LogLevel::Debug, gDebugMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(RegisteredTest, manager, LogLevel::Info, gInfoMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(RegisteredTest, manager, LogLevel::Warn, gWarnMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(RegisteredTest, manager, LogLevel::Error, gErrorMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(RegisteredTest, manager, LogLevel::Fatal, gFatalMessage);
}

void CoreTools::LogAsynchronousTesting::InitAppenderManager(const Appender& appender, const Logger& logger, AppenderManager& manager)
{
    ASSERT_TRUE(manager.InsertLogger(logger));
    ASSERT_TRUE(manager.InsertAppender(SYSTEM_TEXT("FileAppender"s), appender));

    ASSERT_EQUAL(manager.GetMinLogLevelType(LogFilter::CoreTools), LogLevel::Trace);
}

void CoreTools::LogAsynchronousTesting::RegisteredTest(const AppenderManagerSharedPtr& manager, LogLevel logLevel, const String& message)
{
    LogMessage logMessage(logLevel, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED);
    logMessage << message;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(logMessage, manager);
}

void CoreTools::LogAsynchronousTesting::FileContentTest()
{
    const IFileStreamManager fileManager{ logAsynchronousTestingFullName };

    const auto fileContent = fileManager.GetFileContent();

    ASSERT_UNEQUAL(fileContent.find(gTraceMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gDebugMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gInfoMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gWarnMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gErrorMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gFatalMessage), System::String::npos);
}

void CoreTools::LogAsynchronousTesting::DeleteFileTest()
{
    DeleteFileTools file{ logAsynchronousTestingFullName };
}

void CoreTools::LogAsynchronousTesting::WriteMessageToDefaultFileTest()
{
    const Appender appender{ gLogAsynchronousTestingPathName, AppenderPrint::All, LogLevel::Trace, 100000, true, SYSTEM_TEXT("log"s) };

    const Logger logger{ LogFilter::CoreTools, LogLevel::Trace };

    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(logger));
    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("Default"s), appender));

    ASSERT_NOT_THROW_EXCEPTION_1(WriteMessageToDefaultFileRegisteredTest, manager);
}

void CoreTools::LogAsynchronousTesting::WriteMessageToDefaultFileRegisteredTest(const AppenderManagerSharedPtr& manager)
{
    ASSERT_NOT_THROW_EXCEPTION_3(DefaultFileRegisteredTest, manager, LogLevel::Trace, gTraceMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(DefaultFileRegisteredTest, manager, LogLevel::Debug, gDebugMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(DefaultFileRegisteredTest, manager, LogLevel::Info, gInfoMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(DefaultFileRegisteredTest, manager, LogLevel::Warn, gWarnMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(DefaultFileRegisteredTest, manager, LogLevel::Error, gErrorMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(DefaultFileRegisteredTest, manager, LogLevel::Fatal, gFatalMessage);
}

void CoreTools::LogAsynchronousTesting::DefaultFileRegisteredTest(const AppenderManagerSharedPtr& manager, LogLevel logLevel, const String& message)
{
    LogMessage logMessage{ logLevel, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    logMessage << message;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(gLogAsynchronousTestingFileName, logMessage, manager);
}
