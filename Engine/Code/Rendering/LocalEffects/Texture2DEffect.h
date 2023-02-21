///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/14 18:31)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE2D_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE2D_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture2DEffect : public VisualEffect
    {
    public:
        using ClassType = Texture2DEffect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture2DEffect);

    public:
        explicit Texture2DEffect(ShaderFlags::SamplerFilter filter,
                                 ShaderFlags::SamplerCoordinate coordinate0 = ShaderFlags::SamplerCoordinate::ClampEdge,
                                 ShaderFlags::SamplerCoordinate coordinate1 = ShaderFlags::SamplerCoordinate::ClampEdge);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD PixelShaderSharedPtr GetPixelShaderSharedPtr() const noexcept;

        NODISCARD VisualEffectInstanceSharedPtr CreateInstance(const Texture2DSharedPtr& texture);

        NODISCARD static VisualEffectInstanceSharedPtr CreateUniqueInstance(const Texture2DSharedPtr& texture,
                                                                            ShaderFlags::SamplerFilter filter,
                                                                            ShaderFlags::SamplerCoordinate coordinate0,
                                                                            ShaderFlags::SamplerCoordinate coordinate1);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Texture2DEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture2DEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_TEXTURE2D_EFFECT_H
