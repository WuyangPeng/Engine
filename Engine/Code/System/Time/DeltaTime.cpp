///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.3 (2021/05/17 13:56)

#include "System/SystemExport.h"

#include "DeltaTime.h"
#include "Data/CurrentDeltaTime.h"
#include "System/Windows/WindowsSystem.h"

int64_t System::GetTimeInMicroseconds(const DeltaTimeValueData& deltaTime) noexcept
{
    return g_Microseconds * deltaTime.GetSecond() + deltaTime.GetMicrosecond();
}

int64_t System::GetTimeInMicroseconds() noexcept
{
    const CurrentDeltaTime currentTime{};

    const DeltaTimeValueData deltaTimeValueData{ currentTime.GetDeltaTimeValueData() };

    return GetTimeInMicroseconds(deltaTimeValueData);
}

int64_t System::GetTimeInSeconds(const DeltaTimeValueData& deltaTime) noexcept
{
    return deltaTime.GetSecond();
}

int64_t System::GetTimeInSeconds() noexcept
{
    const auto microseconds = GetTimeInMicroseconds();
    return microseconds / g_Microseconds;
}

void System::SystemPause() noexcept
{
    MAYBE_UNUSED const auto status = SystemCommand("PAUSE");
}
