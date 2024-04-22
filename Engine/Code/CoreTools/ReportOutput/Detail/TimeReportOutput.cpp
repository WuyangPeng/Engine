/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 11:06)

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
    const auto formattingTime = timeDescribe + "时间：" + to_simple_string(nowTime);

    std::stringstream ss{};

    ss << std::setw(GetBorderLineLength()) << std::right << formattingTime;

    LOG_ASYNCHRONOUS_SINGLETON.Registered(GetStream(), ss.str());
}

void CoreTools::TimeReportOutput::PrintCostTime(const CpuTimer& cpuTime)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto logLevel = LogLevel::Disabled;

    constexpr auto fatalTime = 10000000000ll;
    constexpr auto errorTime = 5000000000ll;
    constexpr auto warnTime = 1000000000ll;

    if (fatalTime <= cpuTime.elapsed().wall || fatalTime <= cpuTime.elapsed().user || fatalTime <= cpuTime.elapsed().system)
    {
        logLevel = LogLevel::Fatal;
    }
    else if (errorTime <= cpuTime.elapsed().wall || errorTime <= cpuTime.elapsed().user || errorTime <= cpuTime.elapsed().system)
    {
        logLevel = LogLevel::Error;
    }
    else if (warnTime <= cpuTime.elapsed().wall || warnTime <= cpuTime.elapsed().user || warnTime <= cpuTime.elapsed().system)
    {
        logLevel = LogLevel::Warn;
    }

    const auto costTime = timeDescribe + "时间：\n" + cpuTime.format();

    LOG_ASYNCHRONOUS_SINGLETON.Registered(GetStream(), costTime, logLevel);
}
