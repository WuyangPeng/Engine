/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/18 22:00)

#include "LogAppenderIOManagerSignTesting.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
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

    const auto promptMessage = SYSTEM_TEXT("本次断言触发只是测试，并没有错误产生。"s);
    const auto cancelMessage = SYSTEM_TEXT("请点击“否”取消。"s);
    const auto attentionMessage = SYSTEM_TEXT("请注意断言文件名及行号是否显示正确！"s);
}

CoreTools::LogAppenderIOManagerSignTesting::LogAppenderIOManagerSignTesting(const OStreamShared& stream)
    : ParentType{ stream },
      logAppenderIOManagerTestingName{ gAppenderTestingPathName + gLogAppenderIOManageTestingFileName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) },
      logAppenderIOManagerTestingFullName{ logAppenderIOManagerTestingName + SYSTEM_TEXT("."s) + gExtensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogAppenderIOManagerSignTesting)

void CoreTools::LogAppenderIOManagerSignTesting::PrintTipsMessage()
{
    GetStream() << "这个测试会触发失败断言，请按否取消。\n";

    System::SystemPause();
}

void CoreTools::LogAppenderIOManagerSignTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogAppenderIOManagerSignTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LogAppenderIOManageSignTest);
}

void CoreTools::LogAppenderIOManagerSignTesting::LogAppenderIOManageSignTest()
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

void CoreTools::LogAppenderIOManagerSignTesting::FileContentTest()
{
    IFileStreamManager fileManager{ logAppenderIOManagerTestingFullName };
    fileManager.SetSimplifiedChinese();

    auto fileContent = fileManager.GetFileContent();
    ASSERT_UNEQUAL(fileContent.find(promptMessage + SYSTEM_TEXT(' ') + cancelMessage + SYSTEM_TEXT('\n') + attentionMessage), System::String::npos);
}

void CoreTools::LogAppenderIOManagerSignTesting::DeleteFileTest()
{
    DeleteFileTools file{ logAppenderIOManagerTestingFullName };
}

CoreTools::LogAppenderIOManagerSignTesting::AppenderManagerSharedPtr CoreTools::LogAppenderIOManagerSignTesting::GetAppenderManager()
{
    const Appender appender{ SYSTEM_TEXT("Log"s), gLogAppenderIOManageTestingFileName, AppenderPrint::All, LogLevel::Trace, 100000, true, SYSTEM_TEXT("log"s) };

    const Logger logger{ LogFilter::CoreTools, LogLevel::Trace };

    auto manager = AppenderManager::Create();

    std::ignore = manager->InsertLogger(logger);
    std::ignore = manager->InsertAppender(SYSTEM_TEXT("FileAppender"s), appender);

    return manager;
}
