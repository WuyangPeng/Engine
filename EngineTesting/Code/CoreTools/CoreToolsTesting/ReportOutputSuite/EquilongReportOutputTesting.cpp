// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.3 (2020/03/06 15:07)

#include "EquilongReportOutputTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ReportOutput/EquilongReportOutput.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, EquilongReportOutputTesting)

void CoreTools::EquilongReportOutputTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ReportOutputTest);
}

void CoreTools::EquilongReportOutputTesting
	::ReportOutputTest()
{
	const string characterContent{ "这里的文字被两行^包围，且与文字长度一致!"s };
	EquilongReportOutput output{ boost::numeric_cast<int>(characterContent.size()),GetStream() };

	output.PrintBorderLine('^');
	output.PrintNewLine();
	output.PrintString(characterContent);
	output.PrintNewLine();
	output.PrintBorderLine('^');
	output.PrintNewLine();
}

