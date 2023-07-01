///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/21 15:45)

#ifndef RENDERING_LOCAL_EFFECTS_OVERLAY_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_OVERLAY_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OverlayEffect
    {
    public:
        using ClassType = OverlayEffect;

    public:
        CLASS_INVARIANT_DECLARE;

        std::shared_ptr<const VertexBuffer> GetVertexBuffer() const noexcept;

        std::shared_ptr<const IndexBuffer> GetIndexBuffer() const noexcept;

        std::shared_ptr<const VisualEffect> GetEffect() const noexcept;
    };

}

#endif  // RENDERING_LOCAL_EFFECTS_OVERLAY_EFFECT_H
