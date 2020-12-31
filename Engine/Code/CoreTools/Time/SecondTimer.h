//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 19:22)

#ifndef CORE_TOOLS_TIME_SECOND_TIMER_H
#define CORE_TOOLS_TIME_SECOND_TIMER_H

#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(DeltaTimeManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE SecondTimer final
    {
    public:
        using SecondTimerImpl = DeltaTimeManagerImpl;
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(SecondTimer);

    public:
        explicit SecondTimer(uint64_t second);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint64_t GetRemain() const noexcept;
        [[nodiscard]] uint64_t GetElapsedTime() const noexcept;
        [[nodiscard]] bool IsElapsed() const noexcept;
        [[nodiscard]] uint64_t GetNowTime() const noexcept;

        void ReTiming(uint64_t second);

    private:
        IMPL_TYPE_DECLARE(SecondTimer);
        uint64_t m_Second;
    };
}

#endif  // CORE_TOOLS_TIME_SECOND_TIMER_H
