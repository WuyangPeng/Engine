// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 17:55)

#include "CoreTools/CoreToolsExport.h"

#include "TimeReportOutput.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "System/Helper/PragmaWarning/PosixTime.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::setw;
using std::right;
using std::string;
using std::ostream;

CoreTools::TimeReportOutput
	::TimeReportOutput(const string& timeDescribe, int borderLineLength, ostream* osPtr)
	:EquilongReportOutputImpl{ borderLineLength,osPtr }, m_TimeDescribe{ timeDescribe }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::TimeReportOutput
	::~TimeReportOutput()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TimeReportOutput)

void CoreTools::TimeReportOutput
	::PrintCurrentTime()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto nowTime = boost::posix_time::second_clock::local_time();
	string formattingTime{ m_TimeDescribe + "时间：" + boost::posix_time::to_simple_string(nowTime) };

	*GetStream() << setw(GetBorderLineLength()) << right << formattingTime;
}

void CoreTools::TimeReportOutput
	::PrintCostTime(const CpuTimerPtr& cpuTime)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	string costTime{ m_TimeDescribe + "时间：\n" + cpuTime->format() };
	PrintString(costTime);
}
