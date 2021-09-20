// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 15:07)

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
	const string characterContent{ "��������ֱ�����^��Χ���������ֳ���һ��!"s };
	EquilongReportOutput output{ boost::numeric_cast<int>(characterContent.size()),GetStream() };

	output.PrintBorderLine('^');
	output.PrintNewLine();
	output.PrintString(characterContent);
	output.PrintNewLine();
	output.PrintBorderLine('^');
	output.PrintNewLine();
}

