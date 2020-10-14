//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 16:55)

#ifndef CORE_TOOLS_THREADING_MUTEX_IMPL_H
#define CORE_TOOLS_THREADING_MUTEX_IMPL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MutexImpl
    {
    public:
        using ClassType = MutexImpl;

    public:
        MutexImpl() noexcept = default;
        virtual ~MutexImpl() noexcept = default;
        MutexImpl(const MutexImpl&) = delete;
        MutexImpl& operator=(const MutexImpl&) = delete;
        MutexImpl(MutexImpl&&) noexcept = delete;
        MutexImpl& operator=(MutexImpl&&) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Initialize() = 0;
        virtual void Delete() noexcept = 0;
        virtual void Enter() = 0;
        [[nodiscard]] virtual bool TryEnter() = 0;
        virtual void Leave() noexcept = 0;
    };
}

#endif  // CORE_TOOLS_THREADING_MUTEX_IMPL_H
