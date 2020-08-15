// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:36)

#ifndef RENDERING_RENDERERS_RENDERER_BASIS_H
#define RENDERING_RENDERERS_RENDERER_BASIS_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Flags/TextureFormat.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE RendererBasis 
	{
	public:
		using ClassType = RendererBasis;

	public:
		RendererBasis() noexcept;
		RendererBasis(int width,int height,TextureFormat colorFormat,TextureFormat depthStencilFormat,  int numMultisamples) noexcept;

		CLASS_INVARIANT_DECLARE;
	
		int GetWidth () const noexcept;
		int GetHeight () const noexcept;	
		TextureFormat GetColorFormat() const noexcept;
		TextureFormat GetDepthStencilFormat() const noexcept;
		int GetNumMultisamples() const noexcept;

		void SetSize(int width,int height) noexcept;
		void SetTextureFormat(TextureFormat colorFormat,TextureFormat depthStencilFormat) noexcept;
		void SetMultisamplesNumber(int numMultisamples) noexcept;

	private:
		int m_WindowWidth;
		int m_WindowHeight;		
        TextureFormat m_ColorFormat;
        TextureFormat m_DepthStencilFormat;
        int m_MultisamplesNumber;	 
	};
}

#endif // RENDERING_RENDERERS_RENDERER_BASIS_H



	