// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:50)

#ifndef FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ViewMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(PixelViewMiddleLayerImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE PixelViewMiddleLayer : public ViewMiddleLayer
	{
	public:
		NON_COPY_TYPE_DECLARE(PixelViewMiddleLayer);
		using ParentType = ViewMiddleLayer;
		using Colour = Rendering::Colour<uint8_t>;

	public:
		explicit PixelViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform);
		~PixelViewMiddleLayer() noexcept = default;
		PixelViewMiddleLayer(const PixelViewMiddleLayer& rhs) noexcept = delete;
		PixelViewMiddleLayer& operator=(const PixelViewMiddleLayer& rhs) noexcept = delete;
		PixelViewMiddleLayer(PixelViewMiddleLayer&& rhs) noexcept;
		PixelViewMiddleLayer& operator=(PixelViewMiddleLayer&& rhs) noexcept;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		bool Initialize() override;
		bool Idle(int64_t timeDelta) override;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;	

		// 可以让你在渲染屏幕多边形后做更多的渲染。屏幕覆盖应使用渲染器调用，而不是直接访问m_Screen数组。
		virtual void ScreenOverlay();

		bool IsDoFlip() const noexcept;

		void ClearScreen();

		void DoFlip(bool doFlip);

		void SetPixel(int x, int y, const Colour& colour);

		void SetThickPixel(int x, int y, int thick, const Colour& colour);

		const Colour GetPixel(int x, int y) const;

		void DrawLine(int xMin, int yMin, int xMax, int yMax, const Colour& colour);

		void DrawRectangle(int xMin, int yMin, int xMax, int yMax, const Colour& colour, bool solid = false);

		void DrawCircle(int xCenter, int yCenter, int radius, const Colour& colour, bool solid = false);

		void Fill(int x, int y, const Colour& foreColour, const Colour& backColour);

		int GetScreenWidth() const noexcept;
		int GetScreenHeight() const noexcept;

	private:
                PackageType impl;
                
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H



