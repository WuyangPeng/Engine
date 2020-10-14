//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 16:22)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H
#define CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H

#include "ConsoleInstance.h"
#include "System/Console/ConsoleHandle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleInstance<Handle>::ConsoleInstance([[maybe_unused]] DisableNotThrow disableNotThrow)
    : m_Handle{ System::GetStandardHandle(Handle) }
{
    if (!System::IsHandleValid(m_Handle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ȡ��׼�豸�ľ��ʧ�ܡ�"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <CoreTools::StandardHandle Handle>
bool CoreTools::ConsoleInstance<Handle>::IsValid() const noexcept
{
    if (System::IsHandleValid(m_Handle))
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <CoreTools::StandardHandle Handle>
typename CoreTools::ConsoleInstance<Handle>::ConsoleHandle CoreTools::ConsoleInstance<Handle>::GetHandle() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return m_Handle;
}

#endif  // CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H
