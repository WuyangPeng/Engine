// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:21)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestDetail.h"
#include "Detail/UnitTestData.h"
#include "Detail/CpuTimerData.h"
#include "Detail/UnitTestPrintManager.h"
#include "Detail/UnitTestFailPrintManager.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"

#include <iomanip>

using std::string;
using std::wstring;
using std::ostream;
using std::setw;
using std::left;
using std::right;
using std::exception;
using std::make_shared;

CoreTools::UnitTest
	::UnitTest(ostream* osPtr)
	:ParentType{ osPtr }, m_DataPtr{ make_shared<UnitTestData>() }, m_CpuTimerImplPtr{ make_shared<CpuTimerData>() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::UnitTest
	::~UnitTest()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTest
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_DataPtr != nullptr && m_CpuTimerImplPtr != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::UnitTest
	::GetPassedNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_DataPtr->GetPassedNumber();
}

int CoreTools::UnitTest
	::GetFailedNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_DataPtr->GetFailedNumber();
}

int CoreTools::UnitTest
	::GetErrorNumber() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_DataPtr->GetErrorNumber();
}

void CoreTools::UnitTest
	::PrintReport()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	constexpr auto characterWidth = 10;

	UnitTestPrintManager manager{ *this,"测试" + GetTestModeDescribe() };

	manager.PrintTestName();
	manager.PrintTestResult(characterWidth);
	manager.PrintCostTime(m_CpuTimerImplPtr->GetCpuTimerPtr());
}

// private
string CoreTools::UnitTest
	::GetTestModeDescribe() const
{
	return "花费";
}

void CoreTools::UnitTest
	::ResetTestData()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_DataPtr->ClearData();
	m_CpuTimerImplPtr->Start();

	ResetOtherData();
}

// private
void CoreTools::UnitTest
	::ResetOtherData()
{
}

void CoreTools::UnitTest
	::RunUnitTest()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	TestTimingBegins();
	DoRunUnitTest();
	TestTimingEnd();
}

// private
void CoreTools::UnitTest
	::TestTimingBegins()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (m_DataPtr->IsEmpty())
		m_CpuTimerImplPtr->Start();
	else
		m_CpuTimerImplPtr->Resume();
}

// private
void CoreTools::UnitTest
	::TestTimingEnd()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_CpuTimerImplPtr->Stop();
}

// protected
void CoreTools::UnitTest
	::AssertTest(bool condition, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (condition)
	{
		m_DataPtr->AddPassedNumber();
	}
	else
	{
		LogConsoleTextColorsManager manager{ GetStream(),LogLevel::Error };

		PrintFailReport(functionDescribed, errorMessage);

		m_DataPtr->AddFailedNumber();

		if (failureThrow)
		{
			auto exceptionMessage = StringConversion::MultiByteConversionStandard(errorMessage);

			THROW_EXCEPTION(exceptionMessage);
		}
	}
}

// protected
void CoreTools::UnitTest
	::ErrorTest(bool condition, const FunctionDescribed& functionDescribed, const string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (condition)
	{
		m_DataPtr->AddPassedNumber();
	}
	else
	{
		LogConsoleTextColorsManager manager{ GetStream(),LogLevel::Fatal };

		PrintFailReport(functionDescribed, errorMessage);

		m_DataPtr->AddErrorNumber();
	}
}

// private
void CoreTools::UnitTest
	::PrintFailReport(const FunctionDescribed& functionDescribed, const string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	UnitTestFailPrintManager manager{ *this,functionDescribed.GetFileName(),functionDescribed.GetLine(),errorMessage };

	manager.PrintFailClassInformation();
	manager.PrintFailFileName();
	manager.PrintFailLineNumber();
	manager.PrintErrorMessage();
}

const string CoreTools::UnitTest
	::GetName() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return typeid(*this).name();
}

// protected
void CoreTools::UnitTest
	::AssertExceptionInfoLog(const Error& error, const string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
		<< g_CorrectThrowExceptionDescribe
		<< errorMessage
		<< " "
		<< error
		<< LogAppenderIOManageSign::Refresh;

	ErrorTest(true, error.GetFunctionDescribed(), g_CorrectThrowExceptionDescribe);
}

void CoreTools::UnitTest
	::AssertExceptionInfoLog(const exception& error, const FunctionDescribed& functionDescribed, const string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, functionDescribed)
		<< g_CorrectThrowExceptionDescribe
		<< errorMessage
		<< " "
		<< error.what()
		<< LogAppenderIOManageSign::Refresh;

	ErrorTest(true, functionDescribed, g_CorrectThrowExceptionDescribe);
}

