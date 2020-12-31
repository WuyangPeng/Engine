//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 16:58)

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

        void Initialize() noexcept final;
        void Delete() noexcept final;
        void Enter() noexcept final;
        [[nodiscard]] bool TryEnter() noexcept final;
        void Leave() noexcept final;
    };
}

#endif  // CORE_TOOLS_THREADING_NULL_MUTEX_H