///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:06)

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