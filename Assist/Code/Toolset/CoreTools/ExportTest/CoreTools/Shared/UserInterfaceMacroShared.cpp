///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:25)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfaceMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/UserInterfaceMacroSharedImpl.h"

UserInterface::UserInterfaceMacroShared::UserInterfaceMacroShared(int count)
    : impl{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfaceMacroShared)

int UserInterface::UserInterfaceMacroShared::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void UserInterface::UserInterfaceMacroShared::SetCount(int count) noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* UserInterface::UserInterfaceMacroShared::GetAddress() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}