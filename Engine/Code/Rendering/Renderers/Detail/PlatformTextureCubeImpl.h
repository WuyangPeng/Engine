// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:25)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_CUBE_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_CUBE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <memory>

namespace Rendering
{
    class Renderer;
    class TextureCube;

    class RENDERING_HIDDEN_DECLARE PlatformTextureCubeImpl
    {
    public:
        using ClassType = PlatformTextureCubeImpl;
        using PlatformTextureCubePtr = std::shared_ptr<ClassType>;
          using FactoryType = ClassType;
    public:
        PlatformTextureCubeImpl() noexcept;
        virtual ~PlatformTextureCubeImpl();
        PlatformTextureCubeImpl(const PlatformTextureCubeImpl&) = default;
        PlatformTextureCubeImpl& operator=(const PlatformTextureCubeImpl&) = default;
        PlatformTextureCubeImpl(PlatformTextureCubeImpl&&) = default;
        PlatformTextureCubeImpl& operator=(PlatformTextureCubeImpl&&) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // Œ∆¿Ì≤Ÿ◊˜
        virtual void Enable(Renderer* renderer, int textureUnit) = 0;
        virtual void Disable(Renderer* renderer, int textureUnit) = 0;
        virtual void* Lock(int face, int level, BufferLocking mode) = 0;
        virtual void Unlock(int face, int level) = 0;

        static PlatformTextureCubePtr Create(Renderer* renderer, const TextureCube* textureCube);

    private:
        static PlatformTextureCubePtr CreateDefault(Renderer* renderer, const TextureCube* textureCube);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_TEXTURE_CUBE_IMPL_H
