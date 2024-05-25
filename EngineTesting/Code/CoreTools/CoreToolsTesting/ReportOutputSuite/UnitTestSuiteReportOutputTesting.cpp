/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 10:21)

#include "UnitTestSuiteReportOutputTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestSuiteReportOutput.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::UnitTestSuiteReportOutputTesting::UnitTestSuiteReportOutputTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestSuiteReportOutputTesting)

void CoreTools::UnitTestSuiteReportOutputTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::UnitTestSuiteReportOutputTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UnitTestSuiteReportOutputEquidistantTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnitTestSuiteReportOutputTimeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnitTestSuiteReportOutputTestResultTest);
}

void CoreTools::UnitTestSuiteReportOutputTesting::UnitTestSuiteReportOutputEquidistantTest()
{
    const auto characterContent = "��������ֱ�����-��Χ���������ֳ���һ��!"s;
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
    const auto currentTimeContent = "*************�����ӡ��ǰʱ�䣬���Ҷ���:"s;
    const auto costTimeContent = "*************�����ӡ����ʱ�䣬�������:"s;
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
    const auto colorContent =
        "�����������ڿ���̨����ʾΪ��ɫ��"
        "������������ʾΪ��ɫ��"
        "������������ʾΪ����ĺ�ɫ��";
    UnitTestSuiteReportOutput output{ "����"s, 20, GetStream() };

    output.PrintString(describeContent);
    output.PrintString(colorContent);
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
