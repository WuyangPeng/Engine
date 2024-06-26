/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:08)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfaceDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"

UserInterface::UserInterfaceDelayCopyUnsharedMacroImpl::UserInterfaceDelayCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfaceDelayCopyUnsharedMacroImpl)

int UserInterface::UserInterfaceDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return count;
}

void UserInterface::UserInterfaceDelayCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_9;

    count = aCount;
}