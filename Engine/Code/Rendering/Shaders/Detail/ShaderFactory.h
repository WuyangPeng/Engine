///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/19 18:18)

#ifndef RENDERING_SHADERS_SHADER_FACTORY_H
#define RENDERING_SHADERS_SHADER_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderFactory
    {
    public:
        using ClassType = ShaderFactory;
        using ShaderSharedPtr = std::shared_ptr<ShaderImpl>;

    public:
        NODISCARD static ShaderSharedPtr Create(RendererTypes type);
    };
}

#endif  // RENDERING_SHADERS_SHADER_DATA_IMPL_H
