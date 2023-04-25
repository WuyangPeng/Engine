///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 19:34)

#include "ErrorTesting.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "System/Windows/LastPlatformError.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::ErrorTesting::ErrorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ErrorTesting)

void CoreTools::ErrorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ErrorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NormalErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WindowsErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenFileErrorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ComErrorTest);
    ASSERT_THROW_EXCEPTION_0(ThrowExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ThrowLastExceptionTest);
}

void CoreTools::ErrorTesting::NormalErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("错误"s);

    SetPlatformLastError(System::WindowError::Success);

    const LastError lastError{};
    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;
    const Error normalError{ functionDescribed, lastError, errorDescription };

    ASSERT_EQUAL(functionDescribed.GetCurrentFunction(), normalError.GetCurrentFunction());
    ASSERT_EQUAL(functionDescribed.GetFileName(), normalError.GetFileName());
    ASSERT_EQUAL(functionDescribed.GetLine(), normalError.GetLine());

    ASSERT_EQUAL(functionDescribed, normalError.GetFunctionDescribed());

    ASSERT_EQUAL(normalError.GetError(), errorDescription);
}

void CoreTools::ErrorTesting::WindowsErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("环境不正确。"s);

    SetPlatformLastError(System::WindowError::BadEnvironment);

    const LastError lastError{};
    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;
    const Error windowsError{ functionDescribed, lastError, System::String() };
    auto windowsErrorString = windowsError.GetError();

    ASSERT_EQUAL(functionDescribed.GetCurrentFunction(), windowsError.GetCurrentFunction());
    ASSERT_EQUAL(functionDescribed.GetFileName(), windowsError.GetFileName());
    ASSERT_EQUAL(functionDescribed.GetLine(), windowsError.GetLine());

    ASSERT_EQUAL(functionDescribed, windowsError.GetFunctionDescribed());

    ASSERT_UNEQUAL(windowsErrorString.find(errorDescription), System::String::npos);
}

void CoreTools::ErrorTesting::OpenFileErrorTest()
{
    const auto fileName = SYSTEM_TEXT("File.txt"s);
    Error::Format format{ SYSTEM_TEXT("%1% %2%") };
    format % SYSTEM_TEXT("系统找不到指定的文件 ");
    format % fileName;

    SetPlatformLastError(System::WindowError::FileNotFound);

    const LastError lastError{};

    const Error openFileError{ CORE_TOOLS_FUNCTION_DESCRIBED, lastError, fileName };
    const auto openFileErrorString = openFileError.GetError();

    ASSERT_EQUAL(openFileErrorString.find(format.str()), System::String::npos);
}

void CoreTools::ErrorTesting::ComErrorTest()
{
    const auto errorDescription = SYSTEM_TEXT("灾难性故障"s);

    const Error comError{ CORE_TOOLS_FUNCTION_DESCRIBED, System::WindowError::EUnexpected, SYSTEM_TEXT(""s) };

    auto comErrorString = comError.GetError();

    ASSERT_UNEQUAL(comErrorString.find(errorDescription), System::String::npos);
}

void CoreTools::ErrorTesting::ThrowExceptionTest()
{
    SetPlatformLastError(System::WindowError::BadLength);

    THROW_EXCEPTION((Error::Format(SYSTEM_TEXT("%1% %2% %3%")) % 21 % 22 % SYSTEM_TEXT("这里测试抛出异常。")).str())
}

void CoreTools::ErrorTesting::ThrowLastExceptionTest()
{
    THROW_LAST_ERROR_EXCEPTION(System::WindowError::FileNotFound, (Error::Format(SYSTEM_TEXT("%1% %2% %3%")) % 21 % 22 % SYSTEM_TEXT("这里测试抛出异常。")).str())
}
