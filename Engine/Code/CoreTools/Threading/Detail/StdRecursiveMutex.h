/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 18:01)

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

        void Initialize() noexcept override;
        void Delete() noexcept override;
        void Enter() override;
        NODISCARD bool TryEnter() noexcept override;
        void Leave() noexcept override;

    private:
        std::recursive_mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_STD_RECURSIVE_MUTEX_H