///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/16 21:40)

#ifndef CORE_TOOLS_TIME_DELTA_TIME_MANAGER_IMPL_H
#define CORE_TOOLS_TIME_DELTA_TIME_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Time/DeltaTime.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE DeltaTimeManagerImpl final
    {
    public:
        using ClassType = DeltaTimeManagerImpl;

    public:
        DeltaTimeManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD void ResetCurrentTime() noexcept;
        NODISCARD uint64_t GetElapsedTimeInMicroseconds() const noexcept;
        NODISCARD uint64_t GetElapsedTimeInSeconds() const noexcept;
        NODISCARD uint64_t GetNowTimeInMicroseconds() const noexcept;
        NODISCARD uint64_t GetNowTimeInSeconds() const noexcept;

    private:
        System::DeltaTimeValueData initial;
    };
}

#endif  // CORE_TOOLS_TIME_DELTA_TIME_MANAGER_IMPL_H
