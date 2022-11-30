///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 23:08)

#include "System/SystemExport.h"

#include "DeltaTime.h"
#include "Data/CurrentDeltaTime.h"
#include "System/Windows/WindowsSystem.h"

int64_t System::GetTimeInMicroseconds(const DeltaTimeValueData& deltaTime) noexcept
{
    return gMicroseconds * deltaTime.GetSecond() + deltaTime.GetMicrosecond();
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
    return microseconds / gMicroseconds;
}

void System::SystemPause() noexcept
{
    SystemCommand("PAUSE");
}
