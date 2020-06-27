// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:39)

#ifndef RENDERING_RENDERERS_RENDERER_PARAMETER_H
#define RENDERING_RENDERERS_RENDERER_PARAMETER_H

#include "Rendering/RenderingDll.h"

#include "RendererBasis.h"
#include "Flags/RendererTypes.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"

RENDERING_EXPORT_SHARED_PTR(RendererParameterImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE RendererParameter
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(RendererParameter);
		using Colour = Colour<float>;

	public:	
		explicit RendererParameter(const std::string& fileName);

		CLASS_INVARIANT_DECLARE;

		void LoadConfiguration(const std::string& fileName);

		RendererTypes GetRendererType() const;

		TextureFormat GetColorFormat() const;
		TextureFormat GetDepthStencilFormat() const;
		int GetNumMultisamples() const;
		Colour GetClearColor() const;

		const std::string GetWindowTitle() const;
		int GetXPosition () const;
		int GetYPosition () const;
		int GetWidth () const;
		int GetHeight () const;
		bool IsAllowResize() const;

		void Resize(int width,int height);

		const RendererBasis GetRendererBasis() const;

		System::String GetWindowMenuName() const; 
		System::String GetWindowClassName() const;

		int GetIcon() const;
		bool IsIconDefault() const;
		int GetCursor() const;
		bool IsCursorDefault() const;
		System::WindowBrushTypes GetBackground() const;

	private:		
		void DoLoadConfiguration(const std::string& fileName);

	private:		
		IMPL_TYPE_DECLARE(RendererParameter);
	};
} 

#endif // RENDERING_RENDERERS_RENDERER_PARAMETER_H



	