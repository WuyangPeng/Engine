///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:02)

#include "Rendering/RenderingExport.h"

#include "BaseRendererImpl.h"
#include "RendererFactory.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/RendererEngine/RendererBasis.h"
#include "Rendering/RendererEngine/RendererParameter.h"
#include "Rendering/RendererEngine/RenderingEnvironment.h"

Rendering::RendererFactory::RendererSharedPtr Rendering::RendererFactory::Create(const EnvironmentParameter& environmentParameter, const std::string& fileName)
{
    const RendererParameter rendererParameter{ fileName };
    const RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };
    auto result = Create(rendererParameter.GetRendererType(), renderingEnvironment);

    return result;
}

Rendering::RendererFactory::RendererSharedPtr Rendering::RendererFactory::Create(RendererTypes type, const RenderingEnvironment& renderingEnvironment)
{
    return std::make_shared<BaseRendererImpl>(type, renderingEnvironment);
}
