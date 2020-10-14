// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:36)

#ifndef RENDERING_RENDERERS_DX9_RENDER_TARGET_H
#define RENDERING_RENDERERS_DX9_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/PlatformRenderTargetImpl.h"

namespace Rendering
{
	class Renderer;
	class RenderTarget;

	class Dx9RenderTarget : public PlatformRenderTargetImpl
	{
	public:
		using ClassType = Dx9RenderTarget;
		using ParentType = PlatformRenderTargetImpl;

	public:
		Dx9RenderTarget (Renderer* renderer,const RenderTarget* renderTarget);
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 void Enable (Renderer* renderer) override;
		 void Disable (Renderer* renderer) override;
		 ConstTexture2DSharedPtr ReadColor(int index,Renderer* renderer) override;
	};
}

#endif // RENDERING_RENDERERS_DX9_RENDER_TARGET_H


/*

#ifndef WM5DX9RENDERTARGET_H
#define WM5DX9RENDERTARGET_H

#include "Wm5Dx9RendererLIB.h"
#include "Wm5RenderTarget.h"

namespace Wm5
{

class Renderer;

class PdrRenderTarget
{
public:
    // Construction and destruction.
    PdrRenderTarget (Renderer* renderer, const RenderTarget* renderTarget);
    ~PdrRenderTarget ();

    // Render target operations.
    void Enable (Renderer* renderer);
    void Disable (Renderer* renderer);
    void ReadColor (int i, Renderer* renderer, Texture2D*& texture);

private:
    // Support for multiple render targets.
    int mNumTargets;
    unsigned int mWidth, mHeight;
    Texture::Format mFormat;
    bool mHasDepthStencil;

    // The color arrays have sizes equal to the number of targets.  The
    // depth-stencil buffer is shared (naturally, because multiple color
    // writes occur in the same pixel shader call, but only one depth is
    // computed).
    IDirect3DTexture9** mColorTextures;
    IDirect3DSurface9** mColorSurfaces;
    IDirect3DTexture9* mDepthStencilTexture;
    IDirect3DSurface9* mDepthStencilSurface;

    // Support for enable/disable.  We have to get/set the render target 0,
    // which is the backbuffer.
    IDirect3DSurface9* mSaveColorSurface;
    IDirect3DSurface9* mSaveDepthStencilSurface;
};

}

#endif
*/