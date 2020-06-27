// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:47)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H

#include "WindowMessageInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/MiddleLayer/MiddleLayerInternalFwd.h"

namespace Framework
{
	template <typename MiddleLayer>
	class WindowMessage : public WindowMessageInterface
	{
	public:
		using MiddleLayerType = MiddleLayer;
		using ClassType = WindowMessage<MiddleLayerType>;
		using ParentType = WindowMessageInterface;
		using String = System::String;

	public:
		explicit WindowMessage(int64_t delta);

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		bool PreCreate(const EnvironmentDirectory& environmentDirectory) override;
		bool Initialize() override;
		void PreIdle() override;
		void Terminate() override;

		LResult CreateMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult SizeMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult CloseMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult CharMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult MoveMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult KeyUpMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult LeftButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult LeftButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult MiddleButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult MiddleButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult RightButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult RightButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult MouseMoveMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult MouseWheelMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult DestroyMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult PaintMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		LResult EraseBackgroundMessage(HWnd hwnd, WParam wParam, LParam lParam) override;
		void Display(HWnd hwnd, int64_t timeDelta) override;

	private:
		void DoCloseMessage(HWnd hwnd) const;
		String GetWindowsClassName(HWnd hwnd) const;
		const WindowPoint GetCursorPosition(HWnd hwnd) const noexcept;
		bool IsSpecialKey(int virtualKey) const noexcept;

	private:
		MiddleLayerInterfaceSharedPtr m_MiddleLayer;
		int64_t m_Accumulative;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H
