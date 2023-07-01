///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_SINGLE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_SINGLE_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTexture.h"
#include "System/OpenGL/OpenGLFwd.h"
#include "CoreTools/Base/SpanIterator.h"
#include "Rendering/Resources/Textures/TextureSingle.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(OpenGLTextureSingle, OpenGLTextureSingleImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTextureSingle : public OpenGLTexture
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(OpenGLTextureSingle);
        using ParentType = OpenGLTexture;
        using StorageType = std::vector<char>;
        using ConstSpanIterator = CoreTools::SpanIterator<StorageType::const_iterator>;

    public:
        OpenGLTextureSingle(const TextureSingleSharedPtr& textureSingle, const std::string& name, TextureTarget target, TextureTargetBinding targetBinding);
        ~OpenGLTextureSingle() noexcept;
        OpenGLTextureSingle(const OpenGLTextureSingle& rhs) = default;
        OpenGLTextureSingle& operator=(const OpenGLTextureSingle& rhs) = default;
        OpenGLTextureSingle(OpenGLTextureSingle&& rhs) noexcept = default;
        OpenGLTextureSingle& operator=(OpenGLTextureSingle&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void Initialize();

    public:
        NODISCARD ConstTextureSingleSharedPtr GetTextureSingle() const;

        NODISCARD bool Update() override;
        NODISCARD bool CopyCpuToGpu() override;
        NODISCARD bool CopyGpuToCpu() override;

        NODISCARD bool Update(int level) override;
        NODISCARD bool CopyCpuToGpu(int level) override;
        NODISCARD bool CopyGpuToCpu(int level) override;

        NODISCARD virtual bool CanAutoGenerateMipmaps() const = 0;

        virtual bool GenerateMipmaps();

    protected:
        NODISCARD bool DoCopyCpuToGpu(int level);

        void CreateStaging();

        virtual void LoadTextureLevel(int level, const ConstSpanIterator& data) = 0;

    private:
        void DeleteBuffers() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_SINGLE_H