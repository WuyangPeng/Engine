///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/16 20:34)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfacePerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"

UserInterface::UserInterfacePerformanceUnsharedMacroImpl::UserInterfacePerformanceUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfacePerformanceUnsharedMacroImpl)

int UserInterface::UserInterfacePerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return count;
}

 