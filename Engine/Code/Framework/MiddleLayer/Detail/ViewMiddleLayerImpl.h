// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:46)

#ifndef FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/Renderers/Renderer.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Framework/WindowCreate/WindowCreateFwd.h" 

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ViewMiddleLayerImpl
	{
	public:
		using ClassType = ViewMiddleLayerImpl;
		using Renderer = Rendering::Renderer;
		using Colour = Rendering::Colour<float>;
		using RendererSharedPtr = Rendering::RendererSharedPtr;
		using ConstRendererSharedPtr = Rendering::ConstRendererSharedPtr;

	public:
		ViewMiddleLayerImpl() noexcept;
		~ViewMiddleLayerImpl() noexcept = default;
		ViewMiddleLayerImpl(const ViewMiddleLayerImpl& rhs) noexcept = delete;
		ViewMiddleLayerImpl& operator=(const ViewMiddleLayerImpl& rhs) noexcept = delete;
		ViewMiddleLayerImpl(ViewMiddleLayerImpl&& rhs) noexcept;
		ViewMiddleLayerImpl& operator=(ViewMiddleLayerImpl&& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

		void Resize(int width, int height);
		void DrawFrameRate(int x, int y, const Colour& color, const std::string& message);
		void ResetRenderer(const std::string& fileName);
		void ClearColorBuffer();

		const Colour GetClearColor() const;
		void SetClearColor(const Colour& colour);

		const RendererSharedPtr GetRenderer() noexcept;
		const ConstRendererSharedPtr GetRenderer() const noexcept;

	private:
		RendererSharedPtr m_Renderer;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_IMPL_H



