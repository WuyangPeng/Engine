/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/25 09:57)

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
        // 构造高分辨率计时器（64位）。
        NODISCARD static Timer Create();

    private:
        explicit Timer(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        // 获取相对于初始时间的当前时间。
        NODISCARD int64_t GetNanoseconds() const noexcept;
        NODISCARD int64_t GetMicroseconds() const noexcept;
        NODISCARD int64_t GetMilliseconds() const noexcept;
        NODISCARD double GetSeconds() const noexcept;

        // 重置使当前时间为初始时间。
        void Reset() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TIME_TIMER_H