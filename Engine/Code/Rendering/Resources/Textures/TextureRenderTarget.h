///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 20:18)

#ifndef RENDERING_RESOURCES_TEXTURE_RENDER_TARGET_H
#define RENDERING_RESOURCES_TEXTURE_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "Texture2D.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextureRenderTarget : public Texture2D
    {
    public:
        using ClassType = TextureRenderTarget;
        using ParentType = Texture2D;

    public:
        TextureRenderTarget(DataFormatType format, int width, int height, bool hasMipMaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TextureRenderTarget);

        NODISCARD TextureSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TextureRenderTarget);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TextureRenderTarget);
}

#endif  // RENDERING_RESOURCES_TEXTURE_RENDER_TARGET_H