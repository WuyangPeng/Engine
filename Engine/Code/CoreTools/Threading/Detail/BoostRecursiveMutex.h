///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/08/31 22:47)

#ifndef CORE_TOOLS_THREADING_BOOST_RECURSIVE_MUTEX_H
#define CORE_TOOLS_THREADING_BOOST_RECURSIVE_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"
#include "System/Helper/PragmaWarning/RecursiveMutex.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE BoostRecursiveMutex final : public MutexImpl
    {
    public:
        using ClassType = BoostRecursiveMutex;
        using ParentType = MutexImpl;

    public:
        BoostRecursiveMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept final;
        void Delete() noexcept final;
        void Enter() final;
        NODISCARD bool TryEnter() noexcept final;
        void Leave() noexcept final;

    private:
        boost::recursive_mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_BOOST_RECURSIVE_MUTEX_H