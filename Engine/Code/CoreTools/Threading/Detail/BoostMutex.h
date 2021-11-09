///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/08/31 17:00)

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
        NODISCARD bool TryEnter() noexcept final;
        void Leave() noexcept final;

    private:
        boost::mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_BOOST_MUTEX_H