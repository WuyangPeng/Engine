///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:35)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_CUBE_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_CUBE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformTextureCubeImpl
    {
    public:
        using ClassType = PlatformTextureCubeImpl;
        using PlatformTextureCubeSharedPtr = std::shared_ptr<ClassType>;
        using FactoryType = ClassType;

    public:
        PlatformTextureCubeImpl() noexcept;
        virtual ~PlatformTextureCubeImpl() noexcept = default;
        PlatformTextureCubeImpl(const PlatformTextureCubeImpl& rhs) noexcept = default;
        PlatformTextureCubeImpl& operator=(const PlatformTextureCubeImpl& rhs) noexcept = default;
        PlatformTextureCubeImpl(PlatformTextureCubeImpl&& rhs) noexcept = default;
        PlatformTextureCubeImpl& operator=(PlatformTextureCubeImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 纹理操作
        virtual void Enable(Renderer* renderer, int textureUnit) = 0;
        virtual void Disable(Renderer* renderer, int textureUnit) = 0;
        NODISCARD virtual void* Lock(int face, int level, BufferLocking mode) = 0;
        virtual void Unlock(int face, int level) = 0;

        NODISCARD static PlatformTextureCubeSharedPtr Create(Renderer* renderer, const TextureCube* textureCube);

    private:
        NODISCARD static PlatformTextureCubeSharedPtr CreateDefault(Renderer* renderer, const TextureCube* textureCube);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_TEXTURE_CUBE_IMPL_H
