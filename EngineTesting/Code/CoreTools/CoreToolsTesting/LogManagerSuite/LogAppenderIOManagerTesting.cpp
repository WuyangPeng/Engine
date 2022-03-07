// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/05 17:29)

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
namespace
{
    const auto g_AppenderTestingPathName = SYSTEM_TEXT("Log/"s);
    const auto g_LogAppenderIOManageTestingFileName = SYSTEM_TEXT("LogAppenderIOManagerTestingFileName"s);
    const auto g_ExtensionName = SYSTEM_TEXT("log"s);

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
#include STSTEM_WARNING_POP
CoreTools::LogAppenderIOManagerTesting ::LogAppenderIOManagerTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr },
      m_LogAppenderIOManagerTestingName{ g_AppenderTestingPathName + g_LogAppenderIOManageTestingFileName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) },
      m_LogAppenderIOManagerTestingFullName{ m_LogAppenderIOManagerTestingName + SYSTEM_TEXT("."s) + g_ExtensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_0;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogAppenderIOManagerTesting)
void CoreTools::LogAppenderIOManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogAppenderIOManagerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Error1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(FormatTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogAppenderIOManageSignTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileContentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::LogAppenderIOManagerTesting ::IntegerTest()
{
    auto appenderManager = GetAppenderManager();

    LogAppenderIOManager manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    manager << LogFilter::CoreTools
            << CORE_TOOLS_FUNCTION_DESCRIBED
            << integerTest;
}

void CoreTools::LogAppenderIOManagerTesting ::StringTest()
{
    auto appenderManager = GetAppenderManager();

    LogAppenderIOManager manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    manager << LogFilter::CoreTools
            << CORE_TOOLS_FUNCTION_DESCRIBED
            << stringTest;

    manager << LogFilter::CoreTools
            << CORE_TOOLS_FUNCTION_DESCRIBED
            << wstringTest;
}

void CoreTools::LogAppenderIOManagerTesting ::Error1Test()
{
    auto appenderManager = GetAppenderManager();

    LogAppenderIOManager manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    manager << LogFilter::CoreTools
            << errorTest;
}

void CoreTools::LogAppenderIOManagerTesting ::FormatTest()
{
    auto appenderManager = GetAppenderManager();

    LogAppenderIOManager manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

    manager << LogFilter::CoreTools
            << CORE_TOOLS_FUNCTION_DESCRIBED
            << (LogAppenderIOManager::Format(formatMessage) % 10 % 22).str();
}

void CoreTools::LogAppenderIOManagerTesting ::LogAppenderIOManageSignTest()
{
    auto appenderManager = GetAppenderManager();

    LogAppenderIOManager manager = LogAppenderIOManager::Create(LogLevel::Trace, appenderManager);

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

void CoreTools::LogAppenderIOManagerTesting ::FileContentTest()
{
    IFStreamManager fileManager(m_LogAppenderIOManagerTestingFullName);
    fileManager.SetSimplifiedChinese();

    auto fileContent = fileManager.GetFileContent();

    ASSERT_UNEQUAL(fileContent.find(System::ToString(integerTest)), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(StringConversion::MultiByteConversionStandard(stringTest)), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(StringConversion::WideCharConversionStandard(wstringTest)), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(errorTest.GetError()), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(formatResultMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(promptMessage + SYSTEM_TEXT(' ') + cancelMessage + SYSTEM_TEXT('\n') + attentionMessage), System::String::npos);
}

void CoreTools::LogAppenderIOManagerTesting ::DeleteFileTest()
{
    DeleteFileTools file{ m_LogAppenderIOManagerTestingFullName };
}

CoreTools::LogAppenderIOManagerTesting::AppenderManagerPtr CoreTools::LogAppenderIOManagerTesting ::GetAppenderManager()
{
    Appender appender{ SYSTEM_TEXT("Log"s), g_LogAppenderIOManageTestingFileName, AppenderPrint::All, LogLevel::Trace, 100000, true, SYSTEM_TEXT("log"s) };

    Logger logger{ LogFilter::CoreTools, LogLevel::Trace };

    AppenderManagerPtr manager = AppenderManager::Create();

    [[maybe_unused]] const auto value = manager->InsertLogger(logger);
    [[maybe_unused]] auto value1 = manager->InsertAppender(SYSTEM_TEXT("FileAppender"s), appender);

    return manager;
}
