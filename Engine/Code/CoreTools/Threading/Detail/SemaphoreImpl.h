///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:25)

#ifndef CORE_TOOLS_THREADING_SEMAPHORE_IMPL_H
#define CORE_TOOLS_THREADING_SEMAPHORE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Windows/Using/WindowsUsing.h"

#include <atomic>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SemaphoreImpl final
    {
    public:
        using ClassType = SemaphoreImpl;
        using SemaphoreHandle = System::WindowsHandle;

    public:
        SemaphoreImpl(int initialCount, int maximumCount);
        ~SemaphoreImpl() noexcept;
        SemaphoreImpl(const SemaphoreImpl& rhs) = delete;
        SemaphoreImpl& operator=(const SemaphoreImpl& rhs) = delete;
        SemaphoreImpl(SemaphoreImpl&& rhs) noexcept = delete;
        SemaphoreImpl& operator=(SemaphoreImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Release(int releaseCount);
        void Wait();

        NODISCARD int GetCurrentCount() const noexcept;
        NODISCARD int GetMaximumCount() const noexcept;

    private:
        using IntAtomic = std::atomic<int>;

    private:
        SemaphoreHandle handle;
        IntAtomic currentCount;
        int maximumCount;
    };
}

#endif  // CORE_TOOLS_THREADING_SEMAPHORE_IMPL_H
