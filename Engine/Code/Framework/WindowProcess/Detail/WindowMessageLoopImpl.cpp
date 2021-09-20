// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 10:50)

#include "Framework/FrameworkExport.h"

#include "WindowMessageLoopImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
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

System::WindowsWParam Framework::WindowMessageLoopImpl
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
System::WindowsWParam Framework::WindowMessageLoopImpl
	::EnterOldMessageLoop() noexcept
{
	while (System::GetSystemMessage(&m_Msg))
	{
            [[maybe_unused]] const auto result1 = System::TranslateSystemMessage(&m_Msg);
            [[maybe_unused]] const auto result2 = System::DispatchSystemMessage(&m_Msg);
	}

	return m_Msg.wParam;
}

// private
System::WindowsWParam Framework::WindowMessageLoopImpl
	::EnterNewMessageLoop(HWnd hwnd)
{
	// ������Ϣѭ����
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
	if (System::UnderlyingCastEnum<System::WindowsMessages>(m_Msg.message) == System::WindowsMessages::Quit)
	{
		return false;
	}

	System::WindowsHAccel accel{ nullptr };
	if (!System::SystemTranslateAccelerator(hwnd, accel, &m_Msg))
	{
            [[maybe_unused]] const auto result1 = System::TranslateSystemMessage(&m_Msg);
            [[maybe_unused]] const auto result2 = System::DispatchSystemMessage(&m_Msg);
	}

	return true;
}

// private
void Framework::WindowMessageLoopImpl
	::Idle(HWnd hwnd)
{
	FRAMEWORK_ASSERTION_0(m_Function != nullptr, "���к���ָ��Ϊ�գ�");

	const auto timeDelta = m_LastTime.GetThisElapsedMillisecondTime();

	if (m_Function)
	{
		m_Function(hwnd, timeDelta);
	}
}
