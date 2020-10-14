//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 17:04)

#ifndef CORE_TOOLS_THREADING_THREAN_MUTEX_H
#define CORE_TOOLS_THREADING_THREAN_MUTEX_H

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

        void Initialize() final;
        void Delete() noexcept final;
        void Enter() final;
        [[nodiscard]] bool TryEnter() noexcept final;
        void Leave() noexcept final;

    private:
        MutexType m_Mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_THREAN_MUTEX_H
