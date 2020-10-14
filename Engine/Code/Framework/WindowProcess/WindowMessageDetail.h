// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 09:48)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_DETAIL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_DETAIL_H

#include "WindowMessage.h"
#include "VirtualKeysTypes.h"
#include "Flags/MouseTypes.h"
#include "System/Helper/EnumCast.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Window/WindowUser.h"
#include "System/Window/WindowCreate.h"
#include "System/Window/Flags/WindowMessagesFlags.h"
#include "System/Window/Flags/WindowDisplayFlags.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"

template <typename MiddleLayer>
Framework::WindowMessage<MiddleLayer>
	::WindowMessage(int64_t delta)
	:ParentType{ delta }, m_MiddleLayer{ std::make_shared<MiddleLayerType>(MiddleLayerPlatform::Windows) }, m_Accumulative{ delta }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_MiddleLayer != nullptr && 0 <= m_Accumulative)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>
	::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return m_MiddleLayer->PreCreate(environmentDirectory); 
}

template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	return m_MiddleLayer->Initialize();
}

template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayer->PreIdle();

	return ParentType::PreIdle();
}

template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayer->Terminate();

	return ParentType::Terminate();
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::CreateMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayer->Create();

	return ParentType::CreateMessage(hwnd, wParam, lParam);
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::SizeMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const WindowSize clientSize{ lParam };

	m_MiddleLayer->Resize(boost::numeric_cast<System::WindowDisplay>(wParam), clientSize);

	return ParentType::SizeMessage(hwnd, wParam, lParam);
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::CloseMessage(HWnd hwnd, [[maybe_unused]] WParam wParam, [[maybe_unused]] LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	DoCloseMessage(hwnd);

 

	return 0;
}

// private
template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>
	::DoCloseMessage(HWnd hwnd) const
{
	using namespace std::literals;

	auto className = GetWindowsClassName(hwnd);

	auto exitInformation = SYSTEM_TEXT("是否退出"s) + className + SYSTEM_TEXT("？"s);

	System::SystemValidateRect(hwnd);

	if (System::MessageBox(hwnd, exitInformation, className))
	{
		System::DestroySystemWindow(hwnd);
	}
}

