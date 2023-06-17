///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 12:42)

#include "Rendering/RenderingExport.h"

#include "EnvironmentParameterFactory.h"
#include "EnvironmentParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/WglRenderer/Detail/WglEnvironmentParameter.h"

Rendering::EnvironmentParameterFactory::EnvironmentParameterFactory() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, EnvironmentParameterFactory)

Rendering::EnvironmentParameterFactory::EnvironmentParameterSharedPtr Rendering::EnvironmentParameterFactory::Create()
{
    return std::make_shared<EnvironmentParameterImpl>();
}

Rendering::EnvironmentParameterFactory::EnvironmentParameterSharedPtr Rendering::EnvironmentParameterFactory::Create(WindowsHWnd windowsHWnd)
{
    return std::make_shared<WglEnvironmentParameter>(windowsHWnd);
}
