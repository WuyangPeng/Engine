///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 21:06)

#ifndef RENDERING_RENDERERS_DX9_TEXTURE_2D_H
#define RENDERING_RENDERERS_DX9_TEXTURE_2D_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/OpenGLRenderer/OpenGLBindTexture.h"
#include "Rendering/Renderers/Detail/PlatformTexture2DImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Dx9Texture2D : public PlatformTexture2DImpl
    {
    public:
        using ClassType = Dx9Texture2D;
        using ParentType = PlatformTexture2DImpl;

    public:
        Dx9Texture2D(Renderer* renderer, const Texture2D* texture) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 纹理操作
        void Enable(Renderer* renderer, int textureUnit) noexcept override;
        void Disable(Renderer* renderer, int textureUnit) noexcept override;
        NODISCARD void* Lock(int level, BufferLocking mode) noexcept override;
        void Unlock(int level) noexcept override;

        NODISCARD UInt GetTexture() const noexcept override;

    private:
        Dx9Texture2D(Renderer* renderer, bool isColortexture, const Texture2D* texture, bool autoGenMipMap) noexcept;
    };
}

#endif  // RENDERING_RENDERERS_DX9_TEXTURE_2D_H
