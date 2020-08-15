// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:37)

#ifndef RENDERING_RENDERERS_DX9_TEXTURE_1D_H
#define RENDERING_RENDERERS_DX9_TEXTURE_1D_H

#include "Rendering/RenderingDll.h"

#include "System/Window/Flags/WindowFlags.h"
#include "Rendering/Renderers/Detail/PlatformTexture1DImpl.h"

namespace Rendering
{
    class Renderer;
    class Texture1D;

    class RENDERING_HIDDEN_DECLARE Dx9Texture1D : public PlatformTexture1DImpl
    {
    public:
        using ClassType = Dx9Texture1D;
        using ParentType = PlatformTexture1DImpl;

    public:
        Dx9Texture1D(Renderer* renderer, const Texture1D* texture);
        ~Dx9Texture1D();
        Dx9Texture1D(const Dx9Texture1D&) = default;
        Dx9Texture1D& operator=(const Dx9Texture1D&) = default;
        Dx9Texture1D(Dx9Texture1D&&) = default;
        Dx9Texture1D& operator=(Dx9Texture1D&&) = default;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        // Œ∆¿Ì≤Ÿ◊˜
        void Enable(Renderer* renderer, int textureUnit) override;
        void Disable(Renderer* renderer, int textureUnit) override;
        void* Lock(int level, BufferLocking mode) override;
        void Unlock(int level) override;

    private:
        //IDirect3DTexture9* mTexture;
    };
}

#endif  // RENDERING_RENDERERS_DX9_TEXTURE_1D_H
