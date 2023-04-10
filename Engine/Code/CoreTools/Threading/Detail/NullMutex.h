///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:37)

#ifndef CORE_TOOLS_THREADING_NULL_MUTEX_H
#define CORE_TOOLS_THREADING_NULL_MUTEX_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE NullMutex final : public MutexImpl
    {
    public:
        using ClassType = NullMutex;
        using ParentType = MutexImpl;

    public:
        NullMutex() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() noexcept override;
        void Delete() noexcept override;
        void Enter() noexcept override;
        NODISCARD bool TryEnter() noexcept override;
        void Leave() noexcept override;
    };
}

#endif  // CORE_TOOLS_THREADING_NULL_MUTEX_H