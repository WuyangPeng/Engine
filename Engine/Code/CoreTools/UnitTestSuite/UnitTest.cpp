///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/14 21:37)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestDetail.h"
#include "Detail/CpuTimerData.h"
#include "Detail/UnitTestData.h"
#include "Detail/UnitTestFailPrintManager.h"
#include "Detail/UnitTestPrintManager.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"

#include <iomanip>

using std::exception;
using std::left;
using std::make_shared;
using std::ostream;
using std::right;
using std::setw;
using std::string;
using std::stringstream;
using std::wstring;
using namespace std::literals;

CoreTools::UnitTest::UnitTest(const OStreamShared& streamShared)
    : ParentType{ streamShared }, unitTestData{ make_shared<UnitTestData>() }, cpuTimer{ CpuTimerData::CreateSharedPtr() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::UnitTest::UnitTest(UnitTest&& rhs) noexcept
    : ParentType{ std::move(rhs) }, unitTestData{ std::move(rhs.unitTestData) }, cpuTimer{ std::move(rhs.cpuTimer) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::UnitTest& CoreTools::UnitTest::operator=(UnitTest&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        ParentType::operator=(std::move(rhs));
        unitTestData = std::move(rhs.unitTestData);
        cpuTimer = std::move(rhs.cpuTimer);
    }

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTest::IsValid() const noexcept
{
    if (ParentType::IsValid() && unitTestData != nullptr && cpuTimer != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

string CoreTools::UnitTest::GetAssertDescribed(const string& assertMessage, const string& errorMessage)
{
    string result{ assertMessage };

    if (!errorMessage.empty())
    {
        result += " ";
        result += errorMessage;
    }

    return result;
}

int CoreTools::UnitTest::GetPassedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return unitTestData->GetPassedNumber();
}

int CoreTools::UnitTest::GetFailedNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return unitTestData->GetFailedNumber();
}

int CoreTools::UnitTest::GetErrorNumber() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return unitTestData->GetErrorNumber();
}

void CoreTools::UnitTest::PrintReport()
{
    constexpr auto characterWidth = 10;

    UnitTestPrintManager manager{ *this, "测试"s + GetTestModeDescribe() };

    manager.PrintTestName();
    manager.PrintTestResult(characterWidth);
    manager.PrintCostTime(*cpuTimer->GetCpuTimer());
}

// private
string CoreTools::UnitTest::GetTestModeDescribe() const
{
    return "花费"s;
}

void CoreTools::UnitTest::ResetTestData()
{
    unitTestData->ClearData();
    cpuTimer->Start();

    ResetOtherData();
}

// private
void CoreTools::UnitTest::ResetOtherData()
{
    CoreTools::DisableNoexcept();
}

void CoreTools::UnitTest::RunUnitTest()
{
    TestTimingBegins();
    DoRunUnitTest();
    TestTimingEnd();
}

// private
void CoreTools::UnitTest::TestTimingBegins()
{
    CoreTools::DisableNoexcept();

    if (unitTestData->IsEmpty())
        cpuTimer->Start();
    else
        cpuTimer->Resume();
}

// private
void CoreTools::UnitTest::TestTimingEnd()
{
    CoreTools::DisableNoexcept();

    cpuTimer->Stop();
}

// protected
void CoreTools::UnitTest::AssertTest(bool condition, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
    if (condition)
    {
        unitTestData->AddPassedNumber();
    }
    else
    {
        LogConsoleTextColorsManager manager{ GetStream(), LogLevel::Error };

        PrintFailReport(functionDescribed, errorMessage);

        unitTestData->AddFailedNumber();

        if (failureThrow)
        {
            const auto exceptionMessage = StringConversion::MultiByteConversionStandard(errorMessage);

            THROW_EXCEPTION(exceptionMessage);
        }
    }
}

void CoreTools::UnitTest::AssertTrue() noexcept
{
    unitTestData->AddPassedNumber();
}

// protected
void CoreTools::UnitTest::ErrorTest(bool condition, const FunctionDescribed& functionDescribed, const string& errorMessage)
{
    if (condition)
    {
        unitTestData->AddPassedNumber();
    }
    else
    {
        LogConsoleTextColorsManager manager{ GetStream(), LogLevel::Fatal };

        PrintFailReport(functionDescribed, errorMessage);

        unitTestData->AddErrorNumber();
    }
}

void CoreTools::UnitTest::ErrorTest(bool condition, const FunctionDescribed& functionDescribed, const std::string_view& errorMessage)
{
    if (condition)
    {
        unitTestData->AddPassedNumber();
    }
    else
    {
        LogConsoleTextColorsManager manager{ GetStream(), LogLevel::Fatal };

        PrintFailReport(functionDescribed, errorMessage.data());

        unitTestData->AddErrorNumber();
    }
}

// private
void CoreTools::UnitTest::PrintFailReport(const FunctionDescribed& functionDescribed, const string& errorMessage)
{
    UnitTestFailPrintManager manager{ *this, functionDescribed.GetFileName(), functionDescribed.GetLine(), errorMessage };

    manager.PrintFailClassInformation();
    manager.PrintFailFileName();
    manager.PrintFailLineNumber();
    manager.PrintErrorMessage();
}

string CoreTools::UnitTest::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return typeid(*this).name();
}

