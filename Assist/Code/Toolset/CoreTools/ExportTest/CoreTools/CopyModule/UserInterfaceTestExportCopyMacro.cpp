///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 18:52)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfaceTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/UserInterfaceTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(UserInterface, UserInterfaceTestExportCopyMacro)

UserInterface::UserInterfaceTestExportCopyMacro::UserInterfaceTestExportCopyMacro(int count)
    : impl{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfaceTestExportCopyMacro)

int UserInterface::UserInterfaceTestExportCopyMacro::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void UserInterface::UserInterfaceTestExportCopyMacro::SetCount(int count) noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
