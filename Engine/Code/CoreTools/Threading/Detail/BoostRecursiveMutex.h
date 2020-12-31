//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 16:49)

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
        [[nodiscard]] bool TryEnter() noexcept final;
        void Leave() noexcept final;

    private:
        boost::recursive_mutex m_Mutex;
    };
}

#endif  // CORE_TOOLS_THREADING_BOOST_RECURSIVE_MUTEX_H