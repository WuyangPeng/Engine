//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 17:00)

#ifndef CORE_TOOLS_THREADING_STD_MUTEX_H
#define CORE_TOOLS_THREADING_STD_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"

#include <mutex>

namespace CoreTools
{
    // 标准库锁是不可递归的。
    class CORE_TOOLS_HIDDEN_DECLARE StdMutex final : public MutexImpl
    {
    public:
        using ClassType = StdMutex;
        using ParentType = MutexImpl;

    public:
        StdMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept final;
        void Delete() noexcept final;
        void Enter() final;
        [[nodiscard]] bool TryEnter() final;
        void Leave() noexcept final;

    private:
        void DoLeave();

    private:
        std::mutex m_Mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_STD_MUTEX_H