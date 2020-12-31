// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:46)

#ifndef FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Framework/Application/PixelScreen.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE PixelViewMiddleLayerImpl
	{
	public:
		using ClassType = PixelViewMiddleLayerImpl;
		using Colour = Rendering::Colour<uint8_t>;
		using RendererSharedPtr = Rendering::RendererSharedPtr;

	public:
		PixelViewMiddleLayerImpl(int width, int height);

		CLASS_INVARIANT_DECLARE;

		const Colour GetPixel(int x, int y) const;
		bool IsDoFlip() const noexcept;

		void Resize(const WindowSize& windowSize, const Colour& colour);

		void ClearScreen(const Colour& colour);

		void DoFlip(bool doFlip);

		void SetPixel(int x, int y, const Colour& colour);

		void SetThickPixel(int x, int y, int thick, const Colour& colour);

		void DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& colour);

		void DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid = false);

		void DrawCircle(int xCenter, int yCenter, int radius, const Colour& colour, bool solid = false);

		void Fill(int x, int y, const Colour& foreColour, const Colour& backColour);

		void Draw(const RendererSharedPtr& renderer);

		int GetScreenWidth() const noexcept;
		int GetScreenHeight() const noexcept;

	private:
		PixelScreen m_PixelScreen;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H



