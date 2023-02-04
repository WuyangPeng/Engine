///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/02/01 23:38)

#include "System/SystemExport.h"

#include "DeltaTimeValueData.h"

System::DeltaTimeValueData::DeltaTimeValueData() noexcept
    : deltaTimeValue{}
{
}

System::DeltaTimeValueData::DeltaTimeValueData(const DeltaTimeValue& deltaTimeValue) noexcept
    : deltaTimeValue{ deltaTimeValue }
{
}

System::DeltaTimeValueData::DeltaTimeValueData(int64_t second, int32_t microsecond) noexcept
    : deltaTimeValue{}
{
    deltaTimeValue.tv_sec = second;
    deltaTimeValue.tv_usec = microsecond;
}

System::DeltaTimeValue System::DeltaTimeValueData::GetDeltaTimeValue() const noexcept
{
    return deltaTimeValue;
}

void System::DeltaTimeValueData::SetValue(int64_t second, int32_t microsecond) noexcept
{
    deltaTimeValue.tv_sec = second;
    deltaTimeValue.tv_usec = microsecond;
}

int64_t System::DeltaTimeValueData::GetSecond() const noexcept
{
    return deltaTimeValue.tv_sec;
}

int32_t System::DeltaTimeValueData::GetMicrosecond() const noexcept
{
    return deltaTimeValue.tv_usec;
}

void System::DeltaTimeValueData::Correction() noexcept
{
    if (deltaTimeValue.tv_usec < 0)
    {
        deltaTimeValue.tv_usec += gMicroseconds;
        --deltaTimeValue.tv_sec;
    }
}

System::DeltaTimeValueData System::operator-(const DeltaTimeValueData& lhs, const DeltaTimeValueData& rhs) noexcept
{
#ifdef SYSTEM_PLATFORM_MACOS

    auto lhsDeltaTime = lhs.GetDeltaTimeValue();
    auto rhsDeltaTime = rhs.GetDeltaTimeValue();

    DeltaTimeValue result{};
    timersub(&lhsDeltaTime, &rhsDeltaTime, &result);

    return DeltaTimeValueData{ result };

#else  // !SYSTEM_PLATFORM_MACOS

    DeltaTimeValueData result{ lhs.GetSecond() - rhs.GetSecond(), lhs.GetMicrosecond() - rhs.GetMicrosecond() };

    result.Correction();

    return result;

#endif  // SYSTEM_PLATFORM_MACOS
}
