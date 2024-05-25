/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/11 14:31)

#include "LogHelperTesting.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/IFileStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/LogManager/Appender.h"
#include "CoreTools/LogManager/AppenderManager.h"
#include "CoreTools/LogManager/LogAsynchronous.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/Time/CustomTime.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace
{
    const auto gLogHelperTestingPathName = SYSTEM_TEXT("Log/"s);

    const auto gLogHelperTestingFileName = SYSTEM_TEXT("LogHelperTestingFileName"s);
    const auto gExtensionName = SYSTEM_TEXT("log"s);

    const auto gTraceMessage = SYSTEM_TEXT("traceMessage\n"s);
    const auto gDebugMessage = SYSTEM_TEXT("debugMessage\n"s);
    const auto gInfoMessage = SYSTEM_TEXT("infoMessage\n"s);
    const auto gWarnMessage = SYSTEM_TEXT("warnMessage\n"s);
    const auto gErrorMessage = SYSTEM_TEXT("errorMessage\n"s);
    const auto gFatalMessage = SYSTEM_TEXT("fatalMessage\n"s);
}

CoreTools::LogHelperTesting::LogHelperTesting(const OStreamShared& stream)
    : ParentType{ stream },
      logHelperTestingName{ gLogHelperTestingPathName + gLogHelperTestingFileName + SYSTEM_TEXT("("s) + CustomTime::GetSystemTimeDescribe() + SYSTEM_TEXT(")"s) },
      logHelperTestingFullName{ logHelperTestingName + SYSTEM_TEXT("."s) + gExtensionName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogHelperTesting)

void CoreTools::LogHelperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogHelperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WriteMessageTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WriteMessageToFileTest);

    LOG_ASYNCHRONOUS_SINGLETON.Stop();
    LOG_ASYNCHRONOUS_SINGLETON.Run();

    ASSERT_NOT_THROW_EXCEPTION_0(FileContentTest);

    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::LogHelperTesting::WriteMessageTest()  
{
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageTest, LogLevel::Trace, gTraceMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageTest, LogLevel::Debug, gDebugMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageTest, LogLevel::Info, gInfoMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageTest, LogLevel::Warn, gWarnMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageTest, LogLevel::Error, gErrorMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageTest, LogLevel::Fatal, gFatalMessage);
}

void CoreTools::LogHelperTesting::DoWriteMessageTest(LogLevel logLevel, const String& message) noexcept
{
    const LogHelper logHelper(logLevel, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED, message);
}

void CoreTools::LogHelperTesting::FileContentTest()
{
    const IFileStreamManager fileManager{ logHelperTestingFullName };

    const auto fileContent = fileManager.GetFileContent();

    ASSERT_UNEQUAL(fileContent.find(gTraceMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gDebugMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gInfoMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gWarnMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gErrorMessage), System::String::npos);
    ASSERT_UNEQUAL(fileContent.find(gFatalMessage), System::String::npos);
}

void CoreTools::LogHelperTesting::DeleteFileTest()
{
    DeleteFileTools file{ logHelperTestingFullName };
}

void CoreTools::LogHelperTesting::WriteMessageToFileTest()  
{
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageToFileTest, LogLevel::Trace, gTraceMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageToFileTest, LogLevel::Debug, gDebugMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageToFileTest, LogLevel::Info, gInfoMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageToFileTest, LogLevel::Warn, gWarnMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageToFileTest, LogLevel::Error, gErrorMessage);
    ASSERT_NOT_THROW_EXCEPTION_2(DoWriteMessageToFileTest, LogLevel::Fatal, gFatalMessage);
}

void CoreTools::LogHelperTesting::DoWriteMessageToFileTest(LogLevel logLevel, const String& message) noexcept
{
    const LogHelper logHelper(LogFileName{ gLogHelperTestingFileName.c_str() }, logLevel, LogFilter::CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED, message);
}
