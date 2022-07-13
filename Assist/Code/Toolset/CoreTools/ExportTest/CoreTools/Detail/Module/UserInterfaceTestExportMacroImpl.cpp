///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/01 14:09)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfaceTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"

UserInterface::UserInterfaceTestExportMacroImpl::UserInterfaceTestExportMacroImpl(int count) noexcept
    : mCount{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfaceTestExportMacroImpl)

int UserInterface::UserInterfaceTestExportMacroImpl::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void UserInterface::UserInterfaceTestExportMacroImpl::SetCount(int count) noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_9;

    mCount = count;
}