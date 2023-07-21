///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:25)

#ifndef RENDERING_SHADERS_SHADER_FACTORY_H
#define RENDERING_SHADERS_SHADER_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderFactory
    {
    public:
        using ClassType = ShaderFactory;
        using ShaderSharedPtr = std::shared_ptr<ShaderImpl>;

    public:
        NODISCARD static ShaderSharedPtr Create(RendererTypes rendererTypes, const Reflection& reflector, ReferenceType referenceType);
    };
}

#endif  // RENDERING_SHADERS_SHADER_DATA_IMPL_H
