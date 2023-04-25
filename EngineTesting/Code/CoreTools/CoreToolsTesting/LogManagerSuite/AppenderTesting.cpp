///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/12 14:16)

#include "AppenderTesting.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace
{
    const auto gAppenderTestingPathName = SYSTEM_TEXT("Log/"s);

    const auto gAppenderTestingFileName = SYSTEM_TEXT("AppenderTestingFileName"s);

    const auto gExtensionName = SYSTEM_TEXT("log"s);

    const auto gFileTraceMessage = SYSTEM_TEXT("traceMessage\n"s);
    const auto gFileDebugMessage = SYSTEM_TEXT("debugMessage\n"s);
    const auto gFileInfoMessage = SYSTEM_TEXT("infoMessage\n"s);
    const auto gFileWarnMessage = SYSTEM_TEXT("warnMessage\n"s);
    const auto gFileErrorMessage = SYSTEM_TEXT("errorMessage\n"s);
    const auto gFileFatalMessage = SYSTEM_TEXT("fatalMessage\n"s);
    const auto gBackupMessage = SYSTEM_TEXT("backupMessage"s);

    const auto gConsoleTraceMessage = SYSTEM_TEXT("这条日志在控制台显示为白色。\n"s);
    const auto gConsoleDebugMessage = SYSTEM_TEXT("这条日志在控制台显示为青色。\n"s);
    const auto gConsoleInfoMessage = SYSTEM_TEXT("这条日志在控制台显示为绿色。\n"s);
    const auto gConsoleWarnMessage = SYSTEM_TEXT("这条日志在控制台显示为黄色。\n"s);
    const auto gConsoleErrorMessage = SYSTEM_TEXT("这条日志在控制台显示为红色。\n"s);
    const auto gConsoleFatalMessage = SYSTEM_TEXT("这条日志在控制台显示为加深的红色。\n"s);
}

CoreTools::AppenderTesting::AppenderTesting(const OStreamShared& stream)
    : ParentType{ stream },
      appenderTestingName{ gAppenderTestingPathName + gAppenderTestingFileName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) },
      appenderTestingFullName{ appenderTestingName + SYSTEM_TEXT("."s) + gExtensionName },
      backupFileName{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AppenderTesting)

void CoreTools::AppenderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AppenderTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileConfigurationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetLogLevelTest);
}