void CoreTools::UnitTest
	::AssertExceptionInfoLog(const FunctionDescribed& functionDescribed, const string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Warn, CoreTools, functionDescribed)
		<< g_CorrectThrowExceptionDescribe
		<< errorMessage
		<< LogAppenderIOManageSign::Refresh;

	ErrorTest(true, functionDescribed, g_CorrectThrowExceptionDescribe);
}

void CoreTools::UnitTest
	::AssertExceptionErrorLog(const Error& error, const string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
		<< g_ErrorThrowExceptionDescribe
		<< errorMessage
		<< " "
		<< error
		<< LOG_SINGLETON_TRIGGER_ASSERT;

	ErrorTest(false, error.GetFunctionDescribed(), g_ErrorThrowExceptionDescribe);
}

void CoreTools::UnitTest
	::AssertExceptionErrorLog(const FunctionDescribed& functionDescribed, const string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Error, CoreTools, functionDescribed)
		<< g_ErrorNothrowExceptionDescribe
		<< errorMessage
		<< LOG_SINGLETON_TRIGGER_ASSERT;

	ErrorTest(false, functionDescribed, g_ErrorNothrowExceptionDescribe);
}

void CoreTools::UnitTest
	::AssertExceptionFatalLog(const exception& error, const FunctionDescribed& functionDescribed, const string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Error, CoreTools, functionDescribed)
		<< g_ErrorThrowExceptionDescribe
		<< errorMessage
		<< " "
		<< error.what()
		<< LOG_SINGLETON_TRIGGER_ASSERT;

	ErrorTest(false, functionDescribed, g_ErrorThrowExceptionDescribe);
}

void CoreTools::UnitTest
	::AssertExceptionFatalLog(const FunctionDescribed& functionDescribed, const string& errorMessage)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Fatal, CoreTools, functionDescribed)
		<< g_ErrorThrowExceptionDescribe
		<< errorMessage
		<< LOG_SINGLETON_TRIGGER_ASSERT;

	ErrorTest(false, functionDescribed, g_ErrorThrowExceptionDescribe);
}

void CoreTools::UnitTest
	::AssertFloatingPointCompleteEqual(float lhs, float rhs, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto completeLhs = *reinterpret_cast<uint32_t*>(&lhs);
	auto completeRhs = *reinterpret_cast<uint32_t*>(&rhs);

	AssertEqual(completeLhs, completeRhs, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest
	::AssertFloatingPointCompleteEqual(double lhs, double rhs, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto completeLhs = *reinterpret_cast<uint64_t*>(&lhs);
	auto completeRhs = *reinterpret_cast<uint64_t*>(&rhs);

	AssertEqual(completeLhs, completeRhs, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest
	::AssertFloatingPointCompleteUnequal(float lhs, float rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto completeLhs = *reinterpret_cast<uint32_t*>(&lhs);
	auto completeRhs = *reinterpret_cast<uint32_t*>(&rhs);

	AssertUnequal(completeLhs, completeRhs, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest
	::AssertFloatingPointCompleteUnequal(double lhs, double rhs, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto completeLhs = *reinterpret_cast<uint64_t*>(&lhs);
	auto completeRhs = *reinterpret_cast<uint64_t*>(&rhs);

	AssertUnequal(completeLhs, completeRhs, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest
	::AssertEqual(const wstring& lhs, const wstring& rhs, const FunctionDescribed& functionDescribed, const string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto condition = (lhs == rhs);

	std::string described{};

	if (!condition)
	{
		std::stringstream stream{};

		stream << StringConversion::WideCharConversionMultiByte(lhs) << "不等于" << StringConversion::WideCharConversionMultiByte(rhs);

		if (!errorMessage.empty())
		{
			stream << " " << errorMessage;
		}

		described = stream.str();
	}

	AssertTest(condition, functionDescribed, described, failureThrow);
}

void CoreTools::UnitTest
	::AssertEqual(const char* lhs, const char* rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	AssertEqual(string{ lhs }, string{ rhs }, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest
	::AssertEqual(const wchar_t* lhs, const wchar_t* rhs, const FunctionDescribed& functionDescribed, const std::string& errorMessage, bool failureThrow)
{
	AssertEqual(wstring{ lhs }, wstring{ rhs }, functionDescribed, errorMessage, failureThrow);
}

void CoreTools::UnitTest
	::PrintRunUnitTest()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto runUnitTest = "正在运行测试 \"" + GetName() + "\"。\n";

	*GetStream() << runUnitTest;
}



