///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:20)

#include "EquilongReportOutputTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ReportOutput/EquilongReportOutput.h"

using std::string;
using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, EquilongReportOutputTesting)

void CoreTools::EquilongReportOutputTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReportOutputTest);
}

void CoreTools::EquilongReportOutputTesting::ReportOutputTest()
{
    const string characterContent{ "��������ֱ�����^��Χ���������ֳ���һ��!"s };
    EquilongReportOutput output{ boost::numeric_cast<int>(characterContent.size()), GetStream() };

    output.PrintBorderLine('^');
    output.PrintNewLine();
    output.PrintString(characterContent);
    output.PrintNewLine();
    output.PrintBorderLine('^');
    output.PrintNewLine();
}
