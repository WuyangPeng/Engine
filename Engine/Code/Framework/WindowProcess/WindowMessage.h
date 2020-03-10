// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:54)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H

#include "WindowMessageInterface.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"

namespace Framework
{
	template <typename MiddleLayer>
	class WindowMessage : public WindowMessageInterface
	{
	public:	
		using MiddleLayerType = MiddleLayer;
		using ClassType = WindowMessage<MiddleLayerType>;
	    using ParentType = WindowMessageInterface;
		
	public:
		WindowMessage();		
		virtual ~WindowMessage();
	
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;	

		virtual LResult CreateMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult SizeMessage(HWnd hwnd,WParam wParam,LParam lParam);	
		virtual LResult CloseMessage(HWnd hwnd,WParam wParam,LParam lParam);	
		virtual LResult CharMessage(HWnd hwnd,WParam wParam,LParam lParam);	
		virtual LResult MoveMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult KeyDownMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult KeyUpMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult LeftButtonDownMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult LeftButtonUpMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult MiddleButtonDownMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult MiddleButtonUpMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult RightButtonDownMessage(HWnd hwnd,WParam wParam,LParam lParam);	
		virtual LResult RightButtonUpMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult MouseMoveMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult MouseWheelMessage(HWnd hwnd,WParam wParam,LParam lParam);	
		virtual LResult DestroyMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult PaintMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult EraseBackgroundMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual void Display(HWnd hwnd,int64_t timeDelta);

	private:
		using MiddleLayerTypePtr = MiddleLayerInterfaceSmartPointer;

	private:
		void DoCloseMessage(HWnd hwnd) const;	
		System::String GetWindowsClassName(HWnd hwnd) const;	
		const WindowPoint GetCursorPosition( HWnd hwnd ) const; 
		bool IsSpecialKey(int virtKey) const;

	private:
		MiddleLayerTypePtr m_MiddleLayerPtr;
		int64_t m_TimeDelta;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_H
