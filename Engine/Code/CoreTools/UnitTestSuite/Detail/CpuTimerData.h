//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 11:20)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_CPU_TIMER_DATA_H
#define CORE_TOOLS_UNIT_TEST_SUITE_CPU_TIMER_DATA_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include <memory>

namespace boost
{
    namespace timer
    {
        class cpu_timer;
    }
}

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CpuTimerData final : private boost::noncopyable
    {
    public:
        using ClassType = CpuTimerData;
        using CpuTimer = boost::timer::cpu_timer;
        using CpuTimerSharedPtr = std::shared_ptr<CpuTimer>;

    public:
        CpuTimerData();

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const CpuTimerSharedPtr GetCpuTimer() const noexcept;

        void Start() noexcept;
        void Resume() noexcept;
        void Stop() noexcept;

    private:
        CpuTimerSharedPtr m_CpuTimer;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_CPU_TIMER_DATA_H
