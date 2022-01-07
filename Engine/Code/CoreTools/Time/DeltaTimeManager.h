///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/16 21:50)

#ifndef CORE_TOOLS_TIME_DELTA_TIME_MANAGER_H
#define CORE_TOOLS_TIME_DELTA_TIME_MANAGER_H

#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(DeltaTimeManager, DeltaTimeManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE DeltaTimeManager final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(DeltaTimeManager);

    public:
        NODISCARD static DeltaTimeManager Create();

    private:
        explicit DeltaTimeManager(MAYBE_UNUSED DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        void ResetCurrentTime();
        NODISCARD uint64_t GetElapsedTimeInMicroseconds() const noexcept;
        NODISCARD uint64_t GetElapsedTimeInSeconds() const noexcept;
        NODISCARD uint64_t GetNowTimeInMicroseconds() const noexcept;
        NODISCARD uint64_t GetNowTimeInSeconds() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TIME_DELTA_TIME_MANAGER_H
