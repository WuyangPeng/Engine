///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/25 14:21)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_ARRAY_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTexture.h"
#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/Resources/Textures/TextureArray.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(OpenGLTextureArray, OpenGLTextureSingleImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLTextureArray : public OpenGLTexture
    {
    public:
        using OpenGLTextureArrayImpl = OpenGLTextureSingleImpl;
        COPY_UNSHARED_TYPE_DECLARE(OpenGLTextureArray);
        using ParentType = OpenGLTexture;

        using TextureCubeMap = System::TextureCubeMap;
        using StorageType = std::vector<char>;
        using ConstSpanIterator = CoreTools::SpanIterator<StorageType::const_iterator>;

    public:
        OpenGLTextureArray(const TextureArraySharedPtr& textureArray, const std::string& name, TextureTarget target, TextureTargetBinding targetBinding);
        ~OpenGLTextureArray() noexcept;
        OpenGLTextureArray(const OpenGLTextureArray& rhs) = default;
        OpenGLTextureArray& operator=(const OpenGLTextureArray& rhs) = default;
        OpenGLTextureArray(OpenGLTextureArray&& rhs) noexcept = default;
        OpenGLTextureArray& operator=(OpenGLTextureArray&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void Initialize();

    public:
        NODISCARD ConstTextureArraySharedPtr GetTextureArray() const;

        NODISCARD bool Update() override;
        NODISCARD bool CopyCpuToGpu() override;
        NODISCARD bool CopyGpuToCpu() override;

        NODISCARD bool Update(int item, int level);
        NODISCARD bool CopyCpuToGpu(int item, int level);
        NODISCARD bool CopyGpuToCpu(int item, int level);

        virtual bool CanAutoGenerateMipmaps() const = 0;

        virtual bool GenerateMipmaps();

    protected:
        NODISCARD bool DoCopyCpuToGpu(int item, int level);

        void CreateStaging();

        virtual void LoadTextureLevel(int item, int level, const ConstSpanIterator& data) = 0;

        NODISCARD static TextureCubeMap GetCubeFaceTarget(int index);

    private:
        void DeleteBuffers() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_ARRAY_H