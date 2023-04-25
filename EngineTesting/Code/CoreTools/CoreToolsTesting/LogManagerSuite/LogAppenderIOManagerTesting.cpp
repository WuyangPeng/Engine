///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/12 14:19)

#include "LogAppenderIOManagerTesting.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogAppenderIOManager.h"
#include "CoreTools/LogManager/Logger.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace
{
    const auto gAppenderTestingPathName = SYSTEM_TEXT("Log/"s);
    const auto gLogAppenderIOManageTestingFileName = SYSTEM_TEXT("LogAppenderIOManagerTestingFileName"s);
    const auto gExtensionName = SYSTEM_TEXT("log"s);

    constexpr auto integerTest = 3;
    const auto stringTest = "stringTest"s;
    const auto wStringTest = L"wstringTest"s;
    const CoreTools::Error errorTest{ CoreTools::FunctionDescribed{ "", __FILE__, __LINE__ }, System::WindowError::NoError, SYSTEM_TEXT("errorTest"s) };
    const auto promptMessage = SYSTEM_TEXT("本次断言触发只是测试，并没有错误产生。"s);
    const auto cancelMessage = SYSTEM_TEXT("请点击“否”取消。"s);
    const auto attentionMessage = SYSTEM_TEXT("请注意断言文件名及行号是否显示正确！"s);
}

CoreTools::LogAppenderIOManagerTesting::LogAppenderIOManagerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      logAppenderIOManagerTestingName{ gAppenderTestingPathName + gLogAppenderIOManageTestingFileName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) },
      logAppenderIOManagerTestingFullName{ logAppenderIOManagerTestingName + SYSTEM_TEXT("."s) + gExtensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogAppenderIOManagerTesting)

void CoreTools::LogAppenderIOManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogAppenderIOManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogAppenderIOManageSignTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileContentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::LogAppenderIOManagerTesting::IntegerTest()
{
    const auto appenderManager = GetAppenderManager();

    auto manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    LogMessage logMessage{ LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };

    logMessage << integerTest;

    manager << logMessage;
}

void CoreTools::LogAppenderIOManagerTesting::StringTest()
{
    const auto appenderManager = GetAppenderManager();

    auto manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    LogMessage logMessage{ LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };

    logMessage << stringTest
               << wStringTest;

    manager << logMessage;
}

void CoreTools::LogAppenderIOManagerTesting::ExceptionTest()
{
    const auto appenderManager = GetAppenderManager();

    auto manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    LogMessage logMessage{ LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };

    logMessage << errorTest;

    manager << logMessage;
}

void CoreTools::LogAppenderIOManagerTesting::LogAppenderIOManageSignTest()
{
    const auto appenderManager = GetAppenderManager();

    auto manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    LogMessage logMessage{ LogLevel::Trace, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED };

    logMessage << promptMessage
               << LogAppenderIOManageSign::AlwaysConsole
               << SYSTEM_TEXT(' ')
               << cancelMessage
               << SYSTEM_TEXT('\n')
               << attentionMessage
               << LogAppenderIOManageSign::TriggerAssert;

    manager << logMessage;
}

void CoreTools::LogAppenderIOManagerTesting::FileContentTest()
{
    IFStreamManager fileManager{ logAppenderIOManagerTestingFullName };
    fileManager.SetSimplifiedChinese();

    auto fileContent = fileManager.GetFileContent();

    ASSERT_UNEQUAL(fileContent.find(System::ToString(integerTest)), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(StringConversion::MultiByteConversionStandard(stringTest)), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(StringConversion::WideCharConversionStandard(wStringTest)), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(errorTest.GetError()), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(promptMessage + SYSTEM_TEXT(' ') + cancelMessage + SYSTEM_TEXT('\n') + attentionMessage), System::String::npos);
}

void CoreTools::LogAppenderIOManagerTesting::DeleteFileTest()
{
    DeleteFileTools file{ logAppenderIOManagerTestingFullName };
}

CoreTools::LogAppenderIOManagerTesting::AppenderManagerSharedPtr CoreTools::LogAppenderIOManagerTesting::GetAppenderManager()
{
    const Appender appender{ SYSTEM_TEXT("Log"s), gLogAppenderIOManageTestingFileName, AppenderPrint::All, LogLevel::Trace, 100000, true, SYSTEM_TEXT("log"s) };

    const Logger logger{ LogFilter::CoreTools, LogLevel::Trace };

    auto manager = AppenderManager::Create();

    MAYBE_UNUSED const auto value = manager->InsertLogger(logger);
    MAYBE_UNUSED auto value1 = manager->InsertAppender(SYSTEM_TEXT("FileAppender"s), appender);

    return manager;
}

void CoreTools::LogAppenderIOManagerTesting::SetAppenderManagerTest()
{
    const auto appenderManager = GetAppenderManager();

    auto manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    manager.SetAppenderManager(appenderManager);
}