///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:42)

#ifndef RENDERING_LOCAL_EFFECTS_MATERIAL_TEXTURE_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_MATERIAL_TEXTURE_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/SceneGraph/Material.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE MaterialTextureEffect : public VisualEffect
    {
    public:
        using ClassType = MaterialTextureEffect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(MaterialTextureEffect);

    public:
        explicit MaterialTextureEffect(ShaderFlags::SamplerFilter filter,
                                       ShaderFlags::SamplerCoordinate coordinate0 = ShaderFlags::SamplerCoordinate::ClampEdge,
                                       ShaderFlags::SamplerCoordinate coordinate1 = ShaderFlags::SamplerCoordinate::ClampEdge);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(MaterialTextureEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(MaterialTextureEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_MATERIAL_TEXTURE_EFFECT_H
