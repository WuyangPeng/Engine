///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/20 13:52)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformTexture1DImpl
    {
    public:
        using ClassType = PlatformTexture1DImpl;
        using PlatformTexture1DSharedPtr = std::shared_ptr<ClassType>;
        using FactoryType = PlatformTexture1DImpl;

    public:
        PlatformTexture1DImpl() noexcept;
        virtual ~PlatformTexture1DImpl() noexcept = default;
        PlatformTexture1DImpl(const PlatformTexture1DImpl& rhs) noexcept = default;
        PlatformTexture1DImpl& operator=(const PlatformTexture1DImpl& rhs) noexcept = default;
        PlatformTexture1DImpl(PlatformTexture1DImpl&& rhs) noexcept = default;
        PlatformTexture1DImpl& operator=(PlatformTexture1DImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // �������
        virtual void Enable(Renderer* renderer, int textureUnit) = 0;
        virtual void Disable(Renderer* renderer, int textureUnit) = 0;
        NODISCARD virtual void* Lock(int level, BufferLocking mode) = 0;
        virtual void Unlock(int level) = 0;

        NODISCARD static PlatformTexture1DSharedPtr Create(Renderer* renderer, const Texture1D* texture1D);

    private:
        NODISCARD static PlatformTexture1DSharedPtr CreateDefault(Renderer* renderer, const Texture1D* texture1D);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_IMPL_H
