///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:38)

#ifndef CORE_TOOLS_THREADING_SEMAPHORE_H
#define CORE_TOOLS_THREADING_SEMAPHORE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(SemaphoreImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Semaphore final
    {
    public:
        NON_COPY_TYPE_DECLARE(Semaphore);

    public:
        Semaphore(int initialCount, int maximumCount);
        ~Semaphore() noexcept = default;
        Semaphore(const Semaphore& rhs) noexcept = delete;
        Semaphore& operator=(const Semaphore& rhs) noexcept = delete;
        Semaphore(Semaphore&& rhs) noexcept = delete;
        Semaphore& operator=(Semaphore&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Release(int releaseCount);
        void Wait();

        NODISCARD int GetCurrentCount() const noexcept;
        NODISCARD int GetMaximumCount() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_THREADING_SEMAPHORE_H
