/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 19:31)

#include "CriticalSectionPacking.h"
#include "System/Threading/CriticalSection.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"

System::CriticalSectionPacking::CriticalSectionPacking(ThreadingCriticalSection& criticalSection) noexcept
    : criticalSection{ criticalSection }
{
    EnterSystemCriticalSection(&criticalSection);

    SYSTEM_SELF_CLASS_IS_VALID_1;
}

System::CriticalSectionPacking::~CriticalSectionPacking() noexcept
{
    SYSTEM_SELF_CLASS_IS_VALID_1;

    LeaveSystemCriticalSection(&criticalSection);
}

CLASS_INVARIANT_STUB_DEFINE(System, CriticalSectionPacking)
