// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 10:50)

#include "Framework/FrameworkExport.h"

#include "WindowMessageLoopImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Window/Flags/WindowMessagesFlags.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using namespace std::literals;

Framework::WindowMessageLoopImpl
	::WindowMessageLoopImpl(DisplayFunction function) noexcept
	:m_Function{ function }, m_LastTime{ }, m_Msg{ }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageLoopImpl)

System::WindowWParam Framework::WindowMessageLoopImpl
	::EnterMessageLoop(HWnd hwnd)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (m_Function != nullptr)
	{
		return EnterNewMessageLoop(hwnd);
	}
	else
	{
		return EnterOldMessageLoop();
	}
}

// private
System::WindowWParam Framework::WindowMessageLoopImpl
	::EnterOldMessageLoop() noexcept
{
	while (System::GetSystemMessage(&m_Msg))
	{
		System::TranslateSystemMessage(&m_Msg);
		System::DispatchSystemMessage(&m_Msg);
	}

	return m_Msg.wParam;
}

// private
System::WindowWParam Framework::WindowMessageLoopImpl
	::EnterNewMessageLoop(HWnd hwnd)
{
	// 启动消息循环。
	auto applicationRunning = true;

	do
	{
		if (System::PeekSystemMessage(&m_Msg))
		{
			if (!ProcessingMessage(hwnd))
			{
				applicationRunning = false;
				continue;
			}
		}
		else
		{
			Idle(hwnd);
		}

	} while (applicationRunning);

	return m_Msg.wParam;
}

// private
bool Framework::WindowMessageLoopImpl
	::ProcessingMessage(HWnd hwnd) noexcept
{
	if (System::UnderlyingCastEnum<System::WindowMessages>(m_Msg.message) == System::WindowMessages::Quit)
	{
		return false;
	}

	System::WindowHAccel accel{ nullptr };
	if (!System::SystemTranslateAccelerator(hwnd, accel, &m_Msg))
	{
		System::TranslateSystemMessage(&m_Msg);
		System::DispatchSystemMessage(&m_Msg);
	}

	return true;
}

// private
void Framework::WindowMessageLoopImpl
	::Idle(HWnd hwnd)
{
	FRAMEWORK_ASSERTION_0(m_Function != nullptr, "空闲函数指针为空！");

	const auto timeDelta = m_LastTime.GetThisElapsedMillisecondTime();

	if (m_Function)
	{
		m_Function(hwnd, timeDelta);
	}
}
