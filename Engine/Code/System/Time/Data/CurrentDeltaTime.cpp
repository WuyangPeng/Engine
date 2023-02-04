///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.1 (2023/02/01 23:38)

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

System::DeltaTimeValueData System::CurrentDeltaTime::GetDeltaTimeValueData() const noexcept
{
#ifdef SYSTEM_PLATFORM_MACOS

    return DeltaTimeValueData{ currentTime };

#else  // !SYSTEM_PLATFORM_MACOS

    return DeltaTimeValueData{ currentTime.time, gMillisecond * currentTime.millitm };

#endif  // SYSTEM_PLATFORM_MACOS
}
