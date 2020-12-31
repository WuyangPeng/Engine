//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 18:50)

#include "CoreTools/CoreToolsExport.h"

#include "CriticalSection.h"
#include "System/Threading/CriticalSection.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::CriticalSection::CriticalSection() noexcept
    : ParentType{}, m_CriticalSection{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CriticalSection)

void CoreTools::CriticalSection::Initialize()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (!System::InitializeSystemCriticalSection(&m_CriticalSection))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ʼ���ٽ���ʧ�ܡ�"s));
    }
}

void CoreTools::CriticalSection::Delete() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::DeleteSystemCriticalSection(&m_CriticalSection);
}

void CoreTools::CriticalSection::Enter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::EnterSystemCriticalSection(&m_CriticalSection);
}

void CoreTools::CriticalSection::Leave() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::LeaveSystemCriticalSection(&m_CriticalSection);
}

bool CoreTools::CriticalSection::TryEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return System::TryEnterSystemCriticalSection(&m_CriticalSection);
}
