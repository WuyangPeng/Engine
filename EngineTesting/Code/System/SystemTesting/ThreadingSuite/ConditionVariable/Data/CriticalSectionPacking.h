/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 16:30)

#ifndef SYSTEM_THREADING_SUITE_CRITICAL_SECTION_PACKING_H
#define SYSTEM_THREADING_SUITE_CRITICAL_SECTION_PACKING_H

#include "System/Threading/Using/CriticalSectionUsing.h"
#include "CoreTools/Helper/UserMacro.h"

namespace System
{
    class CriticalSectionPacking
    {
    public:
        using ClassType = CriticalSectionPacking;

    public:
        explicit CriticalSectionPacking(ThreadingCriticalSection& criticalSection) noexcept;
        ~CriticalSectionPacking() noexcept;
        CriticalSectionPacking(const CriticalSectionPacking& rhs) = delete;
        CriticalSectionPacking& operator=(const CriticalSectionPacking& rhs) = delete;
        CriticalSectionPacking(CriticalSectionPacking&& rhs) noexcept = delete;
        CriticalSectionPacking& operator=(CriticalSectionPacking&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        ThreadingCriticalSection& criticalSection;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CRITICAL_SECTION_PACKING_H