///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:37)

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
        void DoLeave();

    private:
        std::recursive_mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_STD_RECURSIVE_MUTEX_H