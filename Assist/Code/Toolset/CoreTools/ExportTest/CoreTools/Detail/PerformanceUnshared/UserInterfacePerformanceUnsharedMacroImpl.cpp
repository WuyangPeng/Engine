///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:12)

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
