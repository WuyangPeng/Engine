// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:31)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include <boost/noncopyable.hpp>

RENDERING_NON_COPY_EXPORT_IMPL(PlatformTexture2DImpl);

namespace Rendering
{
    class Renderer;
    class Texture2D;

    class RENDERING_DEFAULT_DECLARE PlatformTexture2D
    {
    public:
        NON_COPY_TYPE_DECLARE(PlatformTexture2D);
        using TextureType = Texture2D;
        using UInt = System::OpenGLUInt;

    public:
        PlatformTexture2D(Renderer* renderer, const Texture2D* texture2D);
        virtual ~PlatformTexture2D();
        PlatformTexture2D(const PlatformTexture2D&) = delete;
        PlatformTexture2D& operator=(const PlatformTexture2D&) = delete;
        PlatformTexture2D(PlatformTexture2D&&) = delete;
        PlatformTexture2D& operator=(PlatformTexture2D&&) = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // Œ∆¿Ì≤Ÿ◊˜
        void Enable(Renderer* renderer, int textureUnit);
        void Disable(Renderer* renderer, int textureUnit);
        void* Lock(int level, BufferLocking mode);
        void Unlock(int level);

        UInt GetTexture() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_H
