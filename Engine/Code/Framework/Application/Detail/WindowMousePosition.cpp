// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:20)

#include "Framework/FrameworkExport.h"

#include "WindowMousePosition.h"
#include "System/Window/WindowProcess.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowMousePosition
	::WindowMousePosition(HWnd hwnd)
	:m_Hwnd(hwnd)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowMousePosition
	::~WindowMousePosition()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowMousePosition
	::IsValid() const noexcept
{
	if(ParentType::IsValid() && m_Hwnd != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const Framework::WindowPoint Framework::WindowMousePosition
	::GetMousePosition() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	System::WindowPoint point;

	System::GetCursorClientPos(m_Hwnd, point);

	return WindowPoint(point);
}

void Framework::WindowMousePosition
	::SetMousePosition( const WindowPoint& windowPoint )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::WindowPoint point = { windowPoint.GetWindowX(), windowPoint.GetWindowY() };

	System::SetCursorClientPos(m_Hwnd, point);
}

Framework::WindowMousePosition::MousePositionImplPtr Framework::WindowMousePosition
	::Clone()
{
	return MousePositionImplPtr(new ClassType(m_Hwnd));
}



