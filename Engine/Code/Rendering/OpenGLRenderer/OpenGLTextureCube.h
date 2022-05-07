///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 22:25)

#ifndef RENDERING_RENDERERS_OPENGL_TEXTURE_CUBE_H
#define RENDERING_RENDERERS_OPENGL_TEXTURE_CUBE_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureData.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "Rendering/Renderers/Detail/PlatformTextureCubeImpl.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLTextureCube : public PlatformTextureCubeImpl
    {
    public:
        using ClassType = OpenGLTextureCube;
        using ParentType = PlatformTextureCubeImpl;

    public:
        OpenGLTextureCube(Renderer* renderer, const TextureCube* texture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 纹理操作
        void Enable(Renderer* renderer, int textureUnit) override;
        void Disable(Renderer* renderer, int textureUnit) noexcept override;
        NODISCARD void* Lock(int face, int level, BufferLocking mode) noexcept override;
        void Unlock(int face, int level) override;

    private:
        OpenGLTextureData<TextureCube> openGLTextureData;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_TEXTURE_CUBE_H
