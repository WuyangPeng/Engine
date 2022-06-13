///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 11:20)

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
    const string characterContent{ "这里的文字被两行-包围，且与文字长度一致!"s };
    UnitTestSuiteReportOutput output{ "测试"s, 40, GetStream() };

    output.PrintBorderLine('-');
    output.PrintNewLine();
    output.PrintString(characterContent);
    output.PrintNewLine();
    output.PrintBorderLine('-');
    output.PrintNewLine();
}

void CoreTools::UnitTestSuiteReportOutputTesting::UnitTestSuiteReportOutputTimeTest()
{
    const string currentTimeContent{ "*************这里打印当前时间，且右对齐:"s };
    const string costTimeContent{ "*************这里打印花费时间，且左对齐:"s };
    UnitTestSuiteReportOutput output{ "测试"s, boost::numeric_cast<int>(currentTimeContent.size()), GetStream() };
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
    const auto describeContent = "下面的五行文字打印虚假的单元测试结果："s;
    const string colourContent{
        "第三行文字在控制台中显示为白色，"
        "第四行文字显示为红色，"
        "第五行文字显示为加深的红色。"
    };
    UnitTestSuiteReportOutput output{ "测试"s, 20, GetStream() };

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
