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
		RendererBasis();
		RendererBasis(int width,int height,TextureFormat colorFormat,TextureFormat depthStencilFormat,  int numMultisamples);

		CLASS_INVARIANT_DECLARE;
	
		int GetWidth () const;
		int GetHeight () const;	
		TextureFormat GetColorFormat() const;
		TextureFormat GetDepthStencilFormat() const;
		int GetNumMultisamples() const;

		void SetSize(int width,int height);
		void SetTextureFormat(TextureFormat colorFormat,TextureFormat depthStencilFormat);
		void SetMultisamplesNumber(int numMultisamples);

	private:
		int m_WindowWidth;
		int m_WindowHeight;		
        TextureFormat m_ColorFormat;
        TextureFormat m_DepthStencilFormat;
        int m_MultisamplesNumber;	 
	};
}

#endif // RENDERING_RENDERERS_RENDERER_BASIS_H



	