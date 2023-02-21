///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:03)

#include "AppenderManagerTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/Logger.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::ostream;
using namespace std::literals;

namespace
{
    const auto gAppenderManagerTestingPathName = SYSTEM_TEXT("Log/"s);

    const auto gAppenderManagerTestingFileName = SYSTEM_TEXT("AppenderManagerTestingFileName"s);
    const auto gExtensionName = SYSTEM_TEXT("log"s);

    const auto gAppenderManagerTestingFullName = gAppenderManagerTestingPathName + gAppenderManagerTestingFileName;

    const auto gTraceMessage = SYSTEM_TEXT("traceMessage\n"s);
    const auto gDebugMessage = SYSTEM_TEXT("debugMessage\n"s);
    const auto gInfoMessage = SYSTEM_TEXT("infoMessage\n"s);
    const auto gWarnMessage = SYSTEM_TEXT("warnMessage\n"s);
    const auto gErrorMessage = SYSTEM_TEXT("errorMessage\n"s);
    const auto gFatalMessage = SYSTEM_TEXT("fatalMessage\n"s);
}

CoreTools::AppenderManagerTesting::AppenderManagerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      appenderManagerTestingName{ gAppenderManagerTestingPathName + gAppenderManagerTestingFileName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) },
      appenderManagerTestingFullName{ appenderManagerTestingName + SYSTEM_TEXT("."s) + gExtensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_0;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AppenderManagerTesting)

void CoreTools::AppenderManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AppenderManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoggerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AppenderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteMessageTest);
}

// Logger测试
void CoreTools::AppenderManagerTesting::LoggerTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoggerSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InsertLoggerFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RemoveLoggerFailTest);
}

void CoreTools::AppenderManagerTesting::LoggerSucceedTest()
{
    auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(Logger(LogFilter::CoreTools, LogLevel::Debug)));
    ASSERT_TRUE(manager->InsertLogger(Logger(LogFilter::ArtificialIntellegence, LogLevel::Error)));
    ASSERT_TRUE(manager->InsertLogger(Logger(LogFilter::Framework, LogLevel::Info)));

    ASSERT_TRUE(manager->RemoveLogger(LogFilter::CoreTools));
    ASSERT_TRUE(manager->RemoveLogger(LogFilter::ArtificialIntellegence));
    ASSERT_TRUE(manager->RemoveLogger(LogFilter::Framework));
}

void CoreTools::AppenderManagerTesting::InsertLoggerFailTest()
{
    auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(Logger(LogFilter::CoreTools, LogLevel::Debug)));
    ASSERT_FALSE(manager->InsertLogger(Logger(LogFilter::CoreTools, LogLevel::Info)));
}

void CoreTools::AppenderManagerTesting::RemoveLoggerFailTest()
{
    auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(Logger(LogFilter::CoreTools, LogLevel::Debug)));
    ASSERT_TRUE(manager->InsertLogger(Logger(LogFilter::Framework, LogLevel::Info)));

    ASSERT_FALSE(manager->RemoveLogger(LogFilter::AssistTools));
}

// Appender测试
void CoreTools::AppenderManagerTesting::AppenderTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AppenderSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InsertAppenderFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RemoveAppenderFailTest);
}

void CoreTools::AppenderManagerTesting::AppenderSucceedTest()
{
    auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("Console"s), Appender(AppenderPrint::All)));
    ASSERT_TRUE(manager->RemoveAppender(SYSTEM_TEXT("Console"s)));
}

void CoreTools::AppenderManagerTesting::InsertAppenderFailTest()
{
    auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("Console"s), Appender(AppenderPrint::All)));
    ASSERT_FALSE(manager->InsertAppender(SYSTEM_TEXT("Console"s), Appender(AppenderPrint::All)));
}

void CoreTools::AppenderManagerTesting::RemoveAppenderFailTest()
{
    auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("Console"s), Appender(AppenderPrint::All)));

    ASSERT_FALSE(manager->RemoveAppender(SYSTEM_TEXT("OStream"s)));
}

// WriteMessage测试
void CoreTools::AppenderManagerTesting::WriteMessageTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteMessageToFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileContentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::AppenderManagerTesting::WriteMessageToFileTest()
{
    Appender appender{ gAppenderManagerTestingPathName, gAppenderManagerTestingFileName, AppenderPrint::All, LogLevel::Trace, 100000, true, SYSTEM_TEXT("log"s) };

    Logger firstLogger{ LogFilter::CoreTools, LogLevel::Trace };

    auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(firstLogger));
    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("FileAppender"s), appender));

    LogMessage traceMessage(LogLevel::Trace, LogFilter::CoreTools, gTraceMessage, CORE_TOOLS_FUNCTION_DESCRIBED);

    // 这条消息被写入g_AppenderManagerTestingFileName
    manager->Write(traceMessage);

    Logger secondLogger(LogFilter::System, LogLevel::Info);
    ASSERT_TRUE(manager->InsertLogger(secondLogger));

    LogMessage debugMessage{ LogLevel::Debug, LogFilter::System, gDebugMessage, CORE_TOOLS_FUNCTION_DESCRIBED };

    // 这条消息没有被写入g_AppenderManagerTestingFileName
    manager->Write(debugMessage);

    LogMessage infoMessage{ LogLevel::Info, LogFilter::CoreTools, gInfoMessage, CORE_TOOLS_FUNCTION_DESCRIBED };

    // 这条消息被写入g_AppenderManagerTestingFileName
    manager->Write(infoMessage);

    appender.SetLogLevel(LogLevel::Error);
    ASSERT_TRUE(manager->RemoveAppender(SYSTEM_TEXT("FileAppender"s)));
    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("FileAppender"s), appender));

    LogMessage warnMessage{ LogLevel::Warn, LogFilter::CoreTools, gWarnMessage, CORE_TOOLS_FUNCTION_DESCRIBED };

    // 这条消息没有被写入g_AppenderManagerTestingFileName
    manager->Write(warnMessage);

    LogMessage errorMessage{ LogLevel::Error, LogFilter::CoreTools, gErrorMessage, CORE_TOOLS_FUNCTION_DESCRIBED };

    // 这条消息被写入g_AppenderManagerTestingFileName
    manager->Write(errorMessage);
}

void CoreTools::AppenderManagerTesting::FileContentTest()
{
    IFStreamManager fileManager{ appenderManagerTestingFullName };

    auto fileContent = fileManager.GetFileContent();

    ASSERT_UNEQUAL(fileContent.find(gTraceMessage), System::String::npos);
    ASSERT_EQUAL(fileContent.find(gDebugMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gInfoMessage), System::String::npos);
    ASSERT_EQUAL(fileContent.find(gWarnMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gErrorMessage), System::String::npos);
}

void CoreTools::AppenderManagerTesting::DeleteFileTest()
{
    DeleteFileTools file{ appenderManagerTestingFullName };
}
