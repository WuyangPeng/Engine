/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/02 16:11)

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
