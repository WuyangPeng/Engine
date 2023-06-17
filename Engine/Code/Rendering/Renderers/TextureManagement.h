///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:38)

#ifndef RENDERING_RENDERERS_TEXTURE_MANAGEMENT_H
#define RENDERING_RENDERERS_TEXTURE_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"

#include <map>
#include <memory>

namespace Rendering
{
    template <typename PlatformTextureType>
    class TextureManagement
    {
    public:
        using ClassType = TextureManagement<PlatformTextureType>;
        using TextureType = typename PlatformTextureType::TextureType;
        using ConstTextureSharedPtr = std::shared_ptr<const TextureType>;
        using PlatformTextureSharedPtr = std::shared_ptr<PlatformTextureType>;
        using RendererSharedPtr = std::shared_ptr<Renderer>;

    public:
        explicit TextureManagement(const RendererSharedPtr& renderer);

        CLASS_INVARIANT_DECLARE;

        // 1D、2D、3D、Cube纹理管理。纹理对象必须是已经由应用程序代码分配。
        void Bind(const ConstTextureSharedPtr& texture);
        void Unbind(const ConstTextureSharedPtr& texture);

        void Enable(const ConstTextureSharedPtr& texture, int textureUnit);
        void Disable(const ConstTextureSharedPtr& texture, int textureUnit);

        NODISCARD void* Lock(const ConstTextureSharedPtr& texture, int level, BufferLocking mode);
        void Unlock(const ConstTextureSharedPtr& texture, int level);
        void Update(const ConstTextureSharedPtr& texture, int level);

        NODISCARD void* LockCube(const ConstTextureSharedPtr& texture, int face, int level, BufferLocking mode);
        void UnlockCube(const ConstTextureSharedPtr& texture, int face, int level);
        void UpdateCube(const ConstTextureSharedPtr& texture, int face, int level);
        NODISCARD
        PlatformTextureSharedPtr GetResource(const ConstTextureSharedPtr& buffer);

        NODISCARD bool IsInTextureMap(const ConstTextureSharedPtr& texture);
        void InsertTextureMap(const ConstTextureSharedPtr& texture, const PlatformTextureSharedPtr& platformTexture);
        void RemoveTextureMap(const ConstTextureSharedPtr& texture);

    private:
        using TextureMap = std::map<ConstTextureSharedPtr, PlatformTextureSharedPtr>;

    private:
        std::weak_ptr<Renderer> renderer;
        TextureMap textures;
    };
}

#endif  // RENDERING_RENDERERS_TEXTURE_MANAGEMENT_H
