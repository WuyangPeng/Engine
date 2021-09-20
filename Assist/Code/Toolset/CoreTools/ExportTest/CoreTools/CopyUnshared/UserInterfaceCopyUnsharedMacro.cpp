///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 15:21)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfaceCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/UserInterfaceCopyUnsharedMacroImpl.h"

UserInterface::UserInterfaceCopyUnsharedMacro::UserInterfaceCopyUnsharedMacro(int count)
    : impl{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfaceCopyUnsharedMacro)

int UserInterface::UserInterfaceCopyUnsharedMacro::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void UserInterface::UserInterfaceCopyUnsharedMacro::SetCount(int count) noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(UserInterface, UserInterfaceCopyUnsharedMacro)