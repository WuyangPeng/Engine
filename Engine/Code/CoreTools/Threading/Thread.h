//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 18:05)

#ifndef CORE_TOOLS_THREADING_THREAD_H
#define CORE_TOOLS_THREADING_THREAD_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Threading/Using/ThreadUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

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

        // ������ֹͣ�̡߳�
        void Resume();
        void Suspend();

        void Wait();

        void SetThreadPriority(int priority);
        [[nodiscard]] int GetThreadPriority() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_H