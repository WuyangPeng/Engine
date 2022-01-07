///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/16 21:50)

#ifndef CORE_TOOLS_TIME_MILLISECOND_TIMER_H
#define CORE_TOOLS_TIME_MILLISECOND_TIMER_H

#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(MillisecondTimer, DeltaTimeManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE MillisecondTimer final
    {
    public:
        using MillisecondTimerImpl = DeltaTimeManagerImpl;
        DELAY_COPY_UNSHARED_TYPE_DECLARE(MillisecondTimer);

    public:
        explicit MillisecondTimer(uint64_t millisecond);

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint64_t GetRemain() const noexcept;
        NODISCARD uint64_t GetElapsedTime() const noexcept;
        NODISCARD bool IsElapsed() const noexcept;
        NODISCARD uint64_t GetNowTime() const noexcept;

        void ReTiming(uint64_t millisecond);

    private:
        PackageType impl;
        uint64_t m_Millisecond;
    };
}

#endif  // CORE_TOOLS_TIME_MILLISECOND_TIMER_H
