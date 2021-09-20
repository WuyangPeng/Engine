//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 19:19)

#ifndef CORE_TOOLS_TIME_DELTA_TIME_MANAGER_H
#define CORE_TOOLS_TIME_DELTA_TIME_MANAGER_H

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(DeltaTimeManager,DeltaTimeManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE DeltaTimeManager final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(DeltaTimeManager);

    public:
        DeltaTimeManager();

        CLASS_INVARIANT_DECLARE;

        void ResetCurrentTime();
        [[nodiscard]] uint64_t GetElapsedTimeInMicroseconds() const noexcept;
        [[nodiscard]] uint64_t GetElapsedTimeInSeconds() const noexcept;
        [[nodiscard]] uint64_t GetNowTimeInMicroseconds() const noexcept;
        [[nodiscard]] uint64_t GetNowTimeInSeconds() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TIME_DELTA_TIME_MANAGER_H
