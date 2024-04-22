/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/18 21:52)

#include "AppenderManagerTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/Logger.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace
{
    const auto gAppenderManagerTestingPathName = SYSTEM_TEXT("Log/"s);

    const auto gAppenderManagerTestingFileName = SYSTEM_TEXT("AppenderManagerTestingFileName"s);
    const auto gExtensionName = SYSTEM_TEXT("log"s);

    const auto gTraceMessage = SYSTEM_TEXT("traceMessage\n"s);
    const auto gDebugMessage = SYSTEM_TEXT("debugMessage\n"s);
    const auto gInfoMessage = SYSTEM_TEXT("infoMessage\n"s);
    const auto gWarnMessage = SYSTEM_TEXT("warnMessage\n"s);
    const auto gErrorMessage = SYSTEM_TEXT("errorMessage\n"s);
    const auto gFatalMessage = SYSTEM_TEXT("fatalMessage\n"s);

    const auto gConsole = SYSTEM_TEXT("Console"s);
}

CoreTools::AppenderManagerTesting::AppenderManagerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      appenderManagerTestingName{ gAppenderManagerTestingPathName + gAppenderManagerTestingFileName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) },
      appenderManagerTestingFullName{ appenderManagerTestingName + SYSTEM_TEXT("."s) + gExtensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
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
    ASSERT_NOT_THROW_EXCEPTION_0(GetMinLogLevelTypeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AppenderNameTest);
}

void CoreTools::AppenderManagerTesting::LoggerTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoggerSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InsertLoggerFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RemoveLoggerFailTest);
}

void CoreTools::AppenderManagerTesting::LoggerSucceedTest()
{
    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(Logger{ LogFilter::CoreTools, LogLevel::Debug }));
    ASSERT_TRUE(manager->InsertLogger(Logger{ LogFilter::ArtificialIntelligence, LogLevel::Error }));
    ASSERT_TRUE(manager->InsertLogger(Logger{ LogFilter::Framework, LogLevel::Info }));

    ASSERT_TRUE(manager->RemoveLogger(LogFilter::CoreTools));
    ASSERT_TRUE(manager->RemoveLogger(LogFilter::ArtificialIntelligence));
    ASSERT_TRUE(manager->RemoveLogger(LogFilter::Framework));
}

void CoreTools::AppenderManagerTesting::InsertLoggerFailTest()
{
    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(Logger{ LogFilter::CoreTools, LogLevel::Debug }));
    ASSERT_FALSE(manager->InsertLogger(Logger{ LogFilter::CoreTools, LogLevel::Info }));
}

void CoreTools::AppenderManagerTesting::RemoveLoggerFailTest()
{
    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(Logger{ LogFilter::CoreTools, LogLevel::Debug }));
    ASSERT_TRUE(manager->InsertLogger(Logger{ LogFilter::Framework, LogLevel::Info }));

    ASSERT_FALSE(manager->RemoveLogger(LogFilter::AssistTools));
}

void CoreTools::AppenderManagerTesting::AppenderTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AppenderSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InsertAppenderFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RemoveAppenderFailTest);
}

void CoreTools::AppenderManagerTesting::AppenderSucceedTest()
{
    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertAppender(gConsole, Appender{ AppenderPrint::All }));
    ASSERT_TRUE(manager->IsAppenderExist(gConsole));
    ASSERT_TRUE(manager->RemoveAppender(gConsole));
    ASSERT_FALSE(manager->IsAppenderExist(gConsole));

    ASSERT_TRUE(manager->InsertAppender(gConsole, Appender{ AppenderPrint::All }));
    ASSERT_TRUE(manager->IsAppenderExist(gConsole));
    manager->Clear();
    ASSERT_FALSE(manager->IsAppenderExist(gConsole));
}

void CoreTools::AppenderManagerTesting::InsertAppenderFailTest()
{
    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertAppender(gConsole, Appender{ AppenderPrint::All }));
    ASSERT_FALSE(manager->InsertAppender(gConsole, Appender{ AppenderPrint::All }));
}

void CoreTools::AppenderManagerTesting::RemoveAppenderFailTest()
{
    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertAppender(gConsole, Appender{ AppenderPrint::All }));

    ASSERT_FALSE(manager->RemoveAppender(SYSTEM_TEXT("OStream"s)));
}

