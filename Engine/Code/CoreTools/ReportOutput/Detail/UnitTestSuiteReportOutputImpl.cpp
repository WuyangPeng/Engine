//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 10:16)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestSuiteReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

#include <iomanip>

using std::left;
using std::make_shared;
using std::right;
using std::setw;
using std::string;
using namespace std::literals;

CoreTools::UnitTestSuiteReportOutputImpl::UnitTestSuiteReportOutputImpl(const string& timeDescribe, int borderLineLength, const OStreamShared& streamShared)
    : ParentType{ timeDescribe, borderLineLength, streamShared }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestSuiteReportOutputImpl)

void CoreTools::UnitTestSuiteReportOutputImpl::PrintTestName(const string& testName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto characterString = "���� \""s + testName + "\"��"s;
    PrintString(characterString);
}

void CoreTools::UnitTestSuiteReportOutputImpl::PrintSuiteName(const string& suiteName)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto characterString = "�����׼� \""s + suiteName + "\"��"s;
    PrintString(characterString);
}

void CoreTools::UnitTestSuiteReportOutputImpl::PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto manager = GetLogConsoleTextColorsManager(failedNumber, errorNumber);

    GetStream() << setw(characterWidth) << right << "ͨ����"
                << setw(characterWidth) << left << passedNumber
                << setw(characterWidth) << right << "ʧ��: "
                << setw(characterWidth) << left << failedNumber
                << setw(characterWidth) << right << "����: "
                << setw(characterWidth) << left << errorNumber;
}

CoreTools::UnitTestSuiteReportOutputImpl::LogConsoleTextColorsManagerSharedPtr CoreTools::UnitTestSuiteReportOutputImpl::GetLogConsoleTextColorsManager(int failedNumber, int errorNumber)
{
    if (0 < errorNumber)
        return make_shared<LogConsoleTextColorsManager>(GetStream(), LogLevel::Fatal);
    else if (0 < failedNumber)
        return make_shared<LogConsoleTextColorsManager>(GetStream(), LogLevel::Error);
    else
        return nullptr;
}
