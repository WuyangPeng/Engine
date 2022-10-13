///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/05 10:59)

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
