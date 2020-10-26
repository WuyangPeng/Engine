//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 18:43)

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

        [[nodiscard]] void ResetCurrentTime() noexcept;
        [[nodiscard]] uint64_t GetElapsedTimeInMicroseconds() const noexcept;
        [[nodiscard]] uint64_t GetElapsedTimeInSeconds() const noexcept;
        [[nodiscard]] uint64_t GetNowTimeInMicroseconds() const noexcept;
        [[nodiscard]] uint64_t GetNowTimeInSeconds() const noexcept;

    private:
        System::DeltaTimeValueData m_Initial;
    };
}

#endif  // CORE_TOOLS_TIME_DELTA_TIME_MANAGER_IMPL_H
