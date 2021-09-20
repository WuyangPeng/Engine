// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.3 (2020/03/05 17:23)

#include "AppenderTesting.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "System/Helper/PragmaWarning/Gregorian.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/FileManager/DeleteFileTools.h"

#include <iostream>

using std::ostream;
using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
namespace
{
	const auto g_AppenderTestingPathName = SYSTEM_TEXT("Log/"s);

	const auto g_AppenderTestingFileName = SYSTEM_TEXT("AppenderTestingFileName"s);

	const auto g_ExtensionName = SYSTEM_TEXT("log"s);

	const auto g_FileTraceMessage = SYSTEM_TEXT("traceMessage\n"s);
	const auto g_FileDebugMessage = SYSTEM_TEXT("debugMessage\n"s);
	const auto g_FileInfoMessage = SYSTEM_TEXT("infoMessage\n"s);
	const auto g_FileWarnMessage = SYSTEM_TEXT("warnMessage\n"s);
	const auto g_FileErrorMessage = SYSTEM_TEXT("errorMessage\n"s);
	const auto g_FileFatalMessage = SYSTEM_TEXT("fatalMessage\n"s);
	const auto g_BackupMessage = SYSTEM_TEXT("backupMessage"s);

	const auto g_ConsoleTraceMessage = SYSTEM_TEXT("这条日志在控制台显示为白色。\n"s);
	const auto g_ConsoleDebugMessage = SYSTEM_TEXT("这条日志在控制台显示为青色。\n"s);
	const auto g_ConsoleInfoMessage = SYSTEM_TEXT("这条日志在控制台显示为绿色。\n"s);
	const auto g_ConsoleWarnMessage = SYSTEM_TEXT("这条日志在控制台显示为黄色。\n"s);
	const auto g_ConsoleErrorMessage = SYSTEM_TEXT("这条日志在控制台显示为红色。\n"s);
	const auto g_ConsoleFatalMessage = SYSTEM_TEXT("这条日志在控制台显示为加深的红色。\n"s);
}
#include STSTEM_WARNING_POP
CoreTools::AppenderTesting
	::AppenderTesting(const OStreamShared& osPtr)
	:ParentType{ osPtr },
	 m_AppenderTestingName{ g_AppenderTestingPathName + g_AppenderTestingFileName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) },
	 m_AppenderTestingFullName{ m_AppenderTestingName + SYSTEM_TEXT("."s) + g_ExtensionName }, m_BackupFileName{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_0;
}

 CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AppenderTesting)
void CoreTools::AppenderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::AppenderTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConsoleTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FileTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FileConfigurationTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetLogLevelTest);
}

