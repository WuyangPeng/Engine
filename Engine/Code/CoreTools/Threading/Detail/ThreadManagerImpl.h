//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 17:03)

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
        ThreadManagerImpl(MAYBE_UNUSED int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        void AddThread(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);

        void AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber = 0, ThreadSize stackSize = 0);

        // ������ֹͣ�̡߳�
        void Resume();
        void Suspend();

        void Wait();

    private:
        using ThreadImplPtr = std::shared_ptr<ThreadImpl>;
        using ThreadContainer = std::vector<ThreadImplPtr>;
        using ThreadHandleContainer = std::vector<ThreadHandle>;

    private:
        ThreadContainer m_Thread;
        ThreadHandleContainer m_ThreadHandle;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_MANAGER_IMPL_H
