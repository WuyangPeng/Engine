/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/09 21:47)

#include "AppenderManagerTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
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

    ASSERT_NOT_THROW_EXCEPTION_1(InsertLoggerSucceedTest, *manager);
    ASSERT_NOT_THROW_EXCEPTION_1(RemoveLoggerSucceedTest, *manager);
}

void CoreTools::AppenderManagerTesting::InsertLoggerSucceedTest(AppenderManager& manager)
{
    ASSERT_TRUE(manager.InsertLogger(Logger{ LogFilter::CoreTools, LogLevel::Debug }));
    ASSERT_TRUE(manager.InsertLogger(Logger{ LogFilter::ArtificialIntelligence, LogLevel::Error }));
    ASSERT_TRUE(manager.InsertLogger(Logger{ LogFilter::Framework, LogLevel::Info }));
}

void CoreTools::AppenderManagerTesting::RemoveLoggerSucceedTest(AppenderManager& manager)
{
    ASSERT_TRUE(manager.RemoveLogger(LogFilter::CoreTools));
    ASSERT_TRUE(manager.RemoveLogger(LogFilter::ArtificialIntelligence));
    ASSERT_TRUE(manager.RemoveLogger(LogFilter::Framework));
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

    const auto manager = InitTraceLogger(appender);

    ASSERT_NOT_THROW_EXCEPTION_1(WriteTraceMessageTest, *manager);

    ASSERT_NOT_THROW_EXCEPTION_1(InitInfoLogger, *manager);

    ASSERT_NOT_THROW_EXCEPTION_1(WriteDebugMessageDoNothingTest, *manager);
    ASSERT_NOT_THROW_EXCEPTION_1(WriteInfoMessageTest, *manager);

    ASSERT_NOT_THROW_EXCEPTION_2(InitFileAppender, appender, *manager);

    ASSERT_NOT_THROW_EXCEPTION_1(WriteWarnMessageDoNothingTest, *manager);
    ASSERT_NOT_THROW_EXCEPTION_1(WriteErrorMessageTest, *manager);
    ASSERT_NOT_THROW_EXCEPTION_1(WriteFatalMessageTest, *manager);
}

void CoreTools::AppenderManagerTesting::WriteTraceMessageTest(const AppenderManager& manager) const
{
    LogMessage traceMessage(LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED);
    traceMessage << gTraceMessage;

    /// 这条消息被写入gAppenderManagerTestingFileName
    manager.Write(traceMessage);
}

void CoreTools::AppenderManagerTesting::WriteDebugMessageDoNothingTest(const AppenderManager& manager) const
{
    LogMessage debugMessage{ LogLevel::Debug, LogFilter::System, CORE_TOOLS_FUNCTION_DESCRIBED };
    debugMessage << gDebugMessage;

    /// 这条消息没有被写入gAppenderManagerTestingFileName
    manager.Write(debugMessage);
}

void CoreTools::AppenderManagerTesting::WriteInfoMessageTest(const AppenderManager& manager) const
{
    LogMessage infoMessage{ LogLevel::Info, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    infoMessage << gInfoMessage;

    /// 这条消息被写入gAppenderManagerTestingFileName
    manager.Write(infoMessage);
}

void CoreTools::AppenderManagerTesting::WriteWarnMessageDoNothingTest(const AppenderManager& manager) const
{
    LogMessage warnMessage{ LogLevel::Warn, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    warnMessage << gWarnMessage;

    /// 这条消息没有被写入gAppenderManagerTestingFileName
    manager.Write(warnMessage);
}

void CoreTools::AppenderManagerTesting::WriteErrorMessageTest(const AppenderManager& manager) const
{
    LogMessage errorMessage{ LogLevel::Error, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    errorMessage << gErrorMessage;

    /// 这条消息被写入gAppenderManagerTestingFileName
    manager.Write(errorMessage);
}

void CoreTools::AppenderManagerTesting::WriteFatalMessageTest(const AppenderManager& manager) const
{
    LogMessage fatalMessage{ LogLevel::Fatal, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    fatalMessage << gFatalMessage;

    /// 这条消息被写入gAppenderManagerTestingFileName
    manager.Write(fatalMessage);
}

CoreTools::AppenderManagerTesting::AppenderManagerSharedPtr CoreTools::AppenderManagerTesting::InitTraceLogger(const Appender& appender)
{
    const Logger logger{ LogFilter::CoreTools, LogLevel::Trace };

    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(logger));
    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("FileAppender"s), appender));

    ASSERT_EQUAL(manager->GetMinLogLevelType(LogFilter::CoreTools), LogLevel::Trace);

    return manager;
}

void CoreTools::AppenderManagerTesting::InitInfoLogger(AppenderManager& manager)
{
    const Logger logger(LogFilter::System, LogLevel::Info);
    ASSERT_TRUE(manager.InsertLogger(logger));
}

void CoreTools::AppenderManagerTesting::InitFileAppender(Appender& appender, AppenderManager& manager)
{
    appender.SetLogLevel(LogLevel::Error);
    ASSERT_TRUE(manager.RemoveAppender(SYSTEM_TEXT("FileAppender"s)));
    ASSERT_TRUE(manager.InsertAppender(SYSTEM_TEXT("FileAppender"s), appender));
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

    ASSERT_NOT_THROW_EXCEPTION_3(DoWriteMessageToDefaultFileTest, *manager, LogLevel::Trace, gTraceMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(DoWriteMessageToDefaultFileTest, *manager, LogLevel::Debug, gDebugMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(DoWriteMessageToDefaultFileTest, *manager, LogLevel::Info, gInfoMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(DoWriteMessageToDefaultFileTest, *manager, LogLevel::Warn, gWarnMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(DoWriteMessageToDefaultFileTest, *manager, LogLevel::Error, gErrorMessage);
    ASSERT_NOT_THROW_EXCEPTION_3(DoWriteMessageToDefaultFileTest, *manager, LogLevel::Fatal, gFatalMessage);
}

void CoreTools::AppenderManagerTesting::DoWriteMessageToDefaultFileTest(AppenderManager& manager, LogLevel logLevel, const String& message)
{
    LogMessage logMessage{ logLevel, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    logMessage << message;

    manager.Write(gAppenderManagerTestingFileName, logMessage);
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
