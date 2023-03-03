///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/01 17:23)

#ifndef CORE_TOOLS_THREADING_THREAD_MANAGER_IMPL_H
#define CORE_TOOLS_THREADING_THREAD_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "ThreadImpl.h"

#include <memory>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ThreadManagerImpl
    {
    public:
        using ClassType = ThreadManagerImpl;
        using ThreadSize = System::WindowsSize;
        using ThreadHandle = System::ThreadHandle;

    public:
        ThreadManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void AddThread(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);

        void AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber = 0, ThreadSize stackSize = 0);

        // ������ֹͣ�̡߳�
        void Resume();
        void Suspend();

        void Wait();

    private:
        using ThreadImplSharedPtr = std::shared_ptr<ThreadImpl>;
        using ThreadContainer = std::vector<ThreadImplSharedPtr>;
        using ThreadHandleContainer = std::vector<ThreadHandle>;

    private:
        ThreadContainer thread;
        ThreadHandleContainer threadHandle;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_MANAGER_IMPL_H
