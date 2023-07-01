///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/25 15:54)

#include "Rendering/RenderingExport.h"

#include "WglEnvironmentParameter.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::WglEnvironmentParameter::WglEnvironmentParameter(WindowsHWnd windowsHWnd) noexcept
    : ParentType{}, windowsHWnd{ windowsHWnd }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, WglEnvironmentParameter)

Rendering::WglEnvironmentParameter::EnvironmentParameterSharedPtr Rendering::WglEnvironmentParameter::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

System::WindowsHWnd Rendering::WglEnvironmentParameter::GetWindowsHWnd() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return windowsHWnd;
}