// Console测试
void CoreTools::AppenderTesting::ConsoleTest()
{
    Appender appender{ AppenderPrint::All, LogLevel::Trace };

    ASSERT_ENUM_EQUAL(appender.GetFlags(), AppenderPrint::All);
    ASSERT_ENUM_EQUAL(appender.GetLogLevel(), LogLevel::Trace);
    ASSERT_ENUM_EQUAL(appender.GetAppenderType(), AppenderType::Console);

    LogMessage traceMessage{ LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    traceMessage << gConsoleTraceMessage;
    appender.Write(traceMessage);

    LogMessage debugMessage{ LogLevel::Debug, LogFilter::Framework, CORE_TOOLS_FUNCTION_DESCRIBED };
    debugMessage << gConsoleDebugMessage;
    appender.Write(debugMessage);

    LogMessage infoMessage{ LogLevel::Info, LogFilter::Mathematics, CORE_TOOLS_FUNCTION_DESCRIBED };
    infoMessage << gConsoleInfoMessage;
    appender.Write(infoMessage);

    LogMessage warnMessage{ LogLevel::Warn, LogFilter::Rendering, CORE_TOOLS_FUNCTION_DESCRIBED };
    warnMessage << gConsoleWarnMessage;
    appender.Write(warnMessage);

    LogMessage errorMessage{ LogLevel::Error, LogFilter::Physics, CORE_TOOLS_FUNCTION_DESCRIBED };
    errorMessage << gConsoleErrorMessage;
    appender.Write(errorMessage);

    LogMessage fatalMessage{ LogLevel::Fatal, LogFilter::System, CORE_TOOLS_FUNCTION_DESCRIBED };
    fatalMessage << gConsoleFatalMessage;
    appender.Write(fatalMessage);

    ASSERT_TRUE(appender.GetDirectory().empty());
    ASSERT_TRUE(appender.GetExtensionName().empty());
    ASSERT_EQUAL(appender.GetMaxFileSize(), 0);
    ASSERT_FALSE(appender.IsBackup());

    ASSERT_TRUE(appender.IsDefault());
    appender.SetIsDefault(false);
    ASSERT_FALSE(appender.IsDefault());
}

// File测试
void CoreTools::AppenderTesting::FileTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileLogTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileContentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BackupFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BackupFileContentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::AppenderTesting::FileLogTest()
{
    constexpr auto maxFileSize = 100000;
    Appender appender{ gAppenderTestingPathName, gAppenderTestingFileName, AppenderPrint::All, LogLevel::Trace, maxFileSize, true, gExtensionName };

    ASSERT_ENUM_EQUAL(appender.GetFlags(), AppenderPrint::All);
    ASSERT_ENUM_EQUAL(appender.GetLogLevel(), LogLevel::Trace);
    ASSERT_ENUM_EQUAL(appender.GetAppenderType(), AppenderType::File);

    LogMessage traceMessage{ LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    traceMessage << gFileTraceMessage;
    appender.Write(traceMessage);

    LogMessage debugMessage{ LogLevel::Debug, LogFilter::System, CORE_TOOLS_FUNCTION_DESCRIBED };
    debugMessage << gFileDebugMessage;
    appender.Write(debugMessage);

    LogMessage infoMessage{ LogLevel::Info, LogFilter::SoundEffect, CORE_TOOLS_FUNCTION_DESCRIBED };
    infoMessage << gFileInfoMessage;
    appender.Write(infoMessage);

    LogMessage warnMessage{ LogLevel::Warn, LogFilter::Physics, CORE_TOOLS_FUNCTION_DESCRIBED };
    warnMessage << gFileWarnMessage;
    appender.Write(warnMessage);

    LogMessage errorMessage{ LogLevel::Error, LogFilter::Rendering, CORE_TOOLS_FUNCTION_DESCRIBED };
    errorMessage << gFileErrorMessage;
    appender.Write(errorMessage);

    LogMessage fatalMessage{ LogLevel::Fatal, LogFilter::Framework, CORE_TOOLS_FUNCTION_DESCRIBED };
    fatalMessage << gFileFatalMessage;
    appender.Write(fatalMessage);

    ASSERT_EQUAL(appender.GetDirectory(), gAppenderTestingPathName);
    ASSERT_EQUAL(appender.GetExtensionName(), gExtensionName);
    ASSERT_EQUAL(appender.GetMaxFileSize(), maxFileSize);
    ASSERT_TRUE(appender.IsBackup());

    ASSERT_TRUE(appender.IsDefault());
    appender.SetIsDefault(false);
    ASSERT_FALSE(appender.IsDefault());
}

void CoreTools::AppenderTesting::FileContentTest()
{
    const IFStreamManager fileManager{ appenderTestingFullName };

    const auto fileContent = fileManager.GetFileContent();

    ASSERT_UNEQUAL(fileContent.find(gFileTraceMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gFileDebugMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gFileInfoMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gFileWarnMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gFileErrorMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gFileFatalMessage), System::String::npos);
}

void CoreTools::AppenderTesting::BackupFileTest()
{
    const Appender appender{ gAppenderTestingPathName, gAppenderTestingFileName, AppenderPrint::All, LogLevel::Trace, 1, true, SYSTEM_TEXT("log"s) };

    backupFileName = GetBackupFileName();

    LogMessage backupMessage(LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED);
    backupMessage << gBackupMessage;
    appender.Write(backupMessage);
}

void CoreTools::AppenderTesting::BackupFileContentTest()
{
    const IFStreamManager fileManager{ appenderTestingFullName };

    const auto fileContent = fileManager.GetFileContent();

    ASSERT_UNEQUAL(fileContent.find(gBackupMessage), System::String::npos);
    ASSERT_EQUAL(fileContent.find(gFileTraceMessage), System::String::npos);
    ASSERT_EQUAL(fileContent.find(gFileDebugMessage), System::String::npos);
    ASSERT_EQUAL(fileContent.find(gFileInfoMessage), System::String::npos);
    ASSERT_EQUAL(fileContent.find(gFileWarnMessage), System::String::npos);
    ASSERT_EQUAL(fileContent.find(gFileErrorMessage), System::String::npos);
    ASSERT_EQUAL(fileContent.find(gFileFatalMessage), System::String::npos);

    const IFStreamManager backupFileManager{ backupFileName };

    const auto backupFileContent = backupFileManager.GetFileContent();

    ASSERT_UNEQUAL(backupFileContent.find(gFileTraceMessage), System::String::npos);
    ASSERT_UNEQUAL(backupFileContent.find(gFileDebugMessage), System::String::npos);
    ASSERT_UNEQUAL(backupFileContent.find(gFileInfoMessage), System::String::npos);
    ASSERT_UNEQUAL(backupFileContent.find(gFileWarnMessage), System::String::npos);
    ASSERT_UNEQUAL(backupFileContent.find(gFileErrorMessage), System::String::npos);
    ASSERT_UNEQUAL(backupFileContent.find(gFileFatalMessage), System::String::npos);
}

void CoreTools::AppenderTesting::DeleteFileTest()
{
    DeleteFileTools file{ appenderTestingFullName };
    DeleteFileTools backupFile{ backupFileName };
}

System::String CoreTools::AppenderTesting::GetBackupFileName()
{
    System::String backupName{ appenderTestingName };

    const auto nowTime = boost::posix_time::second_clock::local_time();

    boost::basic_format<System::TChar> basicFormat{ SYSTEM_TEXT("(%1%)."s) };
    basicFormat % boost::posix_time::to_iso_string_type<System::TChar>(nowTime);

    backupName += basicFormat.str();
    backupName += gExtensionName;

    return backupName;
}

void CoreTools::AppenderTesting::SetLogLevelTest()
{
    Appender appender(AppenderPrint::All, LogLevel::Trace);

    ASSERT_ENUM_EQUAL(appender.GetLogLevel(), LogLevel::Trace);

    appender.SetLogLevel(LogLevel::Fatal);

    ASSERT_ENUM_EQUAL(appender.GetLogLevel(), LogLevel::Fatal);
}

void CoreTools::AppenderTesting::FileConfigurationTest()
{
    constexpr auto maxFileSize = 100000;
    Appender appender{ gAppenderTestingPathName, AppenderPrint::All, LogLevel::Trace, maxFileSize, true, gExtensionName };

    ASSERT_ENUM_EQUAL(appender.GetFlags(), AppenderPrint::All);
    ASSERT_ENUM_EQUAL(appender.GetLogLevel(), LogLevel::Trace);
    ASSERT_ENUM_EQUAL(appender.GetAppenderType(), AppenderType::FileConfiguration);

    LogMessage traceMessage{ LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };
    traceMessage << gFileTraceMessage;
    appender.Write(traceMessage);

    LogMessage debugMessage{ LogLevel::Debug, LogFilter::System, CORE_TOOLS_FUNCTION_DESCRIBED };
    debugMessage << gFileDebugMessage;
    appender.Write(debugMessage);

    LogMessage infoMessage{ LogLevel::Info, LogFilter::SoundEffect, CORE_TOOLS_FUNCTION_DESCRIBED };
    infoMessage << gFileInfoMessage;
    appender.Write(infoMessage);

    LogMessage warnMessage{ LogLevel::Warn, LogFilter::Physics, CORE_TOOLS_FUNCTION_DESCRIBED };
    warnMessage << gFileWarnMessage;
    appender.Write(warnMessage);

    LogMessage errorMessage{ LogLevel::Error, LogFilter::Rendering, CORE_TOOLS_FUNCTION_DESCRIBED };
    errorMessage << gFileErrorMessage;
    appender.Write(errorMessage);

    LogMessage fatalMessage{ LogLevel::Fatal, LogFilter::Framework, CORE_TOOLS_FUNCTION_DESCRIBED };
    fatalMessage << gFileFatalMessage;
    appender.Write(fatalMessage);

    ASSERT_EQUAL(appender.GetDirectory(), gAppenderTestingPathName);
    ASSERT_EQUAL(appender.GetExtensionName(), gExtensionName);
    ASSERT_EQUAL(appender.GetMaxFileSize(), maxFileSize);
    ASSERT_TRUE(appender.IsBackup());

    ASSERT_TRUE(appender.IsDefault());
    appender.SetIsDefault(false);
    ASSERT_FALSE(appender.IsDefault());
}