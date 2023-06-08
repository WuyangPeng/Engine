///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:41)

#include "UnitTestFailReportOutputTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestFailReportOutput.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::UnitTestFailReportOutputTesting::UnitTestFailReportOutputTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestFailReportOutputTesting)

void CoreTools::UnitTestFailReportOutputTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::UnitTestFailReportOutputTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReportOutputTest);
}

void CoreTools::UnitTestFailReportOutputTesting::ReportOutputTest()
{
    UnitTestFailReportOutput output{ "ClassName"s, "FileName"s, 0, ""s, GetStream(), LogLevel::Trace };

    output.PrintFailClassInformation();
    output.PrintFailFileName();
    output.PrintFailLineNumber();
    output.PrintNewLine();
}
