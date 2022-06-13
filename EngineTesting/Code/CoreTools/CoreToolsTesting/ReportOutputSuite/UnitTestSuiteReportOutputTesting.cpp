///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:20)

#include "UnitTestSuiteReportOutputTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestSuiteReportOutput.h"

using std::make_shared;
using std::string;
using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, UnitTestSuiteReportOutputTesting)

void CoreTools::UnitTestSuiteReportOutputTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UnitTestSuiteReportOutputEquilongTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnitTestSuiteReportOutputTimeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnitTestSuiteReportOutputTestResultTest);
}

void CoreTools::UnitTestSuiteReportOutputTesting::UnitTestSuiteReportOutputEquilongTest()
{
    const string characterContent{ "��������ֱ�����-��Χ���������ֳ���һ��!"s };
    UnitTestSuiteReportOutput output{ "����"s, 40, GetStream() };

    output.PrintBorderLine('-');
    output.PrintNewLine();
    output.PrintString(characterContent);
    output.PrintNewLine();
    output.PrintBorderLine('-');
    output.PrintNewLine();
}

void CoreTools::UnitTestSuiteReportOutputTesting::UnitTestSuiteReportOutputTimeTest()
{
    const string currentTimeContent{ "*************�����ӡ��ǰʱ�䣬���Ҷ���:"s };
    const string costTimeContent{ "*************�����ӡ����ʱ�䣬�������:"s };
    UnitTestSuiteReportOutput output{ "����"s, boost::numeric_cast<int>(currentTimeContent.size()), GetStream() };
    const boost::timer::cpu_timer cpuTime{};

    output.PrintString(currentTimeContent);
    output.PrintNewLine();
    output.PrintCurrentTime();
    output.PrintNewLine();
    output.PrintString(costTimeContent);
    output.PrintNewLine();
    output.PrintCostTime(cpuTime);
    output.PrintNewLine();
}

void CoreTools::UnitTestSuiteReportOutputTesting::UnitTestSuiteReportOutputTestResultTest()
{
    const auto describeContent = "������������ִ�ӡ��ٵĵ�Ԫ���Խ����"s;
    const string colourContent{
        "�����������ڿ���̨����ʾΪ��ɫ��"
        "������������ʾΪ��ɫ��"
        "������������ʾΪ����ĺ�ɫ��"
    };
    UnitTestSuiteReportOutput output{ "����"s, 20, GetStream() };

    output.PrintString(describeContent);
    output.PrintString(colourContent);
    output.PrintNewLine();
    output.PrintSuiteName("Suite"s);
    output.PrintNewLine();
    output.PrintTestName("Test"s);
    output.PrintNewLine();
    output.PrintTestResult(10, 0, 0, 8);
    output.PrintNewLine();
    output.PrintTestResult(10, 2, 0, 8);
    output.PrintNewLine();
    output.PrintTestResult(10, 2, 2, 8);
    output.PrintNewLine();
}
