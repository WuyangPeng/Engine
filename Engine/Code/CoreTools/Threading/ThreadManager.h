//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 18:06)

#ifndef CORE_TOOLS_THREADING_THREAD_MANAGER_H
#define CORE_TOOLS_THREADING_THREAD_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Threading/Using/ThreadUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(ThreadManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE ThreadManager final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(ThreadManager);
        using ThreadSize = System::WindowSize;

    public:
        ThreadManager();

        CLASS_INVARIANT_DECLARE;

        void AddThread(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);

        void AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber = 0, ThreadSize stackSize = 0);

        // ������ֹͣ�̡߳�
        void Resume();
        void Suspend();

        void Wait();

    private:
        IMPL_TYPE_DECLARE(ThreadManager);
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_MANAGER_H
