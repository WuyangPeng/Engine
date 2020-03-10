// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:36)

#ifndef FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/Renderer.h"

namespace Framework
{
	class WindowPoint;
	class PixelScreen;
	class WindowSize;

	class FRAMEWORK_HIDDEN_DECLARE PixelViewMiddleLayerImpl
	{
	public:
		using ClassType = PixelViewMiddleLayerImpl;
		using Colour = Rendering::Colour<uint8_t>;
		using RendererSmartPointer = Rendering::RendererSmartPointer;

	public:
		PixelViewMiddleLayerImpl(); 

		CLASS_INVARIANT_DECLARE;	

		const Colour GetPixel(int x, int y) const;
		bool IsDoFlip() const;

		void Resize(const WindowSize& windowSize, const Colour& colour);

		void ClearScreen(const Colour& colour);

		void DoFlip (bool doFlip);

		void SetPixel(int x, int y, const Colour& colour);

		void SetThickPixel(int x, int y, int thick, const Colour& colour);		

		void DrawLine(int beginX, int beginY, int endX, int endY, const Colour& colour);

		void DrawRectangle(int xMin, int yMin, int xMax, int yMax,const Colour& colour, bool solid = false);

		void DrawCircle(int xCenter, int yCenter, int radius,const Colour& colour, bool solid = false);

		void Fill(int x, int y, const Colour& foreColour, const Colour& backColour);

		void Draw(const RendererSmartPointer& renderer);

	private:
		static const int sm_DefaultWidth = 1024;
		static const int sm_DefaultHeight = 768;

		std::shared_ptr<PixelScreen> m_PixelScreen;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H



	