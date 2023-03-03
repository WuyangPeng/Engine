///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 16:21)

#ifndef CORE_TOOLS_THREADING_MUTEX_IMPL_H
#define CORE_TOOLS_THREADING_MUTEX_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Threading/ThreadingInternalFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MutexImpl
    {
    public:
        using ClassType = MutexImpl;
        using FactoryType = MutexFactory;

    public:
        MutexImpl() noexcept = default;
        virtual ~MutexImpl() noexcept = default;
        MutexImpl(const MutexImpl& rhs) noexcept = delete;
        MutexImpl& operator=(const MutexImpl& rhs) noexcept = delete;
        MutexImpl(MutexImpl&& rhs) noexcept = delete;
        MutexImpl& operator=(MutexImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Initialize() = 0;
        virtual void Delete() noexcept = 0;
        virtual void Enter() = 0;
        NODISCARD virtual bool TryEnter() = 0;
        virtual void Leave() noexcept = 0;
    };
}

#endif  // CORE_TOOLS_THREADING_MUTEX_IMPL_H
