// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:53)

#ifndef FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ViewMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(PixelViewMiddleLayerImpl);

namespace Framework
{
	class WindowPoint;

	class FRAMEWORK_DEFAULT_DECLARE PixelViewMiddleLayer: public ViewMiddleLayer
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(PixelViewMiddleLayer);
		using ParentType = ViewMiddleLayer;
		using Colour = Rendering::Colour<uint8_t>;

	public:
		PixelViewMiddleLayer();
		virtual ~PixelViewMiddleLayer();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool Initialize();
		virtual void Terminate();
		virtual bool Display(int64_t timeDelta);	
		virtual bool Resize(WindowDisplayFlags type,const WindowSize& size);

        // 可以让你在渲染屏幕多边形后做更多的渲染。
        // 屏幕覆盖应使用渲染器调用，而不是直接访问m_Screen数组。
		virtual void ScreenOverlay();

		bool IsDoFlip() const;

		void ClearScreen ();

		void DoFlip (bool doFlip);

		void SetPixel(int x, int y, const Colour& colour);

		void SetThickPixel(int x, int y, int thick, const Colour& colour);

		const Colour GetPixel(int x, int y) const;

		void DrawLine(int beginX, int beginY, int endX, int endY, const Colour& colour);

		void DrawRectangle(int xMin, int yMin, int xMax, int yMax,const Colour& colour, bool solid = false);

		void DrawCircle(int xCenter, int yCenter, int radius,const Colour& colour, bool solid = false);

		void Fill(int x, int y, const Colour& foreColour, const Colour& backColour);

	private:
		IMPL_TYPE_DECLARE(PixelViewMiddleLayer);
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_PIXEL_VIEW_MIDDLE_LAYER_H



	