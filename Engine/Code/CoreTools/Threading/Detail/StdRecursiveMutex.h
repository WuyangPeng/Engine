///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 1:18)

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