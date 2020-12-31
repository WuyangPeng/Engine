//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 10:14)

#include "CoreTools/CoreToolsExport.h"

#include "TimeReportOutput.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

using std::right;
using std::setw;
using std::string;
using namespace std::literals;

CoreTools::TimeReportOutput::TimeReportOutput(const string& timeDescribe, int borderLineLength, const OStreamShared& streamShared)
    : EquilongReportOutputImpl{ borderLineLength, streamShared }, m_TimeDescribe{ timeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TimeReportOutput)

void CoreTools::TimeReportOutput::PrintCurrentTime()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto nowTime = boost::posix_time::second_clock::local_time();
    auto formattingTime = m_TimeDescribe + "ʱ�䣺"s + boost::posix_time::to_simple_string(nowTime);

    GetStream() << setw(GetBorderLineLength()) << right << formattingTime;
}

void CoreTools::TimeReportOutput::PrintCostTime(const CpuTimer& cpuTime)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto costTime = m_TimeDescribe + "ʱ�䣺\n"s + cpuTime.format();
    PrintString(costTime);
}
