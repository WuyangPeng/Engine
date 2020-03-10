// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 09:50)

// 窗口过程类的实现
#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_DETAIL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_DETAIL_H

#include "WindowProcessHandle.h"
#include "WindowProcessManager.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename WindowMessage>
Framework::WindowProcessHandle<WindowMessage>
	::WindowProcessHandle()
{
	WindowMessageInterfaceSmartPointer ptr(NEW0 MessageType);

	WINDOW_PROCESS_MANAGER_SINGLETON.SetWindowMessage(ptr);

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename WindowMessage>
Framework::WindowProcessHandle<WindowMessage>
	::~WindowProcessHandle()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;

	WINDOW_PROCESS_MANAGER_SINGLETON.ClearWindowMessage();	
}

#ifdef OPEN_CLASS_INVARIANT
template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>
	::IsValid() const noexcept  
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename WindowMessage>
System::WindowProc Framework::WindowProcessHandle<WindowMessage>
	::GetProcess() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return WINDOW_PROCESS_MANAGER_SINGLETON.GetProcess();
}

template <typename WindowMessage>
System::DisplayPtr 
	Framework::WindowProcessHandle<WindowMessage>
	::GetFunction() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return WINDOW_PROCESS_MANAGER_SINGLETON.GetFunction();
}

template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return WINDOW_PROCESS_MANAGER_SINGLETON.PreCreate();
}

template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return WINDOW_PROCESS_MANAGER_SINGLETON.Initialize();
}

template <typename WindowMessage>
void Framework::WindowProcessHandle<WindowMessage>
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return WINDOW_PROCESS_MANAGER_SINGLETON.PreIdle();
}


template <typename WindowMessage>
void Framework::WindowProcessHandle<WindowMessage>
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return WINDOW_PROCESS_MANAGER_SINGLETON.Terminate();
}

template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>
	::IsClassNameExist( const System::String& className ) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return WINDOW_PROCESS_MANAGER_SINGLETON.IsClassNameExist(className);
}

template <typename WindowMessage>
bool Framework::WindowProcessHandle<WindowMessage>
	::SetNewClassName( const System::String& className )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return WINDOW_PROCESS_MANAGER_SINGLETON.SetNewClassName(className);
}

template <typename WindowMessage>
System::WindowHWnd Framework::WindowProcessHandle<WindowMessage>
	::GetMainWindowHwnd() const
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return WINDOW_PROCESS_MANAGER_SINGLETON.GetMainWindowHwnd();
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_PROCESS_DETAIL_H
