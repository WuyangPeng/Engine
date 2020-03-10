// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:39)

#include "System/SystemExport.h"

#include "WindowProcess.h"
#include "Flags/WindowProcessFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "System/SystemOutput/Data/MessageBoxFlagsData.h"
#include "System/SystemOutput/Flags/MessageBoxFlags.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"

bool System
	::GetSystemMessage(WindowMsg* msg, WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	const auto gotMessage = ::GetMessage(msg, hwnd, 0, 0);

	if (gotMessage != 0 && gotMessage != -1)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(msg);
	SYSTEM_UNUSED_ARG(hwnd);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::TranslateSystemMessage(const WindowMsg* msg) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::TranslateMessage(msg) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(msg);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::DispatchSystemMessage(const WindowMsg* msg) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::DispatchMessage(msg) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(msg);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::PeekSystemMessage(WindowMsg* msg, WindowHWnd hWnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::PeekMessage(msg, hWnd, 0, 0, EnumCastUnderlying(PeekMessageOptions::Remove)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(msg);
	SYSTEM_UNUSED_ARG(hWnd);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemTranslateAccelerator(WindowHWnd hwnd, WindowHAccel accel, WindowMsg* msg) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::TranslateAccelerator(hwnd, accel, msg) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(accel);
	SYSTEM_UNUSED_ARG(msg);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemValidateRect(WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ValidateRect(hwnd, nullptr) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowLResult System
	::DefSystemWindowProc(WindowHWnd hwnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::DefWindowProc(hwnd, EnumCastUnderlying(msg), wParam, lParam);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(msg);
	SYSTEM_UNUSED_ARG(wParam);
	SYSTEM_UNUSED_ARG(lParam);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

int System
	::PostSystemQuitMessage() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::PostQuitMessage(0);

	return 0;
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::MessageBox(WindowHWnd hwnd, const String& information, const String& title) noexcept
{
	constexpr MessageBoxFlagsData flagsData{ MessageBoxType::YesNo,MessageBoxIcon::Exclamation,MessageBoxDefault::Button2,
								             MessageBoxMode::ApplModal,MessageBoxMisc::NoMisc };

	if (MessageBoxSelection(hwnd, information.c_str(), title.c_str(), flagsData) == DialogBoxCommand::IDYes)
		return true;
	else
		return false;
}

bool System
	::DestroySystemWindow(WindowHWnd hwnd) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::DestroyWindow(hwnd) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SendSystemMessage(WindowHWnd hwnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SendMessage(hwnd, EnumCastUnderlying(msg), wParam, lParam) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(msg);
	SYSTEM_UNUSED_ARG(wParam);
	SYSTEM_UNUSED_ARG(lParam);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::GetCursorClientPos(WindowHWnd hwnd, WindowPoint& point) noexcept
{
	GetSystemCursorPos(point);
	SystemScreenToClient(hwnd, point);
}

void  System
	::SetCursorClientPos(WindowHWnd hWnd, const WindowPoint& point) noexcept
{
	WindowPoint clientPoint{ point };
	SystemClientToScreen(hWnd, clientPoint);
	SetSystemCursorPos(clientPoint);
}

bool System
	::SystemBeginPaint(WindowHWnd hwnd, WindowPaintStruct* ps) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::BeginPaint(hwnd, ps) != nullptr)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(ps);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemEndPaint(WindowHWnd hwnd, const WindowPaintStruct* ps) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::EndPaint(hwnd, ps) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(ps);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::String System
	::GetSystemCommandLine()
{
#ifdef SYSTEM_PLATFORM_WIN32
	const TChar* commandLine{ ::GetCommandLine() };
	if (commandLine != nullptr)
		return commandLine;
	else
		return SYSTEM_TEXT("");
#else // !SYSTEM_PLATFORM_WIN32
	return SYSTEM_TEXT("");
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::PostSystemMessage(WindowHWnd hwnd, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::PostMessage(hwnd, EnumCastUnderlying(msg), wParam, lParam)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(msg);
	SYSTEM_UNUSED_ARG(wParam);
	SYSTEM_UNUSED_ARG(lParam);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemCursorPos(WindowPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::GetCursorPos(&point)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(point);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemCursorPos(const WindowPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::SetCursorPos(point.x, point.y)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(point);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemClientToScreen(WindowHWnd hwnd, WindowPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::ClientToScreen(hwnd, &point)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(point);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemScreenToClient(WindowHWnd hwnd, WindowPoint& point) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::ScreenToClient(hwnd, &point)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hwnd);
	SYSTEM_UNUSED_ARG(point);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

