///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 1:18)

#ifndef CORE_TOOLS_THREADING_STD_RECURSIVE_MUTEX_H
#define CORE_TOOLS_THREADING_STD_RECURSIVE_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"

#include <mutex>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE StdRecursiveMutex final : public MutexImpl
    {
    public:
        using ClassType = StdRecursiveMutex;
        using ParentType = MutexImpl;

    public:
        StdRecursiveMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept final;
        void Delete() noexcept final;
        void Enter() final;
        NODISCARD bool TryEnter() noexcept final;
        void Leave() noexcept final;

    private:
        void DoLeave();

    private:
        std::recursive_mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_STD_RECURSIVE_MUTEX_H