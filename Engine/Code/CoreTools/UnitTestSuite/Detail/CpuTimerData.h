///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:36)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_CPU_TIMER_DATA_H
#define CORE_TOOLS_UNIT_TEST_SUITE_CPU_TIMER_DATA_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

#include <memory>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CpuTimerData final
    {
    public:
        using ClassType = CpuTimerData;
        using CpuTimer = boost::timer::cpu_timer;
        using CpuTimerSharedPtr = std::shared_ptr<CpuTimer>;
        using ConstCpuTimerSharedPtr = std::shared_ptr<const CpuTimer>;
        using CpuTimerDataSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static CpuTimerData Create();
        NODISCARD static CpuTimerDataSharedPtr CreateSharedPtr();

    protected:
        explicit CpuTimerData(DisableNotThrow disableNotThrow);

    public:
        ~CpuTimerData() noexcept = default;
        CpuTimerData(const CpuTimerData& rhs) = delete;
        CpuTimerData& operator=(const CpuTimerData& rhs) = delete;
        CpuTimerData(CpuTimerData&& rhs) noexcept;
        CpuTimerData& operator=(CpuTimerData&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstCpuTimerSharedPtr GetCpuTimer() const noexcept;

        void Start() noexcept;
        void Resume() noexcept;
        void Stop() noexcept;

    private:
        CpuTimerSharedPtr cpuTimer;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_CPU_TIMER_DATA_H
