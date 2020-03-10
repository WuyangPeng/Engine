// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 09:38)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_POINT_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_POINT_H

#include "Framework/FrameworkDll.h"

#include "System/Window/Using/WindowUsing.h"

#include <boost/operators.hpp>
#include <iosfwd>

namespace Framework
{
	// 窗口点类的声明
	// 没有使用Impl模式。只定义了==、!=、<<操作运算符。
	class FRAMEWORK_DEFAULT_DECLARE WindowPoint : private boost::equality_comparable<WindowPoint>
	{
	public:
		using ClassType = WindowPoint;
		using Point = System::WindowPoint;
		using LParam = System::WindowLParam;

	public:
		WindowPoint();
		explicit WindowPoint(const Point& point);
		explicit WindowPoint(LParam lParam);
		WindowPoint(int x,int y);
		
		CLASS_INVARIANT_DECLARE;

		int GetWindowX() const;
		int GetWindowY() const;

		void SetWindowPoint(int x,int y);

	private:
		int m_X;
		int m_Y;
	};

	bool FRAMEWORK_DEFAULT_DECLARE operator == (const WindowPoint& lhs,const WindowPoint& rhs);
	FRAMEWORK_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os,const WindowPoint& windowPoint);
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_POINT_H
