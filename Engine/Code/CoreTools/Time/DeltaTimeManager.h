///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:08)

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
        explicit DeltaTimeManager(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        void ResetCurrentTime();
        NODISCARD int64_t GetElapsedTimeInMicroseconds() const noexcept;
        NODISCARD int64_t GetElapsedTimeInSeconds() const noexcept;
        NODISCARD int64_t GetNowTimeInMicroseconds() const noexcept;
        NODISCARD int64_t GetNowTimeInSeconds() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TIME_DELTA_TIME_MANAGER_H
