///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureArray.h"
#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/Resources/Textures/TextureCube.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTextureCube : public OpenGLTextureArray
    {
    public:
        using ClassType = OpenGLTextureCube;
        using ParentType = OpenGLTextureArray;

    public:
        OpenGLTextureCube(const TextureCubeSharedPtr& textureCube, const std::string& name);
        ~OpenGLTextureCube() noexcept;
        OpenGLTextureCube(const OpenGLTextureCube& rhs) = default;
        OpenGLTextureCube& operator=(const OpenGLTextureCube& rhs) = default;
        OpenGLTextureCube(OpenGLTextureCube&& rhs) noexcept = default;
        OpenGLTextureCube& operator=(OpenGLTextureCube&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstTextureCubeSharedPtr GetTextureCube() const;

        NODISCARD bool CanAutoGenerateMipmaps() const override;

        void Enable() noexcept override;

    protected:
        void LoadTextureLevel(int item, int level, const ConstSpanIterator& data) override;

    public:
        [[nodiscard]] bool Update(int level) override;
        [[nodiscard]] bool CopyGpuToCpu(int level) override;
        [[nodiscard]] bool CopyCpuToGpu(int level) override;
        [[nodiscard]] bool GetNumActiveElements() override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_CUBE_H
