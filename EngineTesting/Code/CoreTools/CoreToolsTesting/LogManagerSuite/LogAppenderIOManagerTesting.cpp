///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:09)

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

using std::make_shared;
using std::ostream;
using std::string;
using std::wstring;
using namespace std::literals;

namespace
{
    const auto gAppenderTestingPathName = SYSTEM_TEXT("Log/"s);
    const auto gLogAppenderIOManageTestingFileName = SYSTEM_TEXT("LogAppenderIOManagerTestingFileName"s);
    const auto gExtensionName = SYSTEM_TEXT("log"s);

    constexpr auto integerTest = 3;
    const auto stringTest = "stringTest"s;
    const auto wstringTest = L"wstringTest"s;
    const CoreTools::Error errorTest{ CoreTools::FunctionDescribed("", __FILE__, __LINE__), System::WindowError::NoError, SYSTEM_TEXT("errorTest"s) };
    const auto promptMessage = SYSTEM_TEXT("本次断言触发只是测试，并没有错误产生。"s);
    const auto cancelMessage = SYSTEM_TEXT("请点击“否”取消。"s);
    const auto attentionMessage = SYSTEM_TEXT("请注意断言文件名及行号是否显示正确！"s);
    const auto formatMessage = SYSTEM_TEXT("格式化数字%1%%2%"s);
    const auto formatResultMessage = SYSTEM_TEXT("格式化数字1022"s);
}

CoreTools::LogAppenderIOManagerTesting::LogAppenderIOManagerTesting(const OStreamShared& stream)
    : ParentType{ stream },
      logAppenderIOManagerTestingName{ gAppenderTestingPathName + gLogAppenderIOManageTestingFileName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) },
      logAppenderIOManagerTestingFullName{ logAppenderIOManagerTestingName + SYSTEM_TEXT("."s) + gExtensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_0;
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
    ASSERT_NOT_THROW_EXCEPTION_0(Error1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(FormatTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogAppenderIOManageSignTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileContentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::LogAppenderIOManagerTesting::IntegerTest()
{
    auto appenderManager = GetAppenderManager();

    auto manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    manager << LogFilter::CoreTools
            << CORE_TOOLS_FUNCTION_DESCRIBED
            << integerTest;
}

void CoreTools::LogAppenderIOManagerTesting::StringTest()
{
    auto appenderManager = GetAppenderManager();

    auto manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    manager << LogFilter::CoreTools
            << CORE_TOOLS_FUNCTION_DESCRIBED
            << stringTest;

    manager << LogFilter::CoreTools
            << CORE_TOOLS_FUNCTION_DESCRIBED
            << wstringTest;
}

void CoreTools::LogAppenderIOManagerTesting::Error1Test()
{
    auto appenderManager = GetAppenderManager();

    auto manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    manager << LogFilter::CoreTools
            << errorTest;
}

void CoreTools::LogAppenderIOManagerTesting::FormatTest()
{
    auto appenderManager = GetAppenderManager();

    auto manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    manager << LogFilter::CoreTools
            << CORE_TOOLS_FUNCTION_DESCRIBED
            << (LogAppenderIOManager::Format(formatMessage) % 10 % 22).str();
}

void CoreTools::LogAppenderIOManagerTesting::LogAppenderIOManageSignTest()
{
    auto appenderManager = GetAppenderManager();

    auto manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    manager << LogFilter::CoreTools
            << CORE_TOOLS_FUNCTION_DESCRIBED
            << promptMessage
            << LogAppenderIOManageSign::AlwaysConsole
            << LogAppenderIOManageSign::BlankSpace
            << cancelMessage
            << LogAppenderIOManageSign::Newline
            << attentionMessage
            << LogAppenderIOManageSign::TriggerAssert
            << LogAppenderIOManageSign::Refresh;
}

void CoreTools::LogAppenderIOManagerTesting::FileContentTest()
{
    IFStreamManager fileManager{ logAppenderIOManagerTestingFullName };
    fileManager.SetSimplifiedChinese();

    auto fileContent = fileManager.GetFileContent();

    ASSERT_UNEQUAL(fileContent.find(System::ToString(integerTest)), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(StringConversion::MultiByteConversionStandard(stringTest)), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(StringConversion::WideCharConversionStandard(wstringTest)), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(errorTest.GetError()), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(formatResultMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(promptMessage + SYSTEM_TEXT(' ') + cancelMessage + SYSTEM_TEXT('\n') + attentionMessage), System::String::npos);
}

void CoreTools::LogAppenderIOManagerTesting::DeleteFileTest()
{
    DeleteFileTools file{ logAppenderIOManagerTestingFullName };
}

CoreTools::LogAppenderIOManagerTesting::AppenderManagerSharedPtr CoreTools::LogAppenderIOManagerTesting::GetAppenderManager()
{
    Appender appender{ SYSTEM_TEXT("Log"s), gLogAppenderIOManageTestingFileName, AppenderPrint::All, LogLevel::Trace, 100000, true, SYSTEM_TEXT("log"s) };

    Logger logger{ LogFilter::CoreTools, LogLevel::Trace };

    auto manager = AppenderManager::Create();

    MAYBE_UNUSED const auto value = manager->InsertLogger(logger);
    MAYBE_UNUSED auto value1 = manager->InsertAppender(SYSTEM_TEXT("FileAppender"s), appender);

    return manager;
}
