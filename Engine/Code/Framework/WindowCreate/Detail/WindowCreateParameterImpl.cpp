// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:39)

#include "Framework/FrameworkExport.h"

#include "WindowCreateParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowCreateParameterImpl
	::WindowCreateParameterImpl(const System::String& windowsName,WindowStylesFlags style, HWnd parent, HMenu menu,const WindowPoint& leftTopCorner)
	:m_WindowsName(windowsName),
	 m_Style(style),
	 m_LeftTopCorner(leftTopCorner),
	 m_Parent(parent),
	 m_Menu(menu)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,WindowCreateParameterImpl)

System::String Framework::WindowCreateParameterImpl
    ::GetWindowsName() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowsName;
}

Framework::WindowCreateParameterImpl::WindowStylesFlags Framework::WindowCreateParameterImpl
	::GetStyle() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Style;
}

Framework::WindowPoint Framework::WindowCreateParameterImpl
	::GetLeftTopCorner() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_LeftTopCorner;
}

Framework::WindowCreateParameterImpl::HWnd Framework::WindowCreateParameterImpl
	::GetParent() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Parent;
}

Framework::WindowCreateParameterImpl::HMenu Framework::WindowCreateParameterImpl
	::GetMenu() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Menu;
}

 