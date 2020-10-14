//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 16:48)

#ifndef CORE_TOOLS_THREADING_BOOST_MUTEX_H
#define CORE_TOOLS_THREADING_BOOST_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"

#include "System/Helper/PragmaWarning/Mutex.h"

namespace CoreTools
{
    // boost锁是不可递归的。重入会死锁，而不是抛出异常。
    class CORE_TOOLS_HIDDEN_DECLARE BoostMutex final : public MutexImpl
    {
    public:
        using ClassType = BoostMutex;
        using ParentType = MutexImpl;

    public:
        BoostMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept final;
        void Delete() noexcept final;
        void Enter() final;
        [[nodiscard]] bool TryEnter() noexcept final;
        void Leave() noexcept final;

    private:
        boost::mutex m_Mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_BOOST_MUTEX_H