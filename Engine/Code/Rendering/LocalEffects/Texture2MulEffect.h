///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:43)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE2_MULEFFECT_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE2_MULEFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture2MulEffect : public VisualEffect
    {
    public:
        using ClassType = Texture2MulEffect;
        using ParentType = VisualEffect;

    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture2MulEffect);

    public:
        explicit Texture2MulEffect(CoreTools::DisableNotThrow disableNotThrow);

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

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Texture2MulEffect);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture2MulEffect);
}

#endif  // RENDERING_LOCAL_EFFECTS_TEXTURE2_MULEFFECT_H
