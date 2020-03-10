// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:04)

#ifndef RENDERING_RENDERERS_RENDERER_PARAMETER_IMPL_H
#define RENDERING_RENDERERS_RENDERER_PARAMETER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

#include <string>

namespace Rendering
{
	class RendererParameterImpl 
	{
	public:
		using ClassType = RendererParameterImpl;
		using ColourType = Colour<float>;

	public:
		explicit RendererParameterImpl(RendererTypes type);

		CLASS_INVARIANT_DECLARE;

		TextureFormat GetColorFormat() const;
		TextureFormat GetDepthStencilFormat() const;
		int GetNumMultisamples() const;
		ColourType GetClearColor() const;

		const std::string GetWindowTitle() const;
		int GetXPosition () const;
		int GetYPosition () const;
		int GetWidth () const;
		int GetHeight () const;
		bool IsAllowResize() const;
		RendererTypes GetRendererType() const;

		void SetTextureFormat(TextureFormat colorFormat, TextureFormat depthStencilFormat, int numMultisamples);

		void SetClearColor(float red,float green,float blue,float alpha);

		void SetWindowParameter(const std::string& windowTitle,int width,int height,int x,int y,bool allowResize);

		void Resize(int width,int height);

		const RendererBasis GetRendererBasis() const;

	private:		
		RendererTypes m_Type;
		RendererBasis m_RendererBasis;
        ColourType m_Colour; 
		std::string m_WindowTitle;	
		int m_WindowX;
		int m_WindowY;
		bool m_IsAllowResize;
	};
}

#endif // RENDERING_RENDERERS_RENDERER_PARAMETER_IMPL_H



	