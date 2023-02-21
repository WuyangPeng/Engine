///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:00)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfaceTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"

UserInterface::UserInterfaceTestExportCopyMacroImpl::UserInterfaceTestExportCopyMacroImpl(int count) noexcept
    : count{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfaceTestExportCopyMacroImpl)

int UserInterface::UserInterfaceTestExportCopyMacroImpl::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return count;
}

void UserInterface::UserInterfaceTestExportCopyMacroImpl::SetCount(int aCount) noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_9;

    count = aCount;
}