//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 17:02)

#ifndef CORE_TOOLS_THREADING_THREAD_IMPL_H
#define CORE_TOOLS_THREADING_THREAD_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Threading/Using/CriticalSectionUsing.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ThreadImpl final
    {
    public:
        using ClassType = ThreadImpl;
        using ThreadSize = System::WindowsSize;
        using ThreadHandle = System::ThreadHandle;
        using ThreadingDWord = System::WindowsDWord;

    public:
        ThreadImpl(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);
        ~ThreadImpl() noexcept;
        ThreadImpl(const ThreadImpl&) = delete;
        ThreadImpl& operator=(const ThreadImpl&) = delete;
        ThreadImpl(ThreadImpl&&) noexcept = delete;
        ThreadImpl& operator=(ThreadImpl&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ThreadingDWord GetThreadID() const noexcept;
        [[nodiscard]] ThreadHandle GetThreadHandle() noexcept;

        // ������ֹͣ�̡߳�
        void Resume();
        void Suspend();

        void Wait();

        void SetThreadPriority(int priority);
        [[nodiscard]] int GetThreadPriority() const;

    private:
        static constexpr auto sm_FailResult = static_cast<ThreadingDWord>(-1);

    private:
        ThreadingDWord m_ThreadID;
        void* m_Function;
        void* m_UserData;
        int m_ProcessorNumber;
        ThreadSize m_StackSize;
        ThreadHandle m_Thread;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_IMPL_H
