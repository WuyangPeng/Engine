//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 12:48)

#include "System/SystemExport.h"

#include "DeltaTimeValueData.h"

System::DeltaTimeValueData::DeltaTimeValueData() noexcept
    : m_DeltaTimeValue{}
{
}

System::DeltaTimeValueData::DeltaTimeValueData(const DeltaTimeValue& deltaTimeValue) noexcept
    : m_DeltaTimeValue{ deltaTimeValue }
{
}

System::DeltaTimeValueData::DeltaTimeValueData(int64_t second, int32_t microsecond) noexcept
    : m_DeltaTimeValue{}
{
    m_DeltaTimeValue.tv_sec = second;
    m_DeltaTimeValue.tv_usec = microsecond;
}

const System::DeltaTimeValue System::DeltaTimeValueData::GetDeltaTimeValue() const noexcept
{
    return m_DeltaTimeValue;
}

void System::DeltaTimeValueData::SetValue(int64_t second, int32_t microsecond) noexcept
{
    m_DeltaTimeValue.tv_sec = second;
    m_DeltaTimeValue.tv_usec = microsecond;
}

int64_t System::DeltaTimeValueData::GetSecond() const noexcept
{
    return m_DeltaTimeValue.tv_sec;
}

int32_t System::DeltaTimeValueData::GetMicrosecond() const noexcept
{
    return m_DeltaTimeValue.tv_usec;
}

void System::DeltaTimeValueData::Correction() noexcept
{
    if (m_DeltaTimeValue.tv_usec < 0)
    {
        m_DeltaTimeValue.tv_usec += g_Microseconds;
        --m_DeltaTimeValue.tv_sec;
    }
}

System::DeltaTimeValueData System::operator-(const DeltaTimeValueData& lhs, const DeltaTimeValueData& rhs) noexcept
{
#ifdef SYSTEM_PLATFORM_MACOS

    auto copyLhs = lhs.GetDeltaTimeValue();
    auto copyRhs = rhs.GetDeltaTimeValue();
    DeltaTimeValue result{};

    timersub(&copyLhs, &copyRhs, &result);

    return DeltaTimeValueData{ result };

#else  // !SYSTEM_PLATFORM_MACOS

    DeltaTimeValueData result{ lhs.GetSecond() - rhs.GetSecond(), lhs.GetMicrosecond() - rhs.GetMicrosecond() };

    result.Correction();

    return result;

#endif  // SYSTEM_PLATFORM_MACOS
}
