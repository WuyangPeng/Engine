// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.2 (2020/06/06 20:57)

#include "Framework/FrameworkExport.h"

#include "WindowProcessManagerImpl.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h" 
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::make_shared;

CORE_TOOLS_MUTEX_EXTERN(Framework);

Framework::WindowMessageInterfaceSharedPtr Framework::WindowProcessManagerImpl
	::sm_WindowMessage{ };

int Framework::WindowProcessManagerImpl
	::sm_WindowMessageIndex{ };

// static
// private
Framework::WindowProcessManagerImpl::ClassNameContainerSharedPtr Framework::WindowProcessManagerImpl
	::GetClassNameContainer()
{
	static ClassNameContainerSharedPtr classNameContainer{ };

	if (!classNameContainer)
	{
		SINGLETON_MUTEX_ENTER_GLOBAL(Framework);

		if (!classNameContainer)
		{
			classNameContainer = make_shared<ClassNameContainer>();
		}
	}

	return classNameContainer;
}

// static
// private
Framework::WindowProcessManagerImpl::MessageFunctionPointerContainerSharedPtr Framework::WindowProcessManagerImpl
	::GetMessageFunctionPointer()
{
	static MessageFunctionPointerContainerSharedPtr functionPointer{ };

	if (!functionPointer)
	{
		SINGLETON_MUTEX_ENTER_GLOBAL(Framework);

		if (!functionPointer)
		{
			MessageFunctionPointerContainer messageFunctionPointerContainer{ { System::WindowsMessages::Paint, &WindowMessageInterface::PaintMessage },
																			 { System::WindowsMessages::EraseBkgnd,&WindowMessageInterface::EraseBackgroundMessage },
																			 { System::WindowsMessages::Move, &WindowMessageInterface::MoveMessage },
																			 { System::WindowsMessages::Size, &WindowMessageInterface::SizeMessage },
																			 { System::WindowsMessages::Char, &WindowMessageInterface::CharMessage },
																			 { System::WindowsMessages::KeyDown, &WindowMessageInterface::KeyDownMessage },
																			 { System::WindowsMessages::KeyUp, &WindowMessageInterface::KeyUpMessage },
																			 { System::WindowsMessages::LButtonDown, &WindowMessageInterface::LeftButtonDownMessage },
																			 { System::WindowsMessages::LButtonUp, &WindowMessageInterface::LeftButtonUpMessage },
																			 { System::WindowsMessages::MButtonDown, &WindowMessageInterface::MiddleButtonDownMessage },
																			 { System::WindowsMessages::MButtonUp, &WindowMessageInterface::MiddleButtonUpMessage },
																			 { System::WindowsMessages::RButtonDown, &WindowMessageInterface::RightButtonDownMessage },
																			 { System::WindowsMessages::RButtonUp, &WindowMessageInterface::RightButtonUpMessage },
																			 { System::WindowsMessages::MouseMove, &WindowMessageInterface::MouseMoveMessage },
																			 { System::WindowsMessages::MouseWheel, &WindowMessageInterface::MouseWheelMessage },
																			 { System::WindowsMessages::Create, &WindowMessageInterface::CreateMessage },
																			 { System::WindowsMessages::Close, &WindowMessageInterface::CloseMessage } ,
																			 { System::WindowsMessages::Destroy, &WindowMessageInterface::DestroyMessage } };

			functionPointer = make_shared<MessageFunctionPointerContainer>(messageFunctionPointerContainer);
		}

	}

	return functionPointer;
}

// static
// private
Framework::WindowProcessManagerImpl::WindowMessageContainerSharedPtr Framework::WindowProcessManagerImpl
	::GetWindowMessageContainer()
{
	static WindowMessageContainerSharedPtr windowMessageContainer{ };

	if (!windowMessageContainer)
	{
		SINGLETON_MUTEX_ENTER_GLOBAL(Framework);

		if (!windowMessageContainer)
		{
			windowMessageContainer = make_shared<WindowMessageContainer>();
		}
	}

	return windowMessageContainer;
}


CLASS_INVARIANT_STUB_DEFINE(Framework, WindowProcessManagerImpl)

// static
Framework::WindowProcessManagerImpl::WindowProcess Framework::WindowProcessManagerImpl
	::GetProcess() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return WindowProc;
}

// static
Framework::WindowProcessManagerImpl::DisplayFunction Framework::WindowProcessManagerImpl
	::GetFunction() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return Display;
}

