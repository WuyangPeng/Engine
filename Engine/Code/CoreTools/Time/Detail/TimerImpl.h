/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/25 09:57)

#ifndef CORE_TOOLS_TIME_TIMER_IMPL_H
#define CORE_TOOLS_TIME_TIMER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <chrono>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE TimerImpl final
    {
    public:
        using ClassType = TimerImpl;

    public:
        TimerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int64_t GetNanoseconds() const noexcept;
        NODISCARD int64_t GetMicroseconds() const noexcept;
        NODISCARD int64_t GetMilliseconds() const noexcept;
        NODISCARD double GetSeconds() const noexcept;
        void Reset() noexcept;

    private:
        using TimePoint = std::chrono::high_resolution_clock::time_point;

    private:
        TimePoint initialTime;
    };
}

#endif  // CORE_TOOLS_TIME_TIMER_IMPL_H