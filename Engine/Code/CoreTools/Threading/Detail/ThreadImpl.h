///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/01 16:28)

#ifndef CORE_TOOLS_THREADING_THREAD_IMPL_H
#define CORE_TOOLS_THREADING_THREAD_IMPL_H

#include "CoreTools/CoreToolsDll.h"

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
        ThreadImpl(const ThreadImpl& rhs) = delete;
        ThreadImpl& operator=(const ThreadImpl& rhs) = delete;
        ThreadImpl(ThreadImpl&& rhs) noexcept = delete;
        ThreadImpl& operator=(ThreadImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ThreadingDWord GetThreadId() const noexcept;
        NODISCARD ThreadHandle GetThreadHandle() const noexcept;

        // ������ֹͣ�̡߳�
        void Resume() const;
        void Suspend() const;

        void Wait() const;

        void SetThreadPriority(int priority) const;
        NODISCARD int GetThreadPriority() const;

    private:
        static constexpr auto failResult = static_cast<ThreadingDWord>(-1);

    private:
        ThreadingDWord threadId;
        void* function;
        void* userData;
        int processorNumber;
        ThreadSize stackSize;
        ThreadHandle thread;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_IMPL_H
