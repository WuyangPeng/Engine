///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 09:10)

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