// protected
void CoreTools::UnitTest::AssertExceptionInfoLog(const Error& error, const string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
        << GetCorrectThrowExceptionDescribe()
        << errorMessage
        << " "
        << error
        << LogAppenderIOManageSign::Refresh;

    ErrorTest(true, error.GetFunctionDescribed(), GetCorrectThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionInfoLog(const exception& error, const FunctionDescribed& functionDescribed, const string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, functionDescribed)
        << GetCorrectThrowExceptionDescribe()
        << errorMessage
        << " "
        << error.what()
        << LogAppenderIOManageSign::Refresh;

    ErrorTest(true, functionDescribed, GetCorrectThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionInfoLog(const FunctionDescribed& functionDescribed, const string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Warn, CoreTools, functionDescribed)
        << GetCorrectThrowExceptionDescribe()
        << errorMessage
        << LogAppenderIOManageSign::Refresh;

    ErrorTest(true, functionDescribed, GetCorrectThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionErrorLog(const Error& error, const string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
        << GetErrorThrowExceptionDescribe()
        << errorMessage
        << " "
        << error
        << LOG_SINGLETON_TRIGGER_ASSERT;

    ErrorTest(false, error.GetFunctionDescribed(), GetErrorThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionErrorLog(const FunctionDescribed& functionDescribed, const string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Error, CoreTools, functionDescribed)
        << GetErrorNothrowExceptionDescribe()
        << errorMessage
        << LOG_SINGLETON_TRIGGER_ASSERT;

    ErrorTest(false, functionDescribed, GetErrorNothrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionFatalLog(const exception& error, const FunctionDescribed& functionDescribed, const string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Error, CoreTools, functionDescribed)
        << GetErrorThrowExceptionDescribe()
        << errorMessage
        << " "
        << error.what()
        << LOG_SINGLETON_TRIGGER_ASSERT;

    ErrorTest(false, functionDescribed, GetErrorThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionFatalLog(const FunctionDescribed& functionDescribed, const string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Fatal, CoreTools, functionDescribed)
        << GetErrorThrowExceptionDescribe()
        << errorMessage
        << LOG_SINGLETON_TRIGGER_ASSERT;

    ErrorTest(false, functionDescribed, GetErrorThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertFloatingPointCompleteEqual(float lhs, float rhs, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    const auto completeLhs = *reinterpret_cast<uint32_t*>(&lhs);
    const auto completeRhs = *reinterpret_cast<uint32_t*>(&rhs);
#include STSTEM_WARNING_POP

    AssertEqual(completeLhs, completeRhs, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest::AssertFloatingPointCompleteEqual(double lhs, double rhs, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    const auto completeLhs = *reinterpret_cast<uint64_t*>(&lhs);
    const auto completeRhs = *reinterpret_cast<uint64_t*>(&rhs);
#include STSTEM_WARNING_POP

    AssertEqual(completeLhs, completeRhs, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest::AssertFloatingPointCompleteUnequal(float lhs, float rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    const auto completeLhs = *reinterpret_cast<uint32_t*>(&lhs);
    const auto completeRhs = *reinterpret_cast<uint32_t*>(&rhs);
#include STSTEM_WARNING_POP

    AssertUnequal(completeLhs, completeRhs, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest::AssertFloatingPointCompleteUnequal(double lhs, double rhs, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    const auto completeLhs = *reinterpret_cast<uint64_t*>(&lhs);
    const auto completeRhs = *reinterpret_cast<uint64_t*>(&rhs);
#include STSTEM_WARNING_POP

    AssertUnequal(completeLhs, completeRhs, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest::AssertEqual(const wstring& lhs, const wstring& rhs, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
    const auto condition = (lhs == rhs);

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        stringstream stream{};

        stream << StringConversion::WideCharConversionMultiByte(lhs) << "不等于" << StringConversion::WideCharConversionMultiByte(rhs);

        const auto described = GetAssertDescribed(stream.str(), errorMessage);

        AssertTest(condition, functionDescribed, described, failureThrow);
    }
}

void CoreTools::UnitTest::AssertEqual(wchar_t lhs, wchar_t rhs, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
    const auto condition = (lhs == rhs);

    if (condition)
    {
        AssertTrue();
    }
    else
    {
        stringstream stream{};

        stream << StringConversion::WideCharConversionMultiByte(wstring{ lhs }) << "不等于" << StringConversion::WideCharConversionMultiByte(wstring{ rhs });

        const auto described = GetAssertDescribed(stream.str(), errorMessage);

        AssertTest(condition, functionDescribed, described, failureThrow);
    }
}

void CoreTools::UnitTest::AssertEqual(const char* lhs, const char* rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertEqual(string{ lhs }, string{ rhs }, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest::AssertEqual(const wchar_t* lhs, const wchar_t* rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    AssertEqual(wstring{ lhs }, wstring{ rhs }, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest::PrintRunUnitTest()
{
    auto runUnitTest = "正在运行测试 \""s + GetName() + "\"。\n"s;

    GetStream() << runUnitTest;

    PrintTipsMessage();
}

void CoreTools::UnitTest::PrintTipsMessage()
{
    DisableNoexcept();
}