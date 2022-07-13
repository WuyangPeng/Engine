///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/01 14:13)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfaceDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"

UserInterface::UserInterfaceDelayCopyUnsharedMacroImpl::UserInterfaceDelayCopyUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfaceDelayCopyUnsharedMacroImpl)

int UserInterface::UserInterfaceDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void UserInterface::UserInterfaceDelayCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_9;

    mCount = count;
}