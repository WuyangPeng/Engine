// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:37)

#ifndef FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Renderers/Renderer.h"

namespace Framework
{
	class WindowPoint;

	class FRAMEWORK_HIDDEN_DECLARE ViewMiddleLayerImpl
	{
	public:
		using ClassType = ViewMiddleLayerImpl;
		using Colour = Rendering::Colour<float>;
		using Renderer = Rendering::Renderer;
		using RendererSmartPointer = Rendering::RendererSmartPointer;
		using ConstRendererSmartPointer = Rendering::ConstRendererSmartPointer;

	public:
		ViewMiddleLayerImpl(); 
	
		CLASS_INVARIANT_DECLARE;
	 
		void Resize(int width, int height);
		void DrawFrameRate(int x, int y, const Colour& color, const std::string& message);	
		void ResetRenderer(const std::string& fileName);
		void ClearColorBuffer();

		const Colour GetClearColor() const;

		const RendererSmartPointer GetRenderer();
		const ConstRendererSmartPointer GetConstRenderer() const;

	private:
		RendererSmartPointer m_Renderer;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H



	