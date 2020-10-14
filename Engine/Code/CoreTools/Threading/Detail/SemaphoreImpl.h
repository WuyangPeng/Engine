//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 16:59)

#ifndef CORE_TOOLS_THREADING_SEMAPHORE_IMPL_H
#define CORE_TOOLS_THREADING_SEMAPHORE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Window/Using/WindowUsing.h"

#include <atomic>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SemaphoreImpl final
    {
    public:
        using ClassType = SemaphoreImpl;
        using SemaphoreHandle = System::WindowHandle;

    public:
        SemaphoreImpl(int initialCount, int maximumCount);
        ~SemaphoreImpl() noexcept;
        SemaphoreImpl(const SemaphoreImpl&) = delete;
        SemaphoreImpl& operator=(const SemaphoreImpl&) = delete;
        SemaphoreImpl(SemaphoreImpl&&) noexcept = delete;
        SemaphoreImpl& operator=(SemaphoreImpl&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Release(int releaseCount);
        void Wait();

        [[nodiscard]] int GetCurrentCount() const noexcept;
        [[nodiscard]] int GetMaximumCount() const noexcept;

    private:
        using IntAtomic = std::atomic<int>;

    private:
        SemaphoreHandle m_Handle;
        IntAtomic m_CurrentCount;
        int m_MaximumCount;
    };
}

#endif  // CORE_TOOLS_THREADING_SEMAPHORE_IMPL_H
