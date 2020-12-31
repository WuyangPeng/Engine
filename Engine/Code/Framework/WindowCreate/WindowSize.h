// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 09:45)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H

#include "Framework/FrameworkDll.h"

#include "System/Window/Using/WindowUsing.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <iosfwd>

namespace Framework
{
	// 窗口大小类的声明，没有使用Impl模式。只定义了==、!=、<<操作运算符。
	class FRAMEWORK_DEFAULT_DECLARE WindowSize : private boost::equality_comparable<WindowSize>
	{
	public:
		using ClassType = WindowSize;
		using LParam = System::WindowLParam;

	public:
		WindowSize() noexcept;
		WindowSize(int width, int height);
		explicit WindowSize(LParam lParam);

		CLASS_INVARIANT_DECLARE;

		int GetWindowWidth() const noexcept;
		int GetWindowHeight() const noexcept;

		void SetWindowSize(int width, int height);

	private:
		int m_Width;
		int m_Height;
	};

	bool FRAMEWORK_DEFAULT_DECLARE operator == (const WindowSize& lhs, const WindowSize& rhs) noexcept;
	FRAMEWORK_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const WindowSize& size);
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H
