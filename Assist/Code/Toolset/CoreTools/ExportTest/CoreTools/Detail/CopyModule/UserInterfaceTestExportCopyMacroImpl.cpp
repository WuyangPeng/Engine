///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 22:20)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfaceTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"

UserInterface::UserInterfaceTestExportCopyMacroImpl::UserInterfaceTestExportCopyMacroImpl(int count) noexcept
    : m_Count{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfaceTestExportCopyMacroImpl)

int UserInterface::UserInterfaceTestExportCopyMacroImpl::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void UserInterface::UserInterfaceTestExportCopyMacroImpl::SetCount(int count) noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_9;

    m_Count = count;
}