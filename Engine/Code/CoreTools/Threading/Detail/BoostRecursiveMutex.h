///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 16:14)

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

        void Initialize() noexcept override;
        void Delete() noexcept override;
        void Enter() override;
        NODISCARD bool TryEnter() noexcept override;
        void Leave() noexcept override;

    private:
        boost::recursive_mutex mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_BOOST_RECURSIVE_MUTEX_H