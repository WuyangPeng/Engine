///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 17:08)

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
        explicit Timer(DisableNotThrow disableNotThrow);

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