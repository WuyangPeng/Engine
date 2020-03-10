// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:46)

#include "Framework/FrameworkExport.h"

#include "WindowPictorial.h"
#include "Detail/WindowPictorialImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowPictorial
	::WindowPictorial(System::WindowBrushTypes background)
	:m_Impl(new ImplType(background))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial
	::WindowPictorial(const System::TChar* icon,const System::TChar* cursor,System::WindowBrushTypes background)
	:m_Impl(new ImplType(icon,cursor,background))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial
	::WindowPictorial(HInstance hInstance,int icon,int cursor,System::WindowBrushTypes background)
	:m_Impl(new ImplType(hInstance,icon,cursor,background))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial
	::WindowPictorial(HInstance hInstance,int icon,const System::TChar* cursor,System::WindowBrushTypes background )
	:m_Impl(new ImplType(hInstance,icon,cursor,background))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::WindowPictorial
	::WindowPictorial(HInstance hInstance,const System::TChar* icon,int cursor,System::WindowBrushTypes background)
	:m_Impl(new ImplType(hInstance,icon,cursor,background))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework,WindowPictorial)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowPictorial,GetHIcon,System::WindowHIcon)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowPictorial,GetHCursor,System::WindowHCursor)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework,WindowPictorial,GetHBrush,System::WindowHBrush)


