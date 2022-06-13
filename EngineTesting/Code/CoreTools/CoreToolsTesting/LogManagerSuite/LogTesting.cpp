///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:12)

#include "LogTesting.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/Time/CustomTime.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogTesting)

void CoreTools::LogTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadConfigurationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AppenderTest);
}

void CoreTools::LogTesting::LoadConfigurationTest()
{
    LOG_SINGLETON.LoadConfiguration("Configuration/Log.json");
}

void CoreTools::LogTesting::OutTest() noexcept
{
    LOG_SINGLETON_APPENDER(Trace, CoreTools)
        << SYSTEM_TEXT("��־������Ϣ����")
        << LogAppenderIOManageSign::Refresh;

    LOG_SINGLETON_APPENDER(Debug, CoreTools)
        << SYSTEM_TEXT("��־������Ϣ����")
        << LogAppenderIOManageSign::Refresh;

    LOG_SINGLETON_APPENDER(Info, CoreTools)
        << SYSTEM_TEXT("��־һ����Ϣ����")
        << LogAppenderIOManageSign::Refresh;

    LOG_SINGLETON_APPENDER(Warn, CoreTools)
        << SYSTEM_TEXT("��־������Ϣ����")
        << LogAppenderIOManageSign::Refresh;

    LOG_SINGLETON_APPENDER(Error, CoreTools)
        << SYSTEM_TEXT("��־������Ϣ����")
        << LogAppenderIOManageSign::Refresh;

    LOG_SINGLETON_APPENDER(Fatal, CoreTools)
        << SYSTEM_TEXT("��־����������Ϣ����")
        << LogAppenderIOManageSign::Refresh;
}

void CoreTools::LogTesting::AppenderTest()
{
    const auto testName = SYSTEM_TEXT("Test"s);
    const auto pathName = SYSTEM_TEXT("Log/"s);
    const auto extensionName = SYSTEM_TEXT("log"s);

    auto name = pathName + testName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) + SYSTEM_TEXT("."s) + extensionName;

    DeleteFileTools file{ name };

    Appender appender{ SYSTEM_TEXT("Log"s), testName, AppenderPrint::All, LogLevel::Trace, 100000, true, extensionName };

    LOG_SINGLETON.InsertAppender(testName, appender);
    LOG_SINGLETON.RemoveAppender(testName);
    LOG_SINGLETON.ReloadAppenderFile();
}
