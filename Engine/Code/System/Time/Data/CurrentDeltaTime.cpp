///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.3 (2021/05/17 14:02)

#include "System/SystemExport.h"

#include "CurrentDeltaTime.h"

System::CurrentDeltaTime::CurrentDeltaTime() noexcept
    : currentTime{}
{
#ifdef SYSTEM_PLATFORM_MACOS

    ::gettimeofday(&currentTime, nullptr);

#else  // !SYSTEM_PLATFORM_MACOS

    ::ftime(&currentTime);

#endif  // SYSTEM_PLATFORM_MACOS
}

const System::DeltaTimeValueData System::CurrentDeltaTime::GetDeltaTimeValueData() const noexcept
{
#ifdef SYSTEM_PLATFORM_MACOS

    return DeltaTimeValueData{ currentTime };

#else  // !SYSTEM_PLATFORM_MACOS

    return DeltaTimeValueData{ currentTime.time, g_Millisecond * currentTime.millitm };

#endif  // SYSTEM_PLATFORM_MACOS
}
