/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 18:05)

#include "CoreTools/CoreToolsExport.h"

#include "CriticalSection.h"
#include "System/Threading/CriticalSection.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::CriticalSection::CriticalSection() noexcept
    : ParentType{}, criticalSection{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CriticalSection)

void CoreTools::CriticalSection::Initialize()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (!System::InitializeSystemCriticalSection(&criticalSection))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ʼ���ٽ���ʧ�ܡ�"s))
    }
}

void CoreTools::CriticalSection::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::DeleteSystemCriticalSection(&criticalSection);
}

void CoreTools::CriticalSection::Enter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::EnterSystemCriticalSection(&criticalSection);
}

void CoreTools::CriticalSection::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::LeaveSystemCriticalSection(&criticalSection);
}

bool CoreTools::CriticalSection::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return System::TryEnterSystemCriticalSection(&criticalSection);
}
