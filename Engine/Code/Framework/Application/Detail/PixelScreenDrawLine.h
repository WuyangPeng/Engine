// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:03)

#ifndef FRAMEWORK_APPLICATION_PIXEL_SCREEN_DRAW_LINE_H
#define FRAMEWORK_APPLICATION_PIXEL_SCREEN_DRAW_LINE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/WindowCreate/WindowPoint.h"

#include <vector>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE PixelScreenDrawLine
	{
	public:
		using ClassType = PixelScreenDrawLine;

	public:
		PixelScreenDrawLine(int beginX, int beginY,int endX, int endY);
	
		CLASS_INVARIANT_DECLARE;

	    int GetSize() const;
        const WindowPoint& operator[](int index) const;		 

	private:
	    using WindowPointVector = std::vector<WindowPoint>;

	private:
		void Calculate();
		void DrawLineOnX();
		void DrawLineOnY();

	private:
		int m_BeginX;
		int m_BeginY;
		int m_EndX;
		int m_EndY;

        // 线段的方向。
		int m_DistanceX;
		int m_DistanceY;

        // 增量或减量取决于线的方向。
		int m_StepX;
		int m_StepY;

		WindowPointVector m_Line;
	};
}

#endif // FRAMEWORK_APPLICATION_PIXEL_SCREEN_DRAW_LINE_H



	