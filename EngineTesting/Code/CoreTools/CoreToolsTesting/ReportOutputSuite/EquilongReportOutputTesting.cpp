///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 10:40)

#include "EquilongReportOutputTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ReportOutput/EquidistantReportOutput.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::EquilongReportOutputTesting::EquilongReportOutputTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EquilongReportOutputTesting)

void CoreTools::EquilongReportOutputTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::EquilongReportOutputTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReportOutputTest);
}

void CoreTools::EquilongReportOutputTesting::ReportOutputTest()
{
    const auto characterContent = "这里的文字被两行^包围，且与文字长度一致!"s;
    EquidistantReportOutput output{ boost::numeric_cast<int>(characterContent.size()), GetStream() };

    output.PrintBorderLine('^');
    output.PrintNewLine();
    output.PrintString(characterContent);
    output.PrintNewLine();
    output.PrintBorderLine('^');
    output.PrintNewLine();
}
