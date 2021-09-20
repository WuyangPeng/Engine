// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 10:53)

#include "Framework/FrameworkExport.h"

#include "WindowMessageInterface.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

Framework::WindowMessageInterface
	::WindowMessageInterface(int64_t delta) noexcept
	:m_Hwnd{ nullptr }, m_Delta{ delta }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageInterface)

bool Framework::WindowMessageInterface ::PreCreate([[maybe_unused]] const EnvironmentDirectory& environmentDirectory)
{
	FRAMEWORK_CLASS_IS_VALID_9;

 

	CoreTools::DisableNoexcept();

	return true;
}

bool Framework::WindowMessageInterface
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();

	return true;
}

void Framework::WindowMessageInterface
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();
}

void Framework::WindowMessageInterface
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	CoreTools::DisableNoexcept();
}
 
System::WindowsLResult Framework::WindowMessageInterface
	::CreateMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	// ֻ�����һ���������ڵ�HWnd
	if (m_Hwnd == nullptr)
	{
		m_Hwnd = hwnd;
	}

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::Create, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::SizeMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::Size, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::CloseMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::Close, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::MoveMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::Move, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::CharMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::Char, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::KeyDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::KeyUpMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::KeyUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::LeftButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::LButtonDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::LeftButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::LButtonUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::MiddleButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::MButtonDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::MiddleButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::MButtonUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::RightButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::RButtonDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::RightButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::RButtonUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::MouseMoveMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::MouseMove, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::MouseWheelMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::MouseWheel, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::DestroyMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	// ֻ�յ�����������ʱ���˳�����
	if (hwnd == m_Hwnd)
	{
		m_Hwnd = nullptr;

		return System::PostSystemQuitMessage();
	}
	else
	{
		return System::DefSystemWindowProc(hwnd, System::WindowsMessages::Destroy, wParam, lParam);
	}
}

System::WindowsLResult Framework::WindowMessageInterface
	::PaintMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::Paint, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface
	::EraseBackgroundMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	CoreTools::DisableNoexcept();

	return System::DefSystemWindowProc(hwnd, System::WindowsMessages::EraseBkgnd, wParam, lParam);
}

void Framework::WindowMessageInterface ::Display([[maybe_unused]] HWnd hwnd, [[maybe_unused]] int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

 

	CoreTools::DisableNoexcept();
}

int Framework::WindowMessageInterface
	::GetTerminateKey() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return WindowApplicationTrait::KeyIdentifiers::sm_KeyTerminate;
}

System::WindowsHWnd Framework::WindowMessageInterface
	::GetHwnd() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Hwnd;
}

void Framework::WindowMessageInterface
	::SetMainWindow(HWnd hwnd)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_2(m_Hwnd != nullptr, "���ڻ�δ������");

	// �޸�������
	m_Hwnd = hwnd;

	CoreTools::DisableNoexcept();
}

int64_t Framework::WindowMessageInterface
	::GetDelta() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Delta;
}

