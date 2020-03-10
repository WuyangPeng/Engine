// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:10)

#ifndef FRAMEWORK_APPLICATION_PIXEL_SCREEN_H
#define FRAMEWORK_APPLICATION_PIXEL_SCREEN_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/Renderer.h"

FRAMEWORK_EXPORT_SHARED_PTR(PixelScreenImpl);

namespace Rendering
{
	class Renderer;
}

namespace Framework
{
	class WindowSize;

	class FRAMEWORK_DEFAULT_DECLARE PixelScreen
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(PixelScreen);
		using Colour = Rendering::Colour<unsigned char>;
		using Renderer = Rendering::Renderer;

	public:
		explicit PixelScreen(const WindowSize& size);
	
		CLASS_INVARIANT_DECLARE;

		void Resize(const WindowSize& size, const Colour& color);

		void Draw(const Rendering::RendererSmartPointer& renderer);

		void ClearScreen(const Colour& color);
		bool IsDoFlip() const;
		void DoFlip (bool doFlip);	
		void SetPixel (int x, int y, const Colour& color);
		void SetThickPixel (int x, int y, int thick, const Colour& color);
		const Colour GetPixel (int x, int y) const;
		void DrawLine (int beginX, int beginY,int endX, int endY, const Colour& color);
		void DrawRectangle (int xMin, int yMin, int xMax,int yMax, const Colour& color,  bool solid = false); 
		void DrawCircle (int xCenter, int yCenter, int radius,  const Colour& color, bool solid = false);
		void Fill (int x, int y, const Colour& foreColor, const Colour& backColor);	

	private:
		;
		IMPL_TYPE_DECLARE(PixelScreen);
	};
}

#endif // FRAMEWORK_APPLICATION_PIXEL_SCREEN_H



	