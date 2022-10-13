///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/05 10:59)

#include "Rendering/RenderingExport.h"

#include "NullEnvironment.h"
#include "RenderingEnvironmentFactory.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/OpenGLEnvironment.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/RendererParameter.h"
#include "Rendering/WglRenderer/Detail/WglEnvironment.h"

Rendering::RenderingEnvironmentFactory::RenderingEnvironmentFactory() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingEnvironmentFactory)

Rendering::RenderingEnvironmentFactory::RenderingEnvironmentSharedPtr Rendering::RenderingEnvironmentFactory::Create(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter)
{
    switch (rendererParameter.GetRendererType())
    {
        case RendererTypes::OpenGL:

#ifdef SYSTEM_PLATFORM_WIN32

            return std::make_shared<WglEnvironment>(environmentParameter, rendererParameter);

#else  // !SYSTEM_PLATFORM_WIN32

            return std::make_shared<OpenGLEnvironment>(rendererParameter);

#endif  // SYSTEM_PLATFORM_WIN32

        default:
            return std::make_shared<NullEnvironment>(rendererParameter);
    }
}