void CoreTools::AppenderManagerTesting::WriteMessageTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteMessageToFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileContentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WriteMessageToDefaultFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultFileContentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::AppenderManagerTesting::WriteMessageToFileTest()
{
    Appender appender{ gAppenderManagerTestingPathName, gAppenderManagerTestingFileName, AppenderPrint::All, LogLevel::Trace, 100000, true, SYSTEM_TEXT("log"s) };

    const Logger logger0{ LogFilter::CoreTools, LogLevel::Trace };

    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(logger0));
    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("FileAppender"s), appender));

    ASSERT_EQUAL(manager->GetMinLogLevelType(LogFilter::CoreTools), LogLevel::Trace);

    LogMessage traceMessage(LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED);
    traceMessage << gTraceMessage;

    /// 这条消息被写入gAppenderManagerTestingFileName
    manager->Write(traceMessage);

    const Logger logger1(LogFilter::System, LogLevel::Info);
    ASSERT_TRUE(manager->InsertLogger(logger1));

    LogMessage debugMessage{ LogLevel::Debug, LogFilter::System, CORE_TOOLS_FUNCTION_DESCRIBED };
    debugMessage << gDebugMessage;

    /// 这条消息没有被写入gAppenderManagerTestingFileName
    manager->Write(debugMessage);

    LogMessage infoMessage{ LogLevel::Info, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    infoMessage << gInfoMessage;

    /// 这条消息被写入gAppenderManagerTestingFileName
    manager->Write(infoMessage);

    appender.SetLogLevel(LogLevel::Error);
    ASSERT_TRUE(manager->RemoveAppender(SYSTEM_TEXT("FileAppender"s)));
    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("FileAppender"s), appender));

    LogMessage warnMessage{ LogLevel::Warn, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    warnMessage << gWarnMessage;

    /// 这条消息没有被写入gAppenderManagerTestingFileName
    manager->Write(warnMessage);

    LogMessage errorMessage{ LogLevel::Error, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    errorMessage << gErrorMessage;

    /// 这条消息被写入gAppenderManagerTestingFileName
    manager->Write(errorMessage);

    LogMessage fatalMessage{ LogLevel::Fatal, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    fatalMessage << gFatalMessage;

    /// 这条消息被写入gAppenderManagerTestingFileName
    manager->Write(fatalMessage);
}

void CoreTools::AppenderManagerTesting::FileContentTest()
{
    const IFileStreamManager fileManager{ appenderManagerTestingFullName };

    const auto fileContent = fileManager.GetFileContent();

    ASSERT_UNEQUAL(fileContent.find(gTraceMessage), System::String::npos);
    ASSERT_EQUAL(fileContent.find(gDebugMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gInfoMessage), System::String::npos);
    ASSERT_EQUAL(fileContent.find(gWarnMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gErrorMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gFatalMessage), System::String::npos);
}

void CoreTools::AppenderManagerTesting::DeleteFileTest()
{
    DeleteFileTools file{ appenderManagerTestingFullName };
}

void CoreTools::AppenderManagerTesting::WriteMessageToDefaultFileTest()
{
    const Appender appender{ gAppenderManagerTestingPathName, AppenderPrint::All, LogLevel::Trace, 100000, true, SYSTEM_TEXT("log"s) };

    const Logger logger{ LogFilter::CoreTools, LogLevel::Trace };

    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(logger));
    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("Default"s), appender));

    LogMessage traceMessage(LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED);
    traceMessage << gTraceMessage;

    manager->Write(gAppenderManagerTestingFileName, traceMessage);

    LogMessage debugMessage{ LogLevel::Debug, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    debugMessage << gDebugMessage;

    manager->Write(gAppenderManagerTestingFileName, debugMessage);

    LogMessage infoMessage{ LogLevel::Info, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    infoMessage << gInfoMessage;

    manager->Write(gAppenderManagerTestingFileName, infoMessage);

    LogMessage warnMessage{ LogLevel::Warn, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    warnMessage << gWarnMessage;

    manager->Write(gAppenderManagerTestingFileName, warnMessage);

    LogMessage errorMessage{ LogLevel::Error, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    errorMessage << gErrorMessage;

    manager->Write(gAppenderManagerTestingFileName, errorMessage);

    LogMessage fatalMessage{ LogLevel::Fatal, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    fatalMessage << gFatalMessage;

    manager->Write(gAppenderManagerTestingFileName, fatalMessage);
}

void CoreTools::AppenderManagerTesting::DefaultFileContentTest()
{
    const IFileStreamManager fileManager{ appenderManagerTestingFullName };

    const auto fileContent = fileManager.GetFileContent();

    ASSERT_UNEQUAL(fileContent.find(gTraceMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gDebugMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gInfoMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gWarnMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gErrorMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gFatalMessage), System::String::npos);
}

void CoreTools::AppenderManagerTesting::GetMinLogLevelTypeTest()
{
    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(Logger(LogFilter::CoreTools, LogLevel::Debug)));
    ASSERT_FALSE(manager->InsertLogger(Logger(LogFilter::CoreTools, LogLevel::Info)));

    ASSERT_EQUAL(manager->GetMinLogLevelType(LogFilter::CoreTools), LogLevel::Debug);
}

void CoreTools::AppenderManagerTesting::AppenderNameTest()
{
    ASSERT_EQUAL(AppenderManager::GetDefaultAppenderName(), SYSTEM_TEXT("Default"));
    ASSERT_EQUAL(AppenderManager::GetConsoleAppenderName(), SYSTEM_TEXT("Console"));
}
