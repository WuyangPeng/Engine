///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/20 13:56)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformTexture2DImpl
    {
    public:
        using ClassType = PlatformTexture2DImpl;
        using PlatformTexture2DSharedPtr = std::shared_ptr<ClassType>;
        using UInt = System::OpenGLUInt;
        using FactoryType = ClassType;

    public:
        PlatformTexture2DImpl() noexcept;
        virtual ~PlatformTexture2DImpl() noexcept = default;
        PlatformTexture2DImpl(const PlatformTexture2DImpl& rhs) noexcept = default;
        PlatformTexture2DImpl& operator=(const PlatformTexture2DImpl& rhs) noexcept = default;
        PlatformTexture2DImpl(PlatformTexture2DImpl&& rhs) noexcept = default;
        PlatformTexture2DImpl& operator=(PlatformTexture2DImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // �������
        virtual void Enable(Renderer* renderer, int textureUnit) = 0;
        virtual void Disable(Renderer* renderer, int textureUnit) = 0;
        NODISCARD virtual void* Lock(int level, BufferLocking mode) = 0;
        virtual void Unlock(int level) = 0;

        NODISCARD virtual UInt GetTexture() const = 0;

        NODISCARD static PlatformTexture2DSharedPtr Create(Renderer* renderer, const Texture2D* texture2D);

    private:
        NODISCARD static PlatformTexture2DSharedPtr CreateDefault(Renderer* renderer, const Texture2D* texture2D);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_IMPL_H
