///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:26)

#include "EquidistantReportOutputTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ReportOutput/EquidistantReportOutput.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::EquidistantReportOutputTesting::EquidistantReportOutputTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EquidistantReportOutputTesting)

void CoreTools::EquidistantReportOutputTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::EquidistantReportOutputTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReportOutputTest);
}

void CoreTools::EquidistantReportOutputTesting::ReportOutputTest()
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
