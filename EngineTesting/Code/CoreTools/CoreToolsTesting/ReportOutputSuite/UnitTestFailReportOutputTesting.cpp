///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:20)

#include "UnitTestFailReportOutputTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestFailReportOutput.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, UnitTestFailReportOutputTesting)

void CoreTools::UnitTestFailReportOutputTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReportOutputTest);
}

void CoreTools::UnitTestFailReportOutputTesting::ReportOutputTest()
{
    UnitTestFailReportOutput output{ "ClassName"s, "FileName"s, 0, ""s, GetStream() };

    output.PrintFailClassInformation();
    output.PrintFailFileName();
    output.PrintFailLineNumber();
    output.PrintNewLine();
}
