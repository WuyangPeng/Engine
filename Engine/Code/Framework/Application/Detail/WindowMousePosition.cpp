// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "WindowMousePosition.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

Framework::WindowMousePosition
	::WindowMousePosition(HWnd hwnd) noexcept
	:m_Hwnd{ hwnd }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowMousePosition
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_Hwnd != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const Framework::WindowPoint Framework::WindowMousePosition
	::GetMousePosition() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	System::WindowsPoint point{ };

[[maybe_unused]] const auto result = System::GetCursorClientPos(m_Hwnd, point);

	return WindowPoint{ point };
}

void Framework::WindowMousePosition
	::SetMousePosition(const WindowPoint& windowPoint) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	System::WindowsPoint point{ windowPoint.GetWindowX(), windowPoint.GetWindowY() };

	[[maybe_unused]] const auto result = System::SetCursorClientPos(m_Hwnd, point);
}

Framework::WindowMousePosition::MousePositionImplSharedPtr Framework::WindowMousePosition ::Clone() const
{
	return make_shared<ClassType>(m_Hwnd);
}



