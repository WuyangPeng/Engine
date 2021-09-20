// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:30)

#ifndef FRAMEWORK_APPLICATION_RENDERER_DATA_IMPL_H
#define FRAMEWORK_APPLICATION_RENDERER_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "System/Windows/Flags/WindowsFlags.h"

#include <string>
#include <memory>

namespace Rendering
{
	class Renderer;

	class RendererDataImpl 
	{
	public:
		using ClassType = RendererDataImpl;
		using Renderer = Rendering::Renderer;
		using TextureFormat = Rendering::TextureFormat;
		using Colour = Rendering::Colour<float>;
		using RendererPtr = std::shared_ptr<Renderer>;
		using RendererTypes = Rendering::RendererTypes;

	public:
                RendererDataImpl(MAYBE_UNUSED int count);
 

		CLASS_INVARIANT_DECLARE;

		void LoadConfiguration(const std::string& fileName);
		
		void ClearColor();
		void Resize(int width,int height);

		void DrawMessage (int x,int y, const Colour& color, const std::string& message);

		TextureFormat GetColorFormat() const;
		TextureFormat GetDepthStencilFormat() const;
		int GetNumMultisamples() const;
		Colour GetClearColor() const;

		const std::string GetWindowTitle() const;
		int GetXPosition () const noexcept;
		int GetYPosition () const noexcept;
		int GetWidth () const;
		int GetHeight () const;
		bool IsAllowResize() const noexcept;
		RendererTypes GetRendererType() const;

	private:		
		RendererPtr m_Renderer;
	};
}

#endif // FRAMEWORK_APPLICATION_RENDERER_DATA_IMPL_H



	