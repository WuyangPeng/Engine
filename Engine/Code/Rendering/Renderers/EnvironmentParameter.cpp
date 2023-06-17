///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:45)

#include "Rendering/RenderingExport.h"

#include "EnvironmentParameter.h"
#include "Detail/EnvironmentParameterFactory.h"
#include "Detail/EnvironmentParameterImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::EnvironmentParameter Rendering::EnvironmentParameter::Create()
{
    return EnvironmentParameter{ DisableNotThrow::Disable };
}

Rendering::EnvironmentParameter Rendering::EnvironmentParameter::Create(WindowsHWnd windowsHWnd)
{
    return EnvironmentParameter{ windowsHWnd };
}

Rendering::EnvironmentParameter::EnvironmentParameter(DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::EnvironmentParameter::EnvironmentParameter(WindowsHWnd windowsHWnd)
    : impl{ CoreTools::ImplCreateUseFactory::Default, windowsHWnd }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, EnvironmentParameter)

System::WindowsHWnd Rendering::EnvironmentParameter::GetWindowsHWnd() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWindowsHWnd();
}
