//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 18:04)

#ifndef CORE_TOOLS_THREADING_MUTEX_H
#define CORE_TOOLS_THREADING_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "DllMutex.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Mutex final : public DllMutex
    {
    public:
        using ClassType = Mutex;
        using ParentType = DllMutex;

    public:
        explicit Mutex(MutexCreate mutexCreate = MutexCreate::UseCriticalSection);
        ~Mutex() noexcept;
        Mutex(const Mutex&) = delete;
        Mutex& operator=(const Mutex&) = delete;
        Mutex(Mutex&& rhs) noexcept;
        Mutex& operator=(Mutex&& rhs) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept final;
        void Delete() noexcept final;
    };
}

#endif  // CORE_TOOLS_THREADING_MUTEX_H
