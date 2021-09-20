// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:47)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_INTERFACE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/WindowsProcess.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"

#include <memory>

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowMessageInterface
	{
	public:
		using ClassType = WindowMessageInterface;
		using HWnd = System::WindowsHWnd;
		using WParam = System::WindowsWParam;
		using LParam = System::WindowsLParam;
		using LResult = System::WindowsLResult;
		using FunctionPointer = LResult(ClassType::*) (HWnd hwnd, WParam wParam, LParam lParam);

	public:
		explicit WindowMessageInterface(int64_t delta) noexcept;
		virtual ~WindowMessageInterface() noexcept = default;
		WindowMessageInterface(const WindowMessageInterface&) noexcept = default;
		WindowMessageInterface& operator=(const WindowMessageInterface&) noexcept = default;
		WindowMessageInterface(WindowMessageInterface&&) noexcept = default;
		WindowMessageInterface& operator=(WindowMessageInterface&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate(const EnvironmentDirectory& environmentDirectory);
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();

		virtual LResult CreateMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult SizeMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult CloseMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult MoveMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult CharMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult KeyUpMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult LeftButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult LeftButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult MiddleButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult MiddleButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult RightButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult RightButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult MouseMoveMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult MouseWheelMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult DestroyMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult PaintMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual LResult EraseBackgroundMessage(HWnd hwnd, WParam wParam, LParam lParam);
		virtual void Display(HWnd hwnd, int64_t timeDelta);
		virtual int GetTerminateKey() const noexcept;

		HWnd GetHwnd() const noexcept;
		void SetMainWindow(HWnd hwnd);

		int64_t GetDelta() const noexcept;

	private:
		HWnd m_Hwnd{ nullptr };
		int64_t m_Delta{ 0 };
	};

	using WindowMessageInterfaceSharedPtr = std::shared_ptr<WindowMessageInterface>;
	using ConstWindowMessageInterfaceSharedPtr = std::shared_ptr<const WindowMessageInterface>;
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_INTERFACE_H
