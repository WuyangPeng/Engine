///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/13 11:33)

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
        std::chrono::high_resolution_clock::time_point initialTime;
    };
}

#endif  // CORE_TOOLS_TIME_TIMER_IMPL_H