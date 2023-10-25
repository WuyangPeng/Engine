///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:08)

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
        explicit SecondTimer(int64_t second);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int64_t GetRemain() const noexcept;
        NODISCARD int64_t GetElapsedTime() const noexcept;
        NODISCARD bool IsElapsed() const noexcept;
        NODISCARD int64_t GetNowTime() const noexcept;

        void ReTiming(int64_t aSecond);

    private:
        PackageType impl;
        int64_t second;
    };
}

#endif  // CORE_TOOLS_TIME_SECOND_TIMER_H
