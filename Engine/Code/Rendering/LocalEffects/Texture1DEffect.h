///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/14 16:35)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE1D_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE1D_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Texture1D.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

namespace Rendering
{
    class Texture1DEffect : public VisualEffect
    {
    public:
        using ClassType = Texture1DEffect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture1DEffect);

    public:
        explicit Texture1DEffect(ShaderFlags::SamplerFilter filter,
                                 ShaderFlags::SamplerCoordinate coordinate = ShaderFlags::SamplerCoordinate::ClampEdge);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD PixelShaderSharedPtr GetPixelShaderSharedPtr() const;

        NODISCARD VisualEffectInstanceSharedPtr CreateInstance(const Texture1DSharedPtr& texture);

        NODISCARD static VisualEffectInstanceSharedPtr CreateUniqueInstance(const Texture1DSharedPtr& texture, ShaderFlags::SamplerFilter filter, ShaderFlags::SamplerCoordinate coordinate);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Texture1DEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture1DEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_TEXTURE1D_EFFECT_H
