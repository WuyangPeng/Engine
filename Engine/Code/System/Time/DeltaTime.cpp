//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/24 12:49)

#include "System/SystemExport.h"

#include "DeltaTime.h"
#include "Data/CurrentDeltaTime.h"
#include "System/Window/WindowSystem.h"

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
    [[maybe_unused]] const auto status = SystemCommand("PAUSE");
}
