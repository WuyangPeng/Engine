///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 19:37)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterfacePerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/UserInterfaceClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/UserInterfacePerformanceUnsharedMacroImpl.h"

UserInterface::UserInterfacePerformanceUnsharedMacro::UserInterfacePerformanceUnsharedMacro(int count)
    : impl{ count }
{
    USER_INTERFACE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(UserInterface, UserInterfacePerformanceUnsharedMacro)

int UserInterface::UserInterfacePerformanceUnsharedMacro::GetCount() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

const void* UserInterface::UserInterfacePerformanceUnsharedMacro::GetAddress() const noexcept
{
    USER_INTERFACE_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}