// private
template <typename MiddleLayer>
System::String Framework::WindowMessage<MiddleLayer>
	::GetWindowsClassName(HWnd hwnd) const
{
	String name{ };

	if (System::GetWindowTextString(hwnd, name))
		return name;
	else
		return SYSTEM_TEXT("程序");
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::CharMessage(HWnd hwnd, WParam wParam, [[maybe_unused]] LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto key = boost::numeric_cast<int>(wParam);

	// 当Terminate键被按下时退出应用程序。
	if (key == GetTerminateKey())
	{
		System::SendSystemMessage(hwnd, System::WindowMessages::Close, 0, 0);
	}
	else
	{
		// 获取客户端光标的位置。
		const auto point = GetCursorPosition(hwnd);

		m_MiddleLayer->KeyDown(key, point);
	}
 

	return 0;
}

// private
template <typename MiddleLayer>
const Framework::WindowPoint Framework::WindowMessage<MiddleLayer>
	::GetCursorPosition(HWnd hwnd) const noexcept
{
	System::WindowPoint point{ };
	System::GetCursorClientPos(hwnd, point);

	return WindowPoint{ point };
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::MoveMessage([[maybe_unused]] HWnd hwnd, [[maybe_unused]] WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayer->Move(WindowPoint{ lParam });

 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::KeyDownMessage(HWnd hwnd, WParam wParam, [[maybe_unused]] LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto virtualKey = boost::numeric_cast<int>(wParam);

	// 获取客户端光标的位置。
	const auto point = GetCursorPosition(hwnd);

	if (IsSpecialKey(virtualKey))
	{
		m_MiddleLayer->SpecialKeyDown(virtualKey, point);
	}	

	// KeyDown在CharMessage上监听。

 

	return 0;
}

// private
template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>
	::IsSpecialKey(int virtualKey) const noexcept
{
	auto windowsKeyCodes = System::UnderlyingCastEnum<System::WindowsKeyCodes>(virtualKey);

	if ((System::WindowsKeyCodes::F1 <= windowsKeyCodes) && (windowsKeyCodes <= System::WindowsKeyCodes::F12) ||
		(System::WindowsKeyCodes::Prior <= windowsKeyCodes) && (windowsKeyCodes <= System::WindowsKeyCodes::Down) ||
		(windowsKeyCodes == System::WindowsKeyCodes::Insert) ||
		(windowsKeyCodes == System::WindowsKeyCodes::Delete) ||
		(windowsKeyCodes == System::WindowsKeyCodes::Shift) ||
		(windowsKeyCodes == System::WindowsKeyCodes::Control))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::KeyUpMessage(HWnd hwnd, WParam wParam, [[maybe_unused]] LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	auto virtualKey = boost::numeric_cast<int>(wParam);

	// 获取客户端光标的位置。
	const auto point = GetCursorPosition(hwnd);

	if (IsSpecialKey(virtualKey))
	{
		m_MiddleLayer->SpecialKeyUp(virtualKey, point);
	}
	else
	{
		m_MiddleLayer->KeyUp(virtualKey, point);
	}
 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::LeftButtonDownMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const WindowPoint windowPoint{ lParam };
	const VirtualKeysTypes virtualKeys{ wParam };

	m_MiddleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, windowPoint, virtualKeys);
 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::LeftButtonUpMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const WindowPoint windowPoint{ lParam };
	const VirtualKeysTypes virtualKeys{ wParam };	

	m_MiddleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseUp, windowPoint, virtualKeys);

 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::MiddleButtonDownMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const WindowPoint windowPoint{ lParam };
	const VirtualKeysTypes virtualKeys{ wParam };

	m_MiddleLayer->MouseClick(MouseButtonsTypes::MiddleButton, MouseStateTypes::MouseDown, windowPoint, virtualKeys);

 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::MiddleButtonUpMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const WindowPoint windowPoint{ lParam };
	const VirtualKeysTypes virtualKeys{ wParam };

	m_MiddleLayer->MouseClick(MouseButtonsTypes::MiddleButton, MouseStateTypes::MouseUp, windowPoint, virtualKeys);

 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::RightButtonDownMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const WindowPoint windowPoint{ lParam };
	const VirtualKeysTypes virtualKeys{ wParam };

	m_MiddleLayer->MouseClick(MouseButtonsTypes::RightButton, MouseStateTypes::MouseDown, windowPoint, virtualKeys);

	 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::RightButtonUpMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const WindowPoint windowPoint{ lParam };
	const VirtualKeysTypes virtualKeys{ wParam };

	m_MiddleLayer->MouseClick(MouseButtonsTypes::RightButton, MouseStateTypes::MouseUp, windowPoint, virtualKeys);

	 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::MouseMoveMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const WindowPoint windowPoint{ lParam };
	const VirtualKeysTypes virtualKeys{ wParam };

	if (virtualKeys.IsMouseDown())
	{
		m_MiddleLayer->Motion(windowPoint, virtualKeys);
	}
	else
	{
		m_MiddleLayer->PassiveMotion(windowPoint);
	}

 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::MouseWheelMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	const WindowPoint windowPoint{ lParam };
	const VirtualKeysTypes virtualKeys{ boost::numeric_cast<WParam>(System::GetLowWord(wParam)) };

	m_MiddleLayer->MouseWheel(System::GetHighWord(wParam) / System::EnumCastUnderlying(System::WindowMessages::MouseWheel), windowPoint, virtualKeys);

 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>
	::DestroyMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayer->Destroy();

	return ParentType::DestroyMessage(hwnd, wParam, lParam);
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::PaintMessage([[maybe_unused]] HWnd hwnd, [[maybe_unused]] WParam wParam, [[maybe_unused]] LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_MiddleLayer->Paint();	 

 

	return 0;
}

template <typename MiddleLayer>
System::WindowLResult Framework::WindowMessage<MiddleLayer>::EraseBackgroundMessage([[maybe_unused]] HWnd hwnd, [[maybe_unused]] WParam wParam, [[maybe_unused]] LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	CoreTools::DisableNoexcept();

	// 这告诉Windows不擦除背景（由OpenGL或DirectX来完成）。
 

	return 1;
}

template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>
	::Display(HWnd hwnd, int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_1;

	m_Accumulative += timeDelta;

	if (GetDelta() <= m_Accumulative)
	{
		m_MiddleLayer->Idle(m_Accumulative);		

		m_Accumulative = 0;
	}

	return ParentType::Display(hwnd, timeDelta);
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_DETAIL_H
