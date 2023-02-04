///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/30 14:20)

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
