// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 09:39)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H

#include "Framework/FrameworkDll.h"

#include "System/Window/Using/WindowUsing.h"

#include <boost/operators.hpp>
#include <iosfwd>

namespace Framework
{
	// ���ڴ�С�������
	// û��ʹ��Implģʽ��ֻ������==��!=��<<�����������
	class FRAMEWORK_DEFAULT_DECLARE WindowSize : private boost::equality_comparable<WindowSize>
	{
	public:
		using ClassType = WindowSize;
		using LParam = System::WindowLParam;

	public:
		WindowSize();
		WindowSize(int width,int height);
		explicit WindowSize(LParam lParam);
		
		CLASS_INVARIANT_DECLARE;

		int GetWindowWidth() const;
		int GetWindowHeight() const;

		void SetWindowSize(int width,int height);

	private:
		int m_Width;
		int m_Height;
	};

	bool FRAMEWORK_DEFAULT_DECLARE operator == (const WindowSize& lhs,const WindowSize& rhs);
	FRAMEWORK_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os,const WindowSize& size);
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H
