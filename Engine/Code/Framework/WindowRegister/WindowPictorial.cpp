// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:36)

#include "Framework/FrameworkExport.h"

#include "WindowPictorial.h"
#include "Detail/WindowPictorialImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowRegister/WindowHBrush.h"

using std::make_shared;

Framework::WindowPictorial
	::WindowPictorial(WindowBrushTypes background)
	:impl{ background }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial
	::WindowPictorial(const TChar* icon, const TChar* cursor, WindowBrushTypes background)
	:impl{ icon, cursor, background }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial
	::WindowPictorial(HInstance instance, int icon, int cursor, WindowBrushTypes background)
	:impl{ instance, icon, cursor, background }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial
	::WindowPictorial(HInstance instance, int icon, const TChar* cursor, WindowBrushTypes background)
	:impl{ instance, icon, cursor, background }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial
	::WindowPictorial(HInstance instance, const TChar* icon, int cursor, WindowBrushTypes background)
	:impl{ instance, icon, cursor, background }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial
	::WindowPictorial(HInstance instance, bool isDefaultIcon, int icon, bool isDefaultCursor, int cursor, WindowBrushTypes background)
	:impl{ instance,isDefaultIcon, icon,isDefaultCursor, cursor, background }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowPictorial)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowPictorial, GetHIcon, System::WindowsHIcon)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowPictorial, GetHCursor, System::WindowsHCursor)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowPictorial, GetHBrush, System::WindowsHBrush)