// static
bool Framework::WindowProcessManagerImpl
	::IsClassNameExist(const String& className)
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	auto classNameContainer = GetClassNameContainer();

	const auto iter = classNameContainer->find(className);
	
	if(iter != classNameContainer->cend())
		return true;	
		
	return false;
}

// static
bool Framework::WindowProcessManagerImpl
	::SetNewClassName(const String& className)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	auto classNameContainer = GetClassNameContainer();

	if (classNameContainer->insert(className).second)
		return true;
	else
		return false;
}

Framework::ConstWindowMessageInterfaceSharedPtr Framework::WindowProcessManagerImpl
	::GetWindowMessageInterface() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return sm_WindowMessage;
}

void Framework::WindowProcessManagerImpl
	::SetWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (sm_WindowMessage != nullptr)
	{
		auto windowMessageContainer = GetWindowMessageContainer();

		windowMessageContainer->insert({ sm_WindowMessageIndex++,sm_WindowMessage });
	}

	sm_WindowMessage = windowMessage;	
}

void Framework::WindowProcessManagerImpl
	::ClearWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (sm_WindowMessage == windowMessage)
	{
		ResetMainWindowMessage();
	}
	else 
	{
		ClearWindowMessageContainer(windowMessage);
	}
}

void Framework::WindowProcessManagerImpl
	::ResetMainWindowMessage()
{
	sm_WindowMessage.reset();

	auto windowMessageContainer = GetWindowMessageContainer();	

	for (auto iter = windowMessageContainer->begin(); iter != windowMessageContainer->end(); ++iter)
	{
		auto nextWindowMessage = iter->second.lock();
		if (nextWindowMessage != nullptr)
		{
			sm_WindowMessage = nextWindowMessage;
			windowMessageContainer->erase(iter);
			break;
		}
	}
}

void Framework::WindowProcessManagerImpl
	::ClearWindowMessageContainer(const WindowMessageInterfaceSharedPtr& windowMessage)
{
	auto windowMessageContainer = GetWindowMessageContainer();

	for (auto iter = windowMessageContainer->begin(); iter != windowMessageContainer->end();)
	{
		auto nextWindowMessage = iter->second.lock();
		if (nextWindowMessage == nullptr || nextWindowMessage == windowMessage)
		{
			windowMessageContainer->erase(iter++);
		}
		else
		{
			++iter;
		}
	}
}

bool Framework::WindowProcessManagerImpl
	::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (sm_WindowMessage)
	{
		return sm_WindowMessage->PreCreate(environmentDirectory);
	}
	else
	{
		return false;
	}
}

bool Framework::WindowProcessManagerImpl
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (sm_WindowMessage)
	{
		return sm_WindowMessage->Initialize();
	}
	else
	{
		return false;
	}
}

void Framework::WindowProcessManagerImpl
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (sm_WindowMessage)
	{
		return sm_WindowMessage->PreIdle();
	}
}

void Framework::WindowProcessManagerImpl
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (sm_WindowMessage)
	{
		sm_WindowMessage->Terminate();
	}
}

void Framework::WindowProcessManagerImpl
	::SetMainWindowHwnd(HWnd hwnd)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (sm_WindowMessage)
	{
		sm_WindowMessage->SetMainWindow(hwnd);
	}
}

Framework::WindowProcessManagerImpl::HWnd Framework::WindowProcessManagerImpl
	::GetMainWindowHwnd() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return sm_WindowMessage->GetHwnd();
}

// static
// private
Framework::WindowProcessManagerImpl::LResult SYSTEM_CALL_BACK Framework::WindowProcessManagerImpl
	::WindowProc(HWnd hwnd, UInt message, WParam wParam, LParam lParam)
{
	EXCEPTION_TRY
	{
		auto messageFunctionPointer = GetMessageFunctionPointer();	

		const auto flag = System::UnderlyingCastEnum<System::WindowsMessages>(message);

		const auto iter = messageFunctionPointer->find(flag);

		if (sm_WindowMessage && iter != messageFunctionPointer->cend())
		{
			return ((*sm_WindowMessage).*(iter->second))(hwnd, wParam, lParam);
		}	

		return System::DefSystemWindowProc(hwnd, flag, wParam, lParam);
	}
	EXCEPTION_ALL_CATCH(Framework)

	return 0;
}

// static
// private
void Framework::WindowProcessManagerImpl
	::Display(HWnd hwnd, int64_t timeDelta)
{
	if (sm_WindowMessage)
	{
		sm_WindowMessage->Display(hwnd, timeDelta);
	}
}

Framework::WindowProcessManagerImpl::WindowProcessManagerImpl(MAYBE_UNUSED int count) noexcept
{
}

