///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/16 21:53)

#include "CoreTools/CoreToolsExport.h"

#include "CustomTime.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/Gregorian.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CustomTime::CustomTime() noexcept
    : startTime{ System::GetTimeInMicroseconds() }, currentTime{ 0 }, timeLastTick{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

System::String CoreTools::CustomTime::GetSystemTimeDescribe()
{
    auto nowTime = boost::posix_time::second_clock::local_time();

    return boost::gregorian::to_simple_string_type<System::TChar>(nowTime.date());
}

System::String CoreTools::CustomTime::GetSystemTimeDescribe(const String& dateFormat)
{
    const auto nowTime = boost::posix_time::second_clock::local_time();
    const auto data = nowTime.date();
    boost::basic_format<System::TChar> format{ dateFormat };

    format % data.year();
    format % data.month();
    format % data.day();

    return format.str();
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::CustomTime::IsValid() const noexcept
{
    if (0 <= startTime && 0 <= currentTime && 0 <= timeLastTick)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::CustomTime::ResetCustomTime() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    startTime = System::GetTimeInMicroseconds();
    currentTime = 0;
    timeLastTick = 0;
}

int64_t CoreTools::CustomTime::GetThisElapsedTime() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    MarkTimeThisTick();

    return timeLastTick / System::g_Microseconds;
}

int64_t CoreTools::CustomTime::GetNowTime() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    MarkTimeThisTick();

    return currentTime / System::g_Microseconds;
}

int64_t CoreTools::CustomTime::GetThisElapsedMillisecondTime() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    MarkTimeThisTick();

    return timeLastTick / System::g_Millisecond;
}

int64_t CoreTools::CustomTime::GetNowMillisecondTime() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    MarkTimeThisTick();

    return currentTime / System::g_Millisecond;
}

// private
void CoreTools::CustomTime::MarkTimeThisTick() noexcept
{
    const auto newTime = System::GetTimeInMicroseconds() - startTime;

    timeLastTick = newTime - currentTime;
    currentTime = newTime;

    if (timeLastTick <= 0)
    {
        timeLastTick = 0;
    }
}
