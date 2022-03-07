///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/13 11:02)

#ifndef CORE_TOOLS_TIME_TIMER_H
#define CORE_TOOLS_TIME_TIMER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_COPY_UNSHARED_EXPORT_IMPL(Timer, TimerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Timer final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Timer);

    public:
        NODISCARD static Timer Create();

    private:
        explicit Timer(MAYBE_UNUSED DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD int64_t GetNanoseconds() const noexcept;
        NODISCARD int64_t GetMicroseconds() const noexcept;
        NODISCARD int64_t GetMilliseconds() const noexcept;
        NODISCARD double GetSeconds() const noexcept;
        void Reset() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TIME_TIMER_H