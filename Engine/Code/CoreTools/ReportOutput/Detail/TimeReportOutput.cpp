/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:18)

#include "CoreTools/CoreToolsExport.h"

#include "TimeReportOutput.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "System/Helper/PragmaWarning/Timer.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogAsynchronous.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

#include <sstream>

using namespace std::literals;

CoreTools::TimeReportOutput::TimeReportOutput(std::string timeDescribe, int borderLineLength, const OStreamShared& streamShared) noexcept
    : EquidistantReportOutputImpl{ borderLineLength, streamShared }, timeDescribe{ std::move(timeDescribe) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TimeReportOutput)

void CoreTools::TimeReportOutput::PrintCurrentTime()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto nowTime = boost::posix_time::second_clock::local_time();
    const auto formattingTime = timeDescribe + "时间："s + to_simple_string(nowTime);

    std::stringstream ss{};

    ss << std::setw(GetBorderLineLength()) << std::right << formattingTime;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(GetStream(), ss.str());
}

void CoreTools::TimeReportOutput::PrintCostTime(const CpuTimer& cpuTime)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto logLevel = LogLevel::Disabled;

    if (10.0e9 <= cpuTime.elapsed().wall || 10.0e9 <= cpuTime.elapsed().user || 10.0e9 <= cpuTime.elapsed().system)
    {
        logLevel = LogLevel::Fatal;
    }
    else if (5.0e9 <= cpuTime.elapsed().wall || 5.0e9 <= cpuTime.elapsed().user || 5.0e9 <= cpuTime.elapsed().system)
    {
        logLevel = LogLevel::Error;
    }
    else if (1.0e9 <= cpuTime.elapsed().wall || 1.0e9 <= cpuTime.elapsed().user || 1.0e9 <= cpuTime.elapsed().system)
    {
        logLevel = LogLevel::Warn;
    }

    const auto costTime = timeDescribe + "时间：\n"s + cpuTime.format();

    LOG_ASYNCHRONOUS_SINGLETON.Registered(GetStream(), costTime, logLevel);
}
