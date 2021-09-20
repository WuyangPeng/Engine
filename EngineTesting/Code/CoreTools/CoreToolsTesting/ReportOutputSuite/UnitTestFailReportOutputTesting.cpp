// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:10)

#include "UnitTestFailReportOutputTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestFailReportOutput.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, UnitTestFailReportOutputTesting)

void CoreTools::UnitTestFailReportOutputTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ReportOutputTest);
}

void CoreTools::UnitTestFailReportOutputTesting
	::ReportOutputTest()
{
	UnitTestFailReportOutput output{ "ClassName"s,"FileName"s,0,""s,GetStream() };

	output.PrintFailClassInformation();
	output.PrintFailFileName();
	output.PrintFailLineNumber();
	output.PrintNewLine();
}

