///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/16 21:51)

#ifndef CORE_TOOLS_TIME_SECOND_TIMER_H
#define CORE_TOOLS_TIME_SECOND_TIMER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(SecondTimer, DeltaTimeManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE SecondTimer final
    {
    public:
        using SecondTimerImpl = DeltaTimeManagerImpl;
        DELAY_COPY_UNSHARED_TYPE_DECLARE(SecondTimer);

    public:
        explicit SecondTimer(uint64_t second);

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint64_t GetRemain() const noexcept;
        NODISCARD uint64_t GetElapsedTime() const noexcept;
        NODISCARD bool IsElapsed() const noexcept;
        NODISCARD uint64_t GetNowTime() const noexcept;

        void ReTiming(uint64_t second);

    private:
        PackageType impl;
        uint64_t m_Second;
    };
}

#endif  // CORE_TOOLS_TIME_SECOND_TIMER_H
