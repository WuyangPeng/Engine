///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:07)

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
        NODISCARD int64_t GetNowTimeInMicroseconds() const noexcept;
        NODISCARD int64_t GetNowTimeInSeconds() const noexcept;

    private:
        DeltaTimeValueData initial;
    };
}

#endif  // CORE_TOOLS_TIME_DELTA_TIME_MANAGER_IMPL_H
