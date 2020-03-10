// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:40)

#include "Framework/FrameworkExport.h"

#include "WindowPoint.h"
#include "System/Window/WindowCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

#include <iostream>

using std::ostream;

Framework::WindowPoint
	::WindowPoint()
	:m_X(0),m_Y(0)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPoint
	::WindowPoint(int x,int y)
	:m_X(x),m_Y(y)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPoint
	::WindowPoint( const Point& point )
	:m_X(static_cast<int>(point.x)),
	 m_Y(static_cast<int>(point.y))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPoint
	::WindowPoint( LParam lParam )
	:m_X(System::GetLowWord(lParam)),
	 m_Y(System::GetHighWord(lParam))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,WindowPoint)

void Framework::WindowPoint
    ::SetWindowPoint(int x,int y)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_X = x;
	m_Y = y;
}

int Framework::WindowPoint
	::GetWindowX() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_X;
}

int Framework::WindowPoint
	::GetWindowY() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Y;
}

bool Framework
	::operator == (const WindowPoint& lhs,const WindowPoint& rhs)
{
	return lhs.GetWindowX() == rhs.GetWindowX() &&
		   lhs.GetWindowY() == rhs.GetWindowY();
}

std::ostream& Framework
	::operator<<( std::ostream& os,const WindowPoint& windowPoint )
{
	os << "x = " << windowPoint.GetWindowX()
	   << " y = " << windowPoint.GetWindowY();

	return os;
}

