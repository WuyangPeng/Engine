//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 18:05)

#ifndef CORE_TOOLS_THREADING_THREAD_H
#define CORE_TOOLS_THREADING_THREAD_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Threading/Using/ThreadUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(ThreadImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Thread final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(Thread);
        using ThreadSize = System::WindowSize;

    public:
        Thread(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);

        CLASS_INVARIANT_DECLARE;

        // 启动和停止线程。
        void Resume();
        void Suspend();

        void Wait();

        void SetThreadPriority(int priority);
        [[nodiscard]] int GetThreadPriority() const;

    private:
        IMPL_TYPE_DECLARE(Thread);
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_H