///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/04 15:53)

#include "Framework/FrameworkExport.h"

#include "WindowCreateParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowCreateParameterImpl::WindowCreateParameterImpl(String windowsName, WindowStyles style, WindowsHWnd parent, WindowsHMenu menu, const WindowPoint& leftTopCorner) noexcept
    : windowsName{ std::move(windowsName) }, style{ style }, leftTopCorner{ leftTopCorner }, parent{ parent }, menu{ menu }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowCreateParameterImpl)

System::String Framework::WindowCreateParameterImpl::GetWindowsName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowsName;
}

Framework::WindowCreateParameterImpl::WindowStyles Framework::WindowCreateParameterImpl::GetStyle() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return style;
}

Framework::WindowPoint Framework::WindowCreateParameterImpl::GetLeftTopCorner() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return leftTopCorner;
}

Framework::WindowCreateParameterImpl::WindowsHWnd Framework::WindowCreateParameterImpl::GetParent() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return parent;
}

Framework::WindowCreateParameterImpl::WindowsHMenu Framework::WindowCreateParameterImpl::GetMenu() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return menu;
}
