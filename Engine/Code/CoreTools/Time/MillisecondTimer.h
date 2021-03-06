//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 19:19)

#ifndef CORE_TOOLS_TIME_MILLISECOND_TIMER_H
#define CORE_TOOLS_TIME_MILLISECOND_TIMER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(DeltaTimeManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE MillisecondTimer final
    {
    public:
        using MillisecondTimerImpl = DeltaTimeManagerImpl;
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(MillisecondTimer);

    public:
        explicit MillisecondTimer(uint64_t millisecond);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint64_t GetRemain() const noexcept;
        [[nodiscard]] uint64_t GetElapsedTime() const noexcept;
        [[nodiscard]] bool IsElapsed() const noexcept;
        [[nodiscard]] uint64_t GetNowTime() const noexcept;

        void ReTiming(uint64_t millisecond);

    private:
        IMPL_TYPE_DECLARE(MillisecondTimer);
        uint64_t m_Millisecond;
    };
}

#endif  // CORE_TOOLS_TIME_MILLISECOND_TIMER_H
