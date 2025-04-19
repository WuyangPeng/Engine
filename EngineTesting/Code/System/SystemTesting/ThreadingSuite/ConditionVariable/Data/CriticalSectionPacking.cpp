/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 19:31)

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
