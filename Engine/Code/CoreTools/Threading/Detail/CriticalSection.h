///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 1:14)

#ifndef CORE_TOOLS_THREADING_CRITICAL_SECTION_H
#define CORE_TOOLS_THREADING_CRITICAL_SECTION_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"
#include "System/Threading/Using/CriticalSectionUsing.h"

namespace CoreTools
{
    // �ٽ�����
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