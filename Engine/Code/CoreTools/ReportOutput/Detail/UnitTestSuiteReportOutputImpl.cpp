/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 11:11)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestSuiteReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogAsynchronous.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

#include <iomanip>
#include <sstream>

CoreTools::UnitTestSuiteReportOutputImpl::UnitTestSuiteReportOutputImpl(const std::string& timeDescribe, int borderLineLength, const OStreamShared& streamShared)
    : ParentType{ timeDescribe, borderLineLength, streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestSuiteReportOutputImpl)

void CoreTools::UnitTestSuiteReportOutputImpl::PrintTestName(const std::string& testName) const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto characterString = "测试 \"" + testName + "\"：";
    PrintString(characterString);
}

void CoreTools::UnitTestSuiteReportOutputImpl::PrintSuiteName(const std::string& suiteName) const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto characterString = "测试套件 \"" + suiteName + "\"：";
    PrintString(characterString);
}

void CoreTools::UnitTestSuiteReportOutputImpl::PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto logLevel = GetLogLevel(failedNumber, errorNumber);

    std::stringstream ss{};

    ss << std::setw(characterWidth) << std::right << "通过："
       << std::setw(characterWidth) << std::left << passedNumber
       << std::setw(characterWidth) << std::right << "失败: "
       << std::setw(characterWidth) << std::left << failedNumber
       << std::setw(characterWidth) << std::right << "错误: "
       << std::setw(characterWidth) << std::left << errorNumber;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(GetStream(), ss.str(), logLevel);
}

CoreTools::LogLevel CoreTools::UnitTestSuiteReportOutputImpl::GetLogLevel(int failedNumber, int errorNumber) noexcept
{
    if (0 < errorNumber)
        return LogLevel::Fatal;
    else if (0 < failedNumber)
        return LogLevel::Error;
    else
        return LogLevel::Trace;
}
