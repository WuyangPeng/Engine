///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 16:37)

#include "Framework/FrameworkExport.h"

#include "PerformanceMeasurementsImpl.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::PerformanceMeasurementsImpl::PerformanceMeasurementsImpl(int maxTimer) noexcept
    : customTime{}, accumulatedTime{ 0 }, frameCount{ 0 }, accumulatedFrameCount{ 0 }, timer{ maxTimer }, maxTimer{ maxTimer }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::PerformanceMeasurementsImpl::IsValid() const noexcept
{
    if (0 <= accumulatedTime && 0 <= frameCount && 0 <= accumulatedFrameCount && 0 <= timer && 0 <= maxTimer)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

double Framework::PerformanceMeasurementsImpl::GetFrameRate() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    if (0 < accumulatedTime)
        return accumulatedFrameCount / boost::numeric_cast<double>(accumulatedTime) * System::gMillisecond;
    else
        return 0.0;
}

std::string Framework::PerformanceMeasurementsImpl::GetFrameRateMessage() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    boost::format message{ "fps: %.2lf" };
    message % GetFrameRate();

    return message.str();
}

void Framework::PerformanceMeasurementsImpl::ResetTime() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    customTime.ResetCustomTime();

    accumulatedTime = 0;
    frameCount = 0;
    accumulatedFrameCount = 0;
    timer = maxTimer;
}

void Framework::PerformanceMeasurementsImpl::MeasureTime() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (--timer == 0)
    {
        const auto delta = customTime.GetThisElapsedMillisecondTime();
        accumulatedTime += delta;
        accumulatedFrameCount += frameCount;
        frameCount = 0;
        timer = maxTimer;
    }
}

void Framework::PerformanceMeasurementsImpl::UpdateFrameCount() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ++frameCount;
}
