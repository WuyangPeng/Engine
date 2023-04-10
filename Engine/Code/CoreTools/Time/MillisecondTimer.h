///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 17:07)

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
        explicit MillisecondTimer(int64_t millisecond);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int64_t GetRemain() const noexcept;
        NODISCARD int64_t GetElapsedTime() const noexcept;
        NODISCARD bool IsElapsed() const noexcept;
        NODISCARD int64_t GetNowTime() const noexcept;

        void ReTiming(int64_t aMillisecond);

    private:
        PackageType impl;
        int64_t millisecond;
    };
}

#endif  // CORE_TOOLS_TIME_MILLISECOND_TIMER_H
