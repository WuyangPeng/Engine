/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:10)

#ifndef CORE_TOOLS_THREADING_THREAD_MUTEX_H
#define CORE_TOOLS_THREADING_THREAD_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"
#include "System/Threading/Using/MutexUsing.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ThreadMutex final : public MutexImpl
    {
    public:
        using ClassType = ThreadMutex;
        using ParentType = MutexImpl;

        using MutexType = System::MutexType;

    public:
        ThreadMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() override;
        void Delete() noexcept override;
        void Enter() override;
        NODISCARD bool TryEnter() noexcept override;
        void Leave() noexcept override;

    private:
        MutexType mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAD_MUTEX_H
