///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:35)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformTexture3DImpl
    {
    public:
        using ClassType = PlatformTexture3DImpl;
        using PlatformTexture3DSharedPtr = std::shared_ptr<ClassType>;
        using FactoryType = ClassType;

    public:
        PlatformTexture3DImpl() noexcept;
        virtual ~PlatformTexture3DImpl() noexcept = default;
        PlatformTexture3DImpl(const PlatformTexture3DImpl& rhs) noexcept = default;
        PlatformTexture3DImpl& operator=(const PlatformTexture3DImpl& rhs) noexcept = default;
        PlatformTexture3DImpl(PlatformTexture3DImpl&& rhs) noexcept = default;
        PlatformTexture3DImpl& operator=(PlatformTexture3DImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 纹理操作
        virtual void Enable(Renderer* renderer, int textureUnit) = 0;
        virtual void Disable(Renderer* renderer, int textureUnit) = 0;
        NODISCARD virtual void* Lock(int level, BufferLocking mode) = 0;
        virtual void Unlock(int level) = 0;

        NODISCARD static PlatformTexture3DSharedPtr Create(Renderer* renderer, const Texture3D* texture3D);

    private:
        NODISCARD static PlatformTexture3DSharedPtr CreateDefault(Renderer* renderer, const Texture3D* texture3D);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_IMPL_H
