// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 13:40)

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
		PixelScreenDrawLine(int xMin, int yMin, int xMax, int yMax);

		CLASS_INVARIANT_DECLARE;

#ifdef OPEN_CLASS_INVARIANT
		bool IsEndpointCorrect() const;
#endif // OPEN_CLASS_INVARIANT

		int GetSize() const;
		const WindowPoint& operator[](int index) const;

	private:
		using WindowPointContainer = std::vector<WindowPoint>;

	private:
		void Calculate();
		void DrawLineOnX();
		void DrawLineOnY();

	private:
		int m_XMin;
		int m_YMin;
		int m_XMax;
		int m_YMax;

		// �߶εķ���
		int m_DistanceX;
		int m_DistanceY;

		// ���������ȡ�����ߵķ���
		int m_StepX;
		int m_StepY;

		WindowPointContainer m_Line;
	};
}

#endif // FRAMEWORK_APPLICATION_PIXEL_SCREEN_DRAW_LINE_H



