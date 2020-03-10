// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:40)

#include "Framework/FrameworkExport.h"

#include "WindowSize.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Window/WindowCreate.h"

#include <iostream>

using std::ostream;

Framework::WindowSize
	::WindowSize()
	:m_Width(0),m_Height(0)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowSize
	::WindowSize(int width,int height)
	:m_Width(width),m_Height(height)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowSize
	::WindowSize(LParam lParam)
	:m_Width(System::GetLowWord(lParam)),m_Height(System::GetHighWord(lParam))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowSize
     ::IsValid() const noexcept
{
	if(0 <= m_Width && 0 <= m_Height)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Framework::WindowSize
    ::SetWindowSize(int width,int height)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Width = width;
	m_Height = height;
}

int Framework::WindowSize
	::GetWindowWidth() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Width;
}

int Framework::WindowSize
	::GetWindowHeight() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Height;
}

bool Framework
	::operator == (const WindowSize& lhs,const WindowSize& rhs)
{
	return lhs.GetWindowHeight() == rhs.GetWindowHeight() &&
		   lhs.GetWindowWidth() == rhs.GetWindowWidth();
}

ostream& Framework
	::operator<<( ostream& os,const WindowSize& size )
{
	os << "width = " << size.GetWindowWidth()
	   << " height = " << size.GetWindowHeight();

	return os;
}

