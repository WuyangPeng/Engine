///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 15:17)

#include "Framework/FrameworkExport.h"

#include "WindowCreateParameter.h"
#include "Detail/WindowCreateParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::WindowCreateParameter::WindowCreateParameter(const String& windowsName, WindowStyles style, WindowsHWnd parent, WindowsHMenu menu, const WindowPoint& leftTopCorner)
    : impl{ windowsName, style, parent, menu, leftTopCorner }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowCreateParameter::WindowCreateParameter(const String& windowsName)
    : WindowCreateParameter{ windowsName, WindowStyles::OverlappedWindow | WindowStyles::Visible }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowCreateParameter::WindowCreateParameter(const String& windowsName, WindowStyles style)
    : WindowCreateParameter{ windowsName, style, nullptr, nullptr, WindowPoint{ System::WindowsPointUse::Default } }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowCreateParameter)

System::String Framework::WindowCreateParameter::GetWindowsName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowsName();
}

System::WindowsStyles Framework::WindowCreateParameter::GetStyle() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetStyle();
}

Framework::WindowPoint Framework::WindowCreateParameter::GetLeftTopCorner() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetLeftTopCorner();
}

System::WindowsHWnd Framework::WindowCreateParameter::GetParent() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetParent();
}

System::WindowsHMenu Framework::WindowCreateParameter::GetMenu() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetMenu();
}
