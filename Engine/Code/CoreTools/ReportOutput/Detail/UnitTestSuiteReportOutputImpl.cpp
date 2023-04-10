///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 15:51)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestSuiteReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogAsynchronous.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

#include <iomanip>
#include <sstream>

using namespace std::literals;

CoreTools::UnitTestSuiteReportOutputImpl::UnitTestSuiteReportOutputImpl(const std::string& timeDescribe, int borderLineLength, const OStreamShared& streamShared)
    : ParentType{ timeDescribe, borderLineLength, streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestSuiteReportOutputImpl)

void CoreTools::UnitTestSuiteReportOutputImpl::PrintTestName(const std::string& testName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto characterString = "���� \""s + testName + "\"��"s;
    PrintString(characterString);
}

void CoreTools::UnitTestSuiteReportOutputImpl::PrintSuiteName(const std::string& suiteName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto characterString = "�����׼� \""s + suiteName + "\"��"s;
    PrintString(characterString);
}

void CoreTools::UnitTestSuiteReportOutputImpl::PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto manager = GetLogConsoleTextColorsManager(failedNumber, errorNumber);

    std::stringstream ss{};

    ss << std::setw(characterWidth) << std::right << "ͨ����"
       << std::setw(characterWidth) << std::left << passedNumber
       << std::setw(characterWidth) << std::right << "ʧ��: "
       << std::setw(characterWidth) << std::left << failedNumber
       << std::setw(characterWidth) << std::right << "����: "
       << std::setw(characterWidth) << std::left << errorNumber;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(GetStream(), ss.str());
}

CoreTools::UnitTestSuiteReportOutputImpl::LogConsoleTextColorsManagerSharedPtr CoreTools::UnitTestSuiteReportOutputImpl::GetLogConsoleTextColorsManager(int failedNumber, int errorNumber)
{
    if (0 < errorNumber)
        return std::make_shared<LogConsoleTextColorsManager>(GetStream(), LogLevel::Fatal);
    else if (0 < failedNumber)
        return std::make_shared<LogConsoleTextColorsManager>(GetStream(), LogLevel::Error);
    else
        return nullptr;
}
