///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:22)

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