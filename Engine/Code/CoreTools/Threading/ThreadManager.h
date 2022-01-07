///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 1:22)

#ifndef CORE_TOOLS_THREADING_THREAD_MANAGER_H
#define CORE_TOOLS_THREADING_THREAD_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Threading/Using/ThreadUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

CORE_TOOLS_NON_COPY_EXPORT_IMPL(ThreadManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ThreadManager final
    {
    public:
        NON_COPY_TYPE_DECLARE(ThreadManager);
        using ThreadSize = System::WindowsSize;

    public:
        NODISCARD static ThreadManager Create();

    private:
        explicit ThreadManager(MAYBE_UNUSED DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        void AddThread(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);

        void AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber = 0, ThreadSize stackSize = 0);

        // 启动和停止线程。
        void Resume();
        void Suspend();

        void Wait();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_MANAGER_H
