// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:14)

#include "Framework/FrameworkExport.h"

#include "VirtualKeysTypes.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/ApplicationTrait.h"

#ifdef _WIN32
#include <gl/freeglut.h>
#endif // _WIN32

#if defined(_MSC_VER)
  #pragma warning(disable:4505)
#endif // _MSC_VER

Framework::VirtualKeysTypes
	::VirtualKeysTypes(WParam wParam)
	:m_IsCtrlKeyDown((wParam & WindowApplicationTrait::MouseModifiers::sm_ModifierControl) != 0),
	 m_IsLeftMouseDown((wParam & WindowApplicationTrait::MouseModifiers::sm_ModifierLeftButton) != 0),
	 m_IsMiddleMouseDown((wParam & WindowApplicationTrait::MouseModifiers::sm_ModifierMiddleButton) != 0),
	 m_IsRightMouseDown((wParam & WindowApplicationTrait::MouseModifiers::sm_ModifierRightButton) != 0),
	 m_IsShiftKeyDown((wParam & WindowApplicationTrait::MouseModifiers::sm_ModifierShift) != 0)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::VirtualKeysTypes
	::VirtualKeysTypes()
    :m_IsCtrlKeyDown(false),
	 m_IsLeftMouseDown(false),
	 m_IsMiddleMouseDown(false),
	 m_IsRightMouseDown(false),
	 m_IsShiftKeyDown(false)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,VirtualKeysTypes)

bool Framework::VirtualKeysTypes
    ::IsCtrlKeyDown() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsCtrlKeyDown;
}

bool Framework::VirtualKeysTypes
	::IsLeftMouseDown() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsLeftMouseDown;
}

bool Framework::VirtualKeysTypes
	::IsMiddleMouseDown() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsMiddleMouseDown;
}

bool Framework::VirtualKeysTypes
	::IsRightMouseDown() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsRightMouseDown;
}

bool Framework::VirtualKeysTypes
	::IsShiftKeyDown() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsShiftKeyDown;
}

bool Framework::VirtualKeysTypes
	::IsMouseDown() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_IsLeftMouseDown || m_IsMiddleMouseDown || m_IsRightMouseDown;
}

void Framework::VirtualKeysTypes
    ::SetModifiers( int modifiers )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_IsShiftKeyDown =  GlutApplicationTrait::KeyboardModifiers::sm_KeyShift ==
						modifiers;
	m_IsCtrlKeyDown =  GlutApplicationTrait::KeyboardModifiers::sm_KeyControl ==
					   modifiers;
}

void Framework::VirtualKeysTypes
	::SetMouseButtonsTypes(int button)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_IsLeftMouseDown =  GlutApplicationTrait::MouseButtons::sm_MouseLeftButton ==
						 button;

	m_IsMiddleMouseDown = GlutApplicationTrait::MouseButtons::sm_MouseMiddleButton ==
		                  button;

	m_IsRightMouseDown =  GlutApplicationTrait::MouseButtons::sm_MouseRightButton ==
		                  button;
}

void Framework::VirtualKeysTypes
	::ClearMouseButtonsTypes()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_IsLeftMouseDown = false;
	m_IsMiddleMouseDown = false;
	m_IsRightMouseDown = false;
}

