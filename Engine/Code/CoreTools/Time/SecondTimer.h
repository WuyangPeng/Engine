//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 19:22)

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

        [[nodiscard]] uint64_t GetRemain() const noexcept;
        [[nodiscard]] uint64_t GetElapsedTime() const noexcept;
        [[nodiscard]] bool IsElapsed() const noexcept;
        [[nodiscard]] uint64_t GetNowTime() const noexcept;

        void ReTiming(uint64_t second);

    private:
        PackageType impl;
        uint64_t m_Second;
    };
}

#endif  // CORE_TOOLS_TIME_SECOND_TIMER_H
