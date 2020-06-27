// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:53)

#include "Framework/FrameworkExport.h"

#include "VirtualKeysTypes.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 
#include "System/Helper/PragmaWarning/Freeglut.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::VirtualKeysTypes
	::VirtualKeysTypes(WParam wParam) noexcept
	: m_IsCtrlKeyDown{ (wParam & WindowApplicationTrait::MouseModifiers::sm_ModifierControl) != 0 },
	  m_IsLeftMouseDown{ (wParam & WindowApplicationTrait::MouseModifiers::sm_ModifierLeftButton) != 0 },
	  m_IsMiddleMouseDown{ (wParam & WindowApplicationTrait::MouseModifiers::sm_ModifierMiddleButton) != 0 },
	  m_IsRightMouseDown{ (wParam & WindowApplicationTrait::MouseModifiers::sm_ModifierRightButton) != 0 },
	  m_IsShiftKeyDown{ (wParam & WindowApplicationTrait::MouseModifiers::sm_ModifierShift) != 0 }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9; 
}

CLASS_INVARIANT_STUB_DEFINE(Framework, VirtualKeysTypes)

bool Framework::VirtualKeysTypes
	::IsCtrlKeyDown() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsCtrlKeyDown;
}

bool Framework::VirtualKeysTypes
	::IsLeftMouseDown() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsLeftMouseDown;
}

bool Framework::VirtualKeysTypes
	::IsMiddleMouseDown() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsMiddleMouseDown;
}

bool Framework::VirtualKeysTypes
	::IsRightMouseDown() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsRightMouseDown;
}

bool Framework::VirtualKeysTypes
	::IsShiftKeyDown() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsShiftKeyDown;
}

bool Framework::VirtualKeysTypes
	::IsMouseDown() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsLeftMouseDown || m_IsMiddleMouseDown || m_IsRightMouseDown;
}

void Framework::VirtualKeysTypes
	::SetModifiers(int modifiers) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_IsShiftKeyDown = (GlutApplicationTrait::KeyboardModifiers::sm_KeyShift == modifiers);
	m_IsCtrlKeyDown = (GlutApplicationTrait::KeyboardModifiers::sm_KeyControl == modifiers);
}

void Framework::VirtualKeysTypes
	::SetMouseButtonsTypes(int button)  noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_IsLeftMouseDown = (GlutApplicationTrait::MouseButtons::sm_MouseLeftButton == button);
	m_IsMiddleMouseDown = (GlutApplicationTrait::MouseButtons::sm_MouseMiddleButton == button);
	m_IsRightMouseDown = (GlutApplicationTrait::MouseButtons::sm_MouseRightButton == button);
}

void Framework::VirtualKeysTypes
	::ClearMouseButtonsTypes() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;	 

	m_IsLeftMouseDown = false;
	m_IsMiddleMouseDown = false;
	m_IsRightMouseDown = false;
}

void Framework::VirtualKeysTypes
	::ClearKeyDownTypes() noexcept
{
	m_IsShiftKeyDown = false;
	m_IsCtrlKeyDown = false;
}

