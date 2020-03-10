// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.4 (2019/08/01 10:45)

#include "Framework/FrameworkExport.h"

#include "WindowPictorialImpl.h"
#include "Framework/WindowRegister/WindowHBrush.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowPictorialImpl
	::WindowPictorialImpl(System::WindowBrushTypes background)
	:m_WindowsHIcon(),
	 m_WindowsHCursor(),
	 m_WindowsHBrushPtr(CreateWindowsHBrushPtr(background))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl
	::WindowPictorialImpl(const System::TChar* icon,const System::TChar* cursor, System::WindowBrushTypes background)
	:m_WindowsHIcon(icon),
	 m_WindowsHCursor(cursor),
	 m_WindowsHBrushPtr(CreateWindowsHBrushPtr(background))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl
	::WindowPictorialImpl(HInstance hInstance,int icon, int cursor,System::WindowBrushTypes background)
	:m_WindowsHIcon(hInstance,icon),
	 m_WindowsHCursor(hInstance,cursor),
	 m_WindowsHBrushPtr(CreateWindowsHBrushPtr(background))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl
	::WindowPictorialImpl(HInstance hInstance,int icon, const System::TChar* cursor,System::WindowBrushTypes background)
	:m_WindowsHIcon(hInstance,icon),
	 m_WindowsHCursor(cursor),
	 m_WindowsHBrushPtr(CreateWindowsHBrushPtr(background))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowPictorialImpl
	::WindowPictorialImpl(HInstance hInstance,const System::TChar* icon, int cursor,System::WindowBrushTypes background)
	:m_WindowsHIcon(icon),
	 m_WindowsHCursor(hInstance,cursor),
	 m_WindowsHBrushPtr(CreateWindowsHBrushPtr(background))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// static
Framework::WindowPictorialImpl::WindowHBrushPtr Framework::WindowPictorialImpl
	::CreateWindowsHBrushPtr(System::WindowBrushTypes background)
{
	if(background != System::WindowBrushTypes::Null)
		return WindowHBrushPtr(new WindowHBrush(background));
	else
		return WindowHBrushPtr();
}

 
CLASS_INVARIANT_STUB_DEFINE(Framework,WindowPictorialImpl)
 

System::WindowHIcon Framework::WindowPictorialImpl
    ::GetHIcon() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowsHIcon.GetHIcon();
}

System::WindowHCursor Framework::WindowPictorialImpl
	::GetHCursor() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowsHCursor.GetHCursor();
}

System::WindowHBrush Framework::WindowPictorialImpl
	::GetHBrush() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	if(m_WindowsHBrushPtr != nullptr &&  m_WindowsHBrushPtr != WindowHBrushPtr())
		return m_WindowsHBrushPtr->GetHBrush();
	else
		return nullptr;
}

 