// Console测试
void CoreTools::AppenderTesting
	::ConsoleTest()
{
	Appender appender{ AppenderPrint::All,LogLevel::Trace };

	ASSERT_ENUM_EQUAL(appender.GetFlags(), AppenderPrint::All);
	ASSERT_ENUM_EQUAL(appender.GetLogLevel(), LogLevel::Trace);
	ASSERT_ENUM_EQUAL(appender.GetAppenderType(), AppenderType::Console);

	LogMessage traceMessage{ LogLevel::Trace,LogFilter::CoreTools,g_ConsoleTraceMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(traceMessage);

	LogMessage debugMessage{ LogLevel::Debug,LogFilter::Framework,g_ConsoleDebugMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(debugMessage);

	LogMessage infoMessage{ LogLevel::Info,LogFilter::Mathematics,g_ConsoleInfoMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(infoMessage);

	LogMessage warnMessage{ LogLevel::Warn,LogFilter::Rendering,g_ConsoleWarnMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(warnMessage);

	LogMessage errorMessage{ LogLevel::Error,LogFilter::Physics,g_ConsoleErrorMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(errorMessage);

	LogMessage fatalMessage{ LogLevel::Fatal,LogFilter::System,g_ConsoleFatalMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(fatalMessage);

	ASSERT_TRUE(appender.GetDirectory().empty());
	ASSERT_TRUE(appender.GetExtensionName().empty());
	ASSERT_EQUAL(appender.GetMaxFileSize(), 0);
	ASSERT_FALSE(appender.IsBackup());
	appender.Reload();
	ASSERT_TRUE(appender.IsDefault());
	appender.SetIsDefault(false);
	ASSERT_FALSE(appender.IsDefault());
}

// File测试
void CoreTools::AppenderTesting
	::FileTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FileLogTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FileContentTest);
	ASSERT_NOT_THROW_EXCEPTION_0(BackupFileTest);
	ASSERT_NOT_THROW_EXCEPTION_0(BackupFileContentTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::AppenderTesting
	::FileLogTest()
{
	constexpr auto maxFileSize = 100000;
	Appender appender{ g_AppenderTestingPathName,g_AppenderTestingFileName,AppenderPrint::All  , LogLevel::Trace, maxFileSize,true, g_ExtensionName };

	ASSERT_ENUM_EQUAL(appender.GetFlags(), AppenderPrint::All);
	ASSERT_ENUM_EQUAL(appender.GetLogLevel(), LogLevel::Trace);
	ASSERT_ENUM_EQUAL(appender.GetAppenderType(), AppenderType::File);

	LogMessage traceMessage{ LogLevel::Trace,LogFilter::CoreTools,g_FileTraceMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(traceMessage);

	LogMessage debugMessage{ LogLevel::Debug,LogFilter::System,g_FileDebugMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(debugMessage);

	LogMessage infoMessage{ LogLevel::Info,LogFilter::SoundEffect,g_FileInfoMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(infoMessage);

	LogMessage warnMessage{ LogLevel::Warn,LogFilter::Physics,g_FileWarnMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(warnMessage);

	LogMessage errorMessage{ LogLevel::Error, LogFilter::Rendering,g_FileErrorMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(errorMessage);

	LogMessage fatalMessage{ LogLevel::Fatal,LogFilter::Framework,g_FileFatalMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(fatalMessage);

	ASSERT_EQUAL(appender.GetDirectory(), g_AppenderTestingPathName);
	ASSERT_EQUAL(appender.GetExtensionName(), g_ExtensionName);
	ASSERT_EQUAL(appender.GetMaxFileSize(), maxFileSize);
	ASSERT_TRUE(appender.IsBackup());
	appender.Reload();
	ASSERT_TRUE(appender.IsDefault());
	appender.SetIsDefault(false);
	ASSERT_FALSE(appender.IsDefault());
}

void CoreTools::AppenderTesting
	::FileContentTest()
{
	IFStreamManager fileManager{ m_AppenderTestingFullName };

	auto fileContent = fileManager.GetFileContent();

	ASSERT_UNEQUAL(fileContent.find(g_FileTraceMessage), System::String::npos);
	ASSERT_UNEQUAL(fileContent.find(g_FileDebugMessage), System::String::npos);
	ASSERT_UNEQUAL(fileContent.find(g_FileInfoMessage), System::String::npos);
	ASSERT_UNEQUAL(fileContent.find(g_FileWarnMessage), System::String::npos);
	ASSERT_UNEQUAL(fileContent.find(g_FileErrorMessage), System::String::npos);
	ASSERT_UNEQUAL(fileContent.find(g_FileFatalMessage), System::String::npos);
}

void CoreTools::AppenderTesting
	::BackupFileTest()
{
	Appender appender{ g_AppenderTestingPathName,g_AppenderTestingFileName,AppenderPrint::All, LogLevel::Trace, 1, true, SYSTEM_TEXT("log"s) };

	m_BackupFileName = GetBackupFileName();

	LogMessage backupMessage(LogLevel::Trace, LogFilter::CoreTools, g_BackupMessage, CORE_TOOLS_FUNCTION_DESCRIBED);
	appender.Write(backupMessage);
}

void CoreTools::AppenderTesting
	::BackupFileContentTest()
{
	IFStreamManager fileManager{ m_AppenderTestingFullName };

	auto fileContent = fileManager.GetFileContent();

	ASSERT_UNEQUAL(fileContent.find(g_BackupMessage), System::String::npos);
	ASSERT_EQUAL(fileContent.find(g_FileTraceMessage), System::String::npos);
	ASSERT_EQUAL(fileContent.find(g_FileDebugMessage), System::String::npos);
	ASSERT_EQUAL(fileContent.find(g_FileInfoMessage), System::String::npos);
	ASSERT_EQUAL(fileContent.find(g_FileWarnMessage), System::String::npos);
	ASSERT_EQUAL(fileContent.find(g_FileErrorMessage), System::String::npos);
	ASSERT_EQUAL(fileContent.find(g_FileFatalMessage), System::String::npos);

	IFStreamManager backupFileManager{ m_BackupFileName };

	auto backupFileContent = backupFileManager.GetFileContent();

	ASSERT_UNEQUAL(backupFileContent.find(g_FileTraceMessage), System::String::npos);
	ASSERT_UNEQUAL(backupFileContent.find(g_FileDebugMessage), System::String::npos);
	ASSERT_UNEQUAL(backupFileContent.find(g_FileInfoMessage), System::String::npos);
	ASSERT_UNEQUAL(backupFileContent.find(g_FileWarnMessage), System::String::npos);
	ASSERT_UNEQUAL(backupFileContent.find(g_FileErrorMessage), System::String::npos);
	ASSERT_UNEQUAL(backupFileContent.find(g_FileFatalMessage), System::String::npos);
}

void CoreTools::AppenderTesting
	::DeleteFileTest()
{
	DeleteFileTools file{ m_AppenderTestingFullName };
	DeleteFileTools backupFile{ m_BackupFileName };
}

System::String CoreTools::AppenderTesting
	::GetBackupFileName()
{
	System::String backupName{ m_AppenderTestingName };

	auto nowTime = boost::posix_time::second_clock::local_time();

	boost::basic_format<System::TChar> basicFormat{ SYSTEM_TEXT("(%1%)."s) };
	basicFormat % boost::posix_time::to_iso_string_type<System::TChar>(nowTime);

	backupName += basicFormat.str();
	backupName += g_ExtensionName;

	return backupName;
}

void CoreTools::AppenderTesting
	::SetLogLevelTest()
{
	Appender appender(AppenderPrint::All, LogLevel::Trace);

	ASSERT_ENUM_EQUAL(appender.GetLogLevel(), LogLevel::Trace);

	appender.SetLogLevel(LogLevel::Fatal);

	ASSERT_ENUM_EQUAL(appender.GetLogLevel(), LogLevel::Fatal);
}

void CoreTools::AppenderTesting
	::FileConfigurationTest()
{
	constexpr auto maxFileSize = 100000;
	Appender appender{ g_AppenderTestingPathName,AppenderPrint::All  , LogLevel::Trace, maxFileSize,true, g_ExtensionName };

	ASSERT_ENUM_EQUAL(appender.GetFlags(), AppenderPrint::All);
	ASSERT_ENUM_EQUAL(appender.GetLogLevel(), LogLevel::Trace);
	ASSERT_ENUM_EQUAL(appender.GetAppenderType(), AppenderType::FileConfiguration);

	LogMessage traceMessage{ LogLevel::Trace,LogFilter::CoreTools,g_FileTraceMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(traceMessage);

	LogMessage debugMessage{ LogLevel::Debug,LogFilter::System,g_FileDebugMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(debugMessage);

	LogMessage infoMessage{ LogLevel::Info,LogFilter::SoundEffect,g_FileInfoMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(infoMessage);

	LogMessage warnMessage{ LogLevel::Warn,LogFilter::Physics,g_FileWarnMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(warnMessage);

	LogMessage errorMessage{ LogLevel::Error, LogFilter::Rendering,g_FileErrorMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(errorMessage);

	LogMessage fatalMessage{ LogLevel::Fatal,LogFilter::Framework,g_FileFatalMessage, CORE_TOOLS_FUNCTION_DESCRIBED };
	appender.Write(fatalMessage);

	ASSERT_EQUAL(appender.GetDirectory(), g_AppenderTestingPathName);
	ASSERT_EQUAL(appender.GetExtensionName(), g_ExtensionName);
	ASSERT_EQUAL(appender.GetMaxFileSize(), maxFileSize);
	ASSERT_TRUE(appender.IsBackup());
	appender.Reload();
	ASSERT_TRUE(appender.IsDefault());
	appender.SetIsDefault(false);
	ASSERT_FALSE(appender.IsDefault());
}