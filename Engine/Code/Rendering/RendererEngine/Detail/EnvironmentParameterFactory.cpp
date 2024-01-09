/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 16:11)

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
