// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 09:46)

#include "Framework/FrameworkExport.h"

#include "WindowCreateParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowCreateParameterImpl
	::WindowCreateParameterImpl(const String& windowsName, WindowStyles style, HWnd parent, HMenu menu, const WindowPoint& leftTopCorner)
	:m_WindowsName{ windowsName }, m_Style{ style }, m_LeftTopCorner{ leftTopCorner }, m_Parent{ parent }, m_Menu{ menu }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowCreateParameterImpl)

const System::String Framework::WindowCreateParameterImpl
	::GetWindowsName() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_WindowsName;
}

Framework::WindowCreateParameterImpl::WindowStyles Framework::WindowCreateParameterImpl
	::GetStyle() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Style;
}

const Framework::WindowPoint Framework::WindowCreateParameterImpl
	::GetLeftTopCorner() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_LeftTopCorner;
}

Framework::WindowCreateParameterImpl::HWnd Framework::WindowCreateParameterImpl
	::GetParent() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Parent;
}

Framework::WindowCreateParameterImpl::HMenu Framework::WindowCreateParameterImpl
	::GetMenu() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Menu;
}

