///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:43)

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
#include "CoreTools/LogManager/LogAsynchronous.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"

#include <iomanip>

using namespace std::literals;

CoreTools::UnitTest::UnitTest(const OStreamShared& streamShared)
    : ParentType{ streamShared }, unitTestData{ std::make_shared<UnitTestData>() }, cpuTimer{ CpuTimerData::CreateSharedPtr() }
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
        unitTestData = std::move(rhs.unitTestData);
        cpuTimer = std::move(rhs.cpuTimer);

        ParentType::operator=(std::move(rhs));
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

std::string CoreTools::UnitTest::GetAssertDescribed(const std::string& assertMessage, const std::string& errorMessage)
{
    std::string result{ assertMessage };

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

std::string CoreTools::UnitTest::GetTestModeDescribe() const
{
    return "花费"s;
}

void CoreTools::UnitTest::ResetTestData()
{
    unitTestData->ClearData();
    cpuTimer->Start();

    ResetOtherData();
}

void CoreTools::UnitTest::ResetOtherData()
{
    DisableNoexcept();
}

void CoreTools::UnitTest::RunUnitTest()
{
    TestTimingBegins();
    DoRunUnitTest();
    TestTimingEnd();
}

void CoreTools::UnitTest::TestTimingBegins()
{
    DisableNoexcept();

    if (unitTestData->IsEmpty())
        cpuTimer->Start();
    else
        cpuTimer->Resume();
}

void CoreTools::UnitTest::TestTimingEnd()
{
    DisableNoexcept();

    cpuTimer->Stop();
}

void CoreTools::UnitTest::AssertTest(bool condition, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
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

            THROW_EXCEPTION(exceptionMessage)
        }
    }
}

void CoreTools::UnitTest::AssertTrue() noexcept
{
    unitTestData->AddPassedNumber();
}

void CoreTools::UnitTest::ErrorTest(bool condition, const FunctionDescribed& functionDescribed, const std::string& errorMessage)
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

void CoreTools::UnitTest::PrintFailReport(const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
    UnitTestFailPrintManager manager{ *this, functionDescribed.GetFileName(), functionDescribed.GetLine(), errorMessage };

    manager.PrintFailClassInformation();
    manager.PrintFailFileName();
    manager.PrintFailLineNumber();
    manager.PrintErrorMessage();
}

std::string CoreTools::UnitTest::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return typeid(*this).name();
}

void CoreTools::UnitTest::AssertExceptionInfoLog(const Error& error, const std::string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools, GetCorrectThrowExceptionDescribe(), errorMessage, " ", error);

    ErrorTest(true, error.GetFunctionDescribed(), GetCorrectThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionInfoLog(const std::exception& error, const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, functionDescribed, GetCorrectThrowExceptionDescribe(), errorMessage, " ", error);

    ErrorTest(true, functionDescribed, GetCorrectThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionInfoLog(const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Warn, CoreTools, functionDescribed, GetCorrectThrowExceptionDescribe(), errorMessage);

    ErrorTest(true, functionDescribed, GetCorrectThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionErrorLog(const Error& error, const std::string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, GetErrorThrowExceptionDescribe(), errorMessage, " ", error, CoreTools::LogAppenderIOManageSign::TriggerAssert);

    ErrorTest(false, error.GetFunctionDescribed(), GetErrorThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionErrorLog(const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Error, CoreTools, functionDescribed, GetErrorNothrowExceptionDescribe(), errorMessage, CoreTools::LogAppenderIOManageSign::TriggerAssert);

    ErrorTest(false, functionDescribed, GetErrorNothrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionFatalLog(const std::exception& error, const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Error, CoreTools, functionDescribed, GetErrorThrowExceptionDescribe(), errorMessage, " ", error, CoreTools::LogAppenderIOManageSign::TriggerAssert);

    ErrorTest(false, functionDescribed, GetErrorThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertExceptionFatalLog(const FunctionDescribed& functionDescribed, const std::string& errorMessage)
{
    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Fatal, CoreTools, functionDescribed, GetErrorThrowExceptionDescribe(), errorMessage, CoreTools::LogAppenderIOManageSign::TriggerAssert);

    ErrorTest(false, functionDescribed, GetErrorThrowExceptionDescribe());
}

void CoreTools::UnitTest::AssertFloatingPointCompleteEqual(float lhs, float rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto completeLhs = *reinterpret_cast<uint32_t*>(&lhs);
    const auto completeRhs = *reinterpret_cast<uint32_t*>(&rhs);

#include STSTEM_WARNING_POP

    AssertEqual(completeLhs, completeRhs, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest::AssertFloatingPointCompleteEqual(double lhs, double rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
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

void CoreTools::UnitTest::AssertFloatingPointCompleteUnequal(double lhs, double rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto completeLhs = *reinterpret_cast<uint64_t*>(&lhs);
    const auto completeRhs = *reinterpret_cast<uint64_t*>(&rhs);

#include STSTEM_WARNING_POP

    AssertUnequal(completeLhs, completeRhs, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest::AssertEqual(wchar_t lhs, wchar_t rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    if (const auto condition = (lhs == rhs); condition)
    {
        AssertTrue();
    }
    else
    {
        std::stringstream stream{};

        stream << StringConversion::WideCharConversionMultiByte(std::wstring{ lhs }) << "不等于" << StringConversion::WideCharConversionMultiByte(std::wstring{ rhs });

        const auto described = GetAssertDescribed(stream.str(), errorMessage);

        AssertTest(condition, functionDescribed, described, failureThrow);
    }
}

void CoreTools::UnitTest::AssertEqual(const SimpleCSV::CellValue& lhs, const SimpleCSV::CellValue& rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
    if (const auto condition = (lhs == rhs); condition)
    {
        AssertTrue();
    }
    else
    {
        AssertTest(condition, functionDescribed, errorMessage, failureThrow);
    }
}

void CoreTools::UnitTest::PrintRunUnitTest()
{
    const auto runUnitTest = "正在运行测试 \""s + GetName() + "\"。\n"s;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(GetStream(), runUnitTest);

    PrintTipsMessage();
}

void CoreTools::UnitTest::PrintTipsMessage()
{
    DisableNoexcept();
}