///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 10:43)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE3D_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE3D_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Texture3D.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture3DEffect : public VisualEffect
    {
    public:
        using ClassType = Texture3DEffect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture3DEffect);

    public:
        explicit Texture3DEffect(ShaderFlags::SamplerFilter filter,
                                 ShaderFlags::SamplerCoordinate coordinate0 = ShaderFlags::SamplerCoordinate::ClampEdge,
                                 ShaderFlags::SamplerCoordinate coordinate1 = ShaderFlags::SamplerCoordinate::ClampEdge,
                                 ShaderFlags::SamplerCoordinate coordinate2 = ShaderFlags::SamplerCoordinate::ClampEdge);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD PixelShaderSharedPtr GetPixelShaderSharedPtr() const;

        NODISCARD VisualEffectInstanceSharedPtr CreateInstance(const Texture3DSharedPtr& texture);

        NODISCARD static VisualEffectInstanceSharedPtr CreateUniqueInstance(const Texture3DSharedPtr& texture,
                                                                            ShaderFlags::SamplerFilter filter,
                                                                            ShaderFlags::SamplerCoordinate coordinate0,
                                                                            ShaderFlags::SamplerCoordinate coordinate1,
                                                                            ShaderFlags::SamplerCoordinate coordinate2);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Texture3DEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture3DEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_TEXTURE3D_EFFECT_H
