///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 1:16)

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
