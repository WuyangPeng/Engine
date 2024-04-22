/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:27)

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

        using DeltaTimeValueData = System::DeltaTimeValueData;

    public:
        DeltaTimeManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD void ResetCurrentTime() noexcept;
        NODISCARD int64_t GetElapsedTimeInMicroseconds() const noexcept;
        NODISCARD int64_t GetElapsedTimeInSeconds() const noexcept;
        NODISCARD static int64_t GetNowTimeInMicroseconds() noexcept;
        NODISCARD static int64_t GetNowTimeInSeconds() noexcept;

    private:
        DeltaTimeValueData initial;
    };
}

#endif  // CORE_TOOLS_TIME_DELTA_TIME_MANAGER_IMPL_H
