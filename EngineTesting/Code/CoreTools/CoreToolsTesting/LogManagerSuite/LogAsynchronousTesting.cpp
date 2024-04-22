/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/18 22:06)

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

    const Logger logger0{ LogFilter::CoreTools, LogLevel::Trace };

    const auto manager = AppenderManager::Create();

    ASSERT_TRUE(manager->InsertLogger(logger0));
    ASSERT_TRUE(manager->InsertAppender(SYSTEM_TEXT("FileAppender"s), appender));

    ASSERT_EQUAL(manager->GetMinLogLevelType(LogFilter::CoreTools), LogLevel::Trace);

    LogMessage traceMessage(LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED);
    traceMessage << gTraceMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(traceMessage, manager);

    LogMessage debugMessage{ LogLevel::Debug, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    debugMessage << gDebugMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(debugMessage, manager);

    LogMessage infoMessage{ LogLevel::Info, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    infoMessage << gInfoMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(infoMessage, manager);

    LogMessage warnMessage{ LogLevel::Warn, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    warnMessage << gWarnMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(warnMessage, manager);

    LogMessage errorMessage{ LogLevel::Error, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    errorMessage << gErrorMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(errorMessage, manager);

    LogMessage fatalMessage{ LogLevel::Fatal, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    fatalMessage << gFatalMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(fatalMessage, manager);
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

    LogMessage traceMessage(LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED);
    traceMessage << gTraceMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(gLogAsynchronousTestingFileName, traceMessage, manager);

    LogMessage debugMessage{ LogLevel::Debug, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    debugMessage << gDebugMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(gLogAsynchronousTestingFileName, debugMessage, manager);

    LogMessage infoMessage{ LogLevel::Info, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    infoMessage << gInfoMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(gLogAsynchronousTestingFileName, infoMessage, manager);

    LogMessage warnMessage{ LogLevel::Warn, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    warnMessage << gWarnMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(gLogAsynchronousTestingFileName, warnMessage, manager);

    LogMessage errorMessage{ LogLevel::Error, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    errorMessage << gErrorMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(gLogAsynchronousTestingFileName, errorMessage, manager);

    LogMessage fatalMessage{ LogLevel::Fatal, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    fatalMessage << gFatalMessage;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(gLogAsynchronousTestingFileName, fatalMessage, manager);
}
