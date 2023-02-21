///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 18:57)

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