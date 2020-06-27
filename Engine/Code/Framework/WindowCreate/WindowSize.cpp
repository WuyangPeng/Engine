// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 09:46)

#include "Framework/FrameworkExport.h"

#include "WindowSize.h"
#include "System/Window/WindowCreate.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <iostream>

using std::ostream;
using namespace std::literals;

Framework::WindowSize
	::WindowSize() noexcept
	:m_Width{ 0 }, m_Height{ 0 }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowSize
	::WindowSize(int width, int height)  
	:m_Width{ width }, m_Height{ height }
{
	if (m_Width < 0 || m_Height < 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("WindowSize传入的大小为负数！"s));
	}

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowSize
	::WindowSize(LParam lParam)  
	:WindowSize{ System::GetLowWord(lParam),System::GetHighWord(lParam) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowSize
	::IsValid() const noexcept
{
	if (0 <= m_Width && 0 <= m_Height)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Framework::WindowSize
	::SetWindowSize(int width, int height)  
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (width < 0 || height < 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("设置的新大小为负数！"s));
	}

	m_Width = width;
	m_Height = height;	
}

int Framework::WindowSize
	::GetWindowWidth() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Width;
}

int Framework::WindowSize
	::GetWindowHeight() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Height;
}

bool Framework
	::operator == (const WindowSize& lhs, const WindowSize& rhs) noexcept
{
	return lhs.GetWindowHeight() == rhs.GetWindowHeight() && lhs.GetWindowWidth() == rhs.GetWindowWidth();
}

ostream& Framework
	::operator<<(ostream& os, const WindowSize& size)
{
	os << "width = " << size.GetWindowWidth()
	   << " height = " << size.GetWindowHeight();

	return os;
}

