// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:47)

#ifndef FRAMEWORK_APPLICATION_PIXEL_SCREEN_H
#define FRAMEWORK_APPLICATION_PIXEL_SCREEN_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"

FRAMEWORK_EXPORT_SHARED_PTR(PixelScreenImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE PixelScreen
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(PixelScreen);
		using Colour = Rendering::Colour<uint8_t>;
		using Renderer = Rendering::Renderer;
		using RendererSharedPtr = Rendering::RendererSharedPtr;

	public:
		explicit PixelScreen(const WindowSize& size);

		CLASS_INVARIANT_DECLARE;

		int GetScreenWidth() const noexcept;
		int GetScreenHeight() const noexcept;

		const Colour GetPixel(int x, int y) const;

		void ClearScreen(const Colour& color);

		void Resize(const WindowSize& size, const Colour& color);
		
		bool IsDoFlip() const noexcept;
		void DoFlip(bool doFlip);
		void SetPixel(int x, int y, const Colour& color);
		void SetThickPixel(int x, int y, int thick, const Colour& color);	

		void DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& color);
		void DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& color, bool solid = false);
		void DrawCircle(int xCenter, int yCenter, int radius, const Colour& color, bool solid = false);
		void Fill(int x, int y, const Colour& foreColor, const Colour& backColor);

		void Draw(const Rendering::RendererSharedPtr& renderer);

	private:
		IMPL_TYPE_DECLARE(PixelScreen);
	};
}

#endif // FRAMEWORK_APPLICATION_PIXEL_SCREEN_H



