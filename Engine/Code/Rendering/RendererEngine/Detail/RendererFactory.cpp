/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 16:13)

#include "Rendering/RenderingExport.h"

#include "BaseRendererImpl.h"
#include "RendererFactory.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/RendererEngine/RendererParameter.h"
#include "Rendering/RendererEngine/RenderingEnvironment.h"

Rendering::RendererFactory::RendererSharedPtr Rendering::RendererFactory::Create(const EnvironmentParameter& environmentParameter, const std::string& fileName)
{
    const RendererParameter rendererParameter{ fileName };
    const RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };

    return Create(rendererParameter.GetRendererType(), renderingEnvironment);
}

Rendering::RendererFactory::RendererSharedPtr Rendering::RendererFactory::Create(RendererTypes type, const RenderingEnvironment& renderingEnvironment)
{
    return std::make_shared<BaseRendererImpl>(type, renderingEnvironment);
}
