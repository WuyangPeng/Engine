// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.3 (2020/03/05 17:37)

#include "LogTesting.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/FileManager/DeleteFileTools.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogTesting)

void CoreTools::LogTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(LoadConfigurationTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OutTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AppenderTest);
}

void CoreTools::LogTesting
	::LoadConfigurationTest()
{
	LOG_SINGLETON.LoadConfiguration("Configuration/Log.json");
}

void CoreTools::LogTesting
	::OutTest() noexcept
{
	LOG_SINGLETON_APPENDER(Trace, CoreTools)
		<< SYSTEM_TEXT("日志跟踪信息测试")
		<< LogAppenderIOManageSign::Refresh;

	LOG_SINGLETON_APPENDER(Debug, CoreTools)
		<< SYSTEM_TEXT("日志调试信息测试")
		<< LogAppenderIOManageSign::Refresh;

	LOG_SINGLETON_APPENDER(Info, CoreTools)
		<< SYSTEM_TEXT("日志一般信息测试")
		<< LogAppenderIOManageSign::Refresh;

	LOG_SINGLETON_APPENDER(Warn, CoreTools)
		<< SYSTEM_TEXT("日志警告信息测试")
		<< LogAppenderIOManageSign::Refresh;

	LOG_SINGLETON_APPENDER(Error, CoreTools)
		<< SYSTEM_TEXT("日志错误信息测试")
		<< LogAppenderIOManageSign::Refresh;

	LOG_SINGLETON_APPENDER(Fatal, CoreTools)
		<< SYSTEM_TEXT("日志致命错误信息测试")
		<< LogAppenderIOManageSign::Refresh;
}

void CoreTools::LogTesting
	::AppenderTest()
{
	const auto testName = SYSTEM_TEXT("Test"s);
	const auto pathName = SYSTEM_TEXT("Log/"s);
	const auto extensionName = SYSTEM_TEXT("log"s);

	auto name = pathName + testName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) + SYSTEM_TEXT("."s) + extensionName;

	DeleteFileTools file{ name };

	Appender appender{ SYSTEM_TEXT("Log"s),testName,AppenderPrint::All, LogLevel::Trace, 100000, true, extensionName };

	LOG_SINGLETON.InsertAppender(testName, appender);
	LOG_SINGLETON.RemoveAppender(testName);
	LOG_SINGLETON.ReloadAppenderFile();
}

