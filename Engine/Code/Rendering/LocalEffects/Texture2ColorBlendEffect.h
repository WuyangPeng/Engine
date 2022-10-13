///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/14 18:01)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE2_COLOR_BLEND_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE2_COLOR_BLEND_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture2ColorBlendEffect : public VisualEffect
    {
    public:
        using ClassType = Texture2ColorBlendEffect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture2ColorBlendEffect);

    public:
        explicit Texture2ColorBlendEffect(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD PixelShaderSharedPtr GetPixelShaderSharedPtr() const noexcept;

        NODISCARD VisualEffectInstanceSharedPtr CreateInstance(const Texture2DSharedPtr& texture0, const Texture2DSharedPtr& texture1);

        NODISCARD static VisualEffectInstanceSharedPtr CreateUniqueInstance(const Texture2DSharedPtr& texture0,
                                                                            ShaderFlags::SamplerFilter filter0,
                                                                            ShaderFlags::SamplerCoordinate coordinate00,
                                                                            ShaderFlags::SamplerCoordinate coordinate01,
                                                                            const Texture2DSharedPtr& texture1,
                                                                            ShaderFlags::SamplerFilter filter1,
                                                                            ShaderFlags::SamplerCoordinate coordinate10,
                                                                            ShaderFlags::SamplerCoordinate coordinate11);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Texture2ColorBlendEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture2ColorBlendEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_TEXTURE2_COLOR_BLEND_EFFECT_H
