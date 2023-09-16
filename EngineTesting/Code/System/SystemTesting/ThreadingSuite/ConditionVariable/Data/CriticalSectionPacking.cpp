///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:55)

#include "CriticalSectionPacking.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"

System::CriticalSectionPacking::CriticalSectionPacking(ThreadingCriticalSection& criticalSection) noexcept
    : criticalSection{ criticalSection }
{
    EnterCriticalSection(&criticalSection);

    SYSTEM_SELF_CLASS_IS_VALID_1;
}

System::CriticalSectionPacking::~CriticalSectionPacking() noexcept
{
    SYSTEM_SELF_CLASS_IS_VALID_1;

    LeaveCriticalSection(&criticalSection);
}

CLASS_INVARIANT_STUB_DEFINE(System, CriticalSectionPacking)
