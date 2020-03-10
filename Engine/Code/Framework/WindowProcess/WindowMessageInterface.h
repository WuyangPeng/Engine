// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:54)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_INTERFACE_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "System/Window/WindowProcess.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"
#include "CoreTools/MemoryTools/FirstSubclassSmartPointer.h"

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowMessageInterface
	{
	public:	
		using ClassType = WindowMessageInterface;
		using LResult = System::WindowLResult;
		using HWnd = System::WindowHWnd;
		using WParam = System::WindowWParam;
		using LParam = System::WindowLParam;
		using FunctionPointer = LResult (ClassType::*) (HWnd hwnd,WParam wParam,LParam lParam);

	public:
		WindowMessageInterface();		
		virtual ~WindowMessageInterface();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();

		virtual LResult CreateMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult SizeMessage(HWnd hwnd,WParam wParam,LParam lParam);	
		virtual LResult CloseMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult MoveMessage(HWnd hwnd,WParam wParam,LParam lParam);
		virtual LResult CharMessage(HWnd hwnd,WParam wParam,LParam lParam);	
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
		virtual uint8_t GetTerminateKey() const;

        HWnd GetHwnd() const;
		void SetMainWindow(HWnd hwnd);

    private:
        HWnd m_Hwnd;
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(First, WindowMessageInterface);
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_INTERFACE_H
