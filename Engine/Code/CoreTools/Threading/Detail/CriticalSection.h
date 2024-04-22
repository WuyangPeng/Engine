/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 18:00)

#ifndef CORE_TOOLS_THREADING_CRITICAL_SECTION_H
#define CORE_TOOLS_THREADING_CRITICAL_SECTION_H

#include "CoreTools/CoreToolsDll.h"

#include "MutexImpl.h"
#include "System/Threading/Using/CriticalSectionUsing.h"

/// �ٽ�����
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CriticalSection final : public MutexImpl
    {
    public:
        using ClassType = CriticalSection;
        using ParentType = MutexImpl;

        using ThreadingCriticalSection = System::ThreadingCriticalSection;

    public:
        CriticalSection() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Initialize() override;
        void Delete() noexcept override;
        void Enter() noexcept override;
        NODISCARD bool TryEnter() noexcept override;
        void Leave() noexcept override;

    private:
        ThreadingCriticalSection criticalSection;
    };
}

#endif  // CORE_TOOLS_THREADING_CRITICAL_SECTION_H