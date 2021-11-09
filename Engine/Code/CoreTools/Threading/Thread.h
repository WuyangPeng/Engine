///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/01 13:21)

#ifndef CORE_TOOLS_THREADING_THREAD_H
#define CORE_TOOLS_THREADING_THREAD_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Threading/Using/ThreadUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(ThreadImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Thread final
    {
    public:
        NON_COPY_TYPE_DECLARE(Thread);
        using ThreadSize = System::WindowsSize;

    public:
        Thread(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);
        ~Thread() noexcept = default;
        Thread(const Thread& rhs) noexcept = delete;
        Thread& operator=(const Thread& rhs) noexcept = delete;
        Thread(Thread&& rhs) noexcept = delete;
        Thread& operator=(Thread&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        // 启动和停止线程。
        void Resume();
        void Suspend();

        void Wait();

        void SetThreadPriority(int priority);
        NODISCARD int GetThreadPriority() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_H