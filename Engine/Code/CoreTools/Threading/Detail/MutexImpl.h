///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/01 12:48)

#ifndef CORE_TOOLS_THREADING_MUTEX_IMPL_H
#define CORE_TOOLS_THREADING_MUTEX_IMPL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    class MutexFactory;
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
