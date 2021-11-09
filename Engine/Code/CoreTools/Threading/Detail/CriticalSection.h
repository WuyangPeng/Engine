///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/08/31 22:49)

#ifndef CORE_TOOLS_THREADING_CRITICAL_SECTION_H
#define CORE_TOOLS_THREADING_CRITICAL_SECTION_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"
#include "System/Threading/Using/CriticalSectionUsing.h"

namespace CoreTools
{
    // 临界区类
    class CORE_TOOLS_HIDDEN_DECLARE CriticalSection final : public MutexImpl
    {
    public:
        using ClassType = CriticalSection;
        using ParentType = MutexImpl;
        using ThreadingCriticalSection = System::ThreadingCriticalSection;

    public:
        CriticalSection() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() final;
        void Delete() noexcept final;
        void Enter() noexcept final;
        NODISCARD bool TryEnter() noexcept final;
        void Leave() noexcept final;

    private:
        ThreadingCriticalSection criticalSection;
    };
}

#endif  // CORE_TOOLS_THREADING_CRITICAL_SECTION_H