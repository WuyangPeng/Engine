///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 16:13)

#ifndef CORE_TOOLS_THREADING_BOOST_MUTEX_H
#define CORE_TOOLS_THREADING_BOOST_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"

#include "System/Helper/PragmaWarning/Mutex.h"

// boost锁是不可递归的。重入会死锁，而不是抛出异常。
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BoostMutex final : public MutexImpl
    {
    public:
        using ClassType = BoostMutex;
        using ParentType = MutexImpl;

    public:
        BoostMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept override;
        void Delete() noexcept override;
        void Enter() override;
        NODISCARD bool TryEnter() noexcept override;
        void Leave() noexcept override;

    private:
        boost::mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_BOOST_MUTEX_H