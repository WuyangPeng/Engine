// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:22)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Resources/Flags/BufferFlags.h"

#include <memory>

namespace Rendering
{
    class Renderer;
    class Texture2D;

    class RENDERING_HIDDEN_DECLARE PlatformTexture2DImpl
    {
    public:
        using ClassType = PlatformTexture2DImpl;
        using PlatformTexture2DPtr = std::shared_ptr<ClassType>;
        using UInt = System::OpenGLUInt;
          using FactoryType = ClassType;
    public:
        PlatformTexture2DImpl() noexcept;
        virtual ~PlatformTexture2DImpl();
        PlatformTexture2DImpl(const PlatformTexture2DImpl&) = default;
        PlatformTexture2DImpl& operator=(const PlatformTexture2DImpl&) = default;
        PlatformTexture2DImpl(PlatformTexture2DImpl&&) = default;
        PlatformTexture2DImpl& operator=(PlatformTexture2DImpl&&) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // Œ∆¿Ì≤Ÿ◊˜
        virtual void Enable(Renderer* renderer, int textureUnit) = 0;
        virtual void Disable(Renderer* renderer, int textureUnit) = 0;
        virtual void* Lock(int level, BufferLocking mode) = 0;
        virtual void Unlock(int level) = 0;

        virtual UInt GetTexture() const = 0;

        static PlatformTexture2DPtr Create(Renderer* renderer, const Texture2D* texture2D);

    private:
        static PlatformTexture2DPtr CreateDefault(Renderer* renderer, const Texture2D* texture2D);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_IMPL_H
