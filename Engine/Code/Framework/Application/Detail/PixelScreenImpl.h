// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:04)

#ifndef FRAMEWORK_APPLICATION_PIXEL_SCREEN_IMPL_H
#define FRAMEWORK_APPLICATION_PIXEL_SCREEN_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/Renderer.h"
#include "Framework/WindowCreate/WindowSize.h" 

#include <vector>

namespace Rendering
{
	class Renderer;
}

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE PixelScreenImpl
	{
	public:
		using ClassType = PixelScreenImpl;
		using Colour = Rendering::Colour<unsigned char>;
		using Renderer = Rendering::Renderer;

	public:
		explicit PixelScreenImpl(const WindowSize& size);
	
		CLASS_INVARIANT_DECLARE;

		void Resize(const WindowSize& size, const Colour& color);

		void Draw(const Rendering::RendererSmartPointer& renderer);

		void ClearScreen(const Colour& color);

        // 相对于右手绘制。您还可以绘制到左手屏幕，在立即绘制之前，
        // 屏幕被复制到了另一个逆行缓冲区。
        // 你只需要在应用程序调用DoFlip (true)一次的。默认值是“false”。
		void DoFlip (bool doFlip);

		bool IsDoFlip() const;
	
		// 设置位置(x,y)的像素为指定的颜色。
		void SetPixel (int x, int y, const Colour& color);

		// 设置像素 (x',y') 对 x - thick <= x' <= x + thick 和
		// y - thick <= y' <= y + thick.
		void SetThickPixel (int x, int y, int thick, const Colour& color);

		// 获取位置(x,y)的像素颜色。 
		const Colour GetPixel (int x, int y) const;
 
		// 使用Bresenham算法绘制像素为指定的的颜色从画线(beginX, beginY) 到 (endX, endY)。
		// 该算法是有偏差的，通过DrawLine(beginX, beginY, endX, endY)设定的像素不一定
		// 同DrawLine(endX, endY, beginX, beginY)设置的相同。
		// TODO：实现中点算法，以避免偏差。
		void DrawLine (int beginX, int beginY,int endX, int endY,const Colour& color);

        // 使用指定的颜色绘制轴对齐矩形。solid参数指示是否填充矩形。
		void DrawRectangle (int xMin, int yMin, int xMax,int yMax, const Colour& color, bool solid = false);
 
		// 使用Bresenham算法绘制中心在(xCenter,yCenter)和指定“半径”，
		// 并使用指定的颜色的圆。'solid'参数指示是否填充圈。
		void DrawCircle (int xCenter, int yCenter, int radius,const Colour& color, bool solid = false);
 
        // 漫水填充一个区域，通过改变其像素颜色“背景色”为“前景色”。
        // 填充处理4连屏；也就是说，在(x,y)被访问，则(x + 1,y), (x,y - 1), 和 (x,y + 1)
        // 被访问（因为它们是在屏幕的边界）。该函数通过使用栈，
        // 从而避免了真正的递归代价和调用堆栈溢出的可能。
		void Fill (int x, int y, const Colour& foreColor,const Colour& backColor);	

	private:
	    using ColourVector = std::vector<Colour>;

	private:
		void DrawSolidCircle (int xCenter, int yCenter, int radius,const Colour& color);
		void DrawHollowCircle (int xCenter, int yCenter, int radius,const Colour& color);

	private:
		int m_ScreenWidth;
		int m_ScreenHeight;
		ColourVector m_Screen;
		bool m_DoFlip;
	};
}

#endif // FRAMEWORK_APPLICATION_PIXEL_SCREEN_IMPL_H



	