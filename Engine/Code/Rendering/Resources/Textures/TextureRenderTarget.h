///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/16 10:23)

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
        TextureRenderTarget(DataFormatType format, int width, int height, bool hasMipmaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TextureRenderTarget);

        NODISCARD TextureSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TextureRenderTarget);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TextureRenderTarget);
}

#endif  // RENDERING_RESOURCES_TEXTURE_RENDER_TARGET_H