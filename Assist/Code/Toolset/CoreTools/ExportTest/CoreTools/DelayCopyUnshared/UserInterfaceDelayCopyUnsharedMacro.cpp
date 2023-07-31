///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:40)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfaceDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/UserInterfaceDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(UserInterface, UserInterfaceDelayCopyUnsharedMacro)

UserInterface::UserInterfaceDelayCopyUnsharedMacro::UserInterfaceDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfaceDelayCopyUnsharedMacro)

int UserInterface::UserInterfaceDelayCopyUnsharedMacro::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void UserInterface::UserInterfaceDelayCopyUnsharedMacro::SetCount(int count)
{
    USER_INTERFACE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* UserInterface::UserInterfaceDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}