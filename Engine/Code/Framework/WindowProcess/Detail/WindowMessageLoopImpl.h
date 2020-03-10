// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:51)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Time/CustomTime.h"
#include "System/Window/WindowProcess.h"
#include "System/Window/WindowCreate.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowMessageLoopImpl
	{
	public:
		using ClassType = WindowMessageLoopImpl;
		using WParam = System::WindowWParam;
		using HWnd = System::WindowHWnd;

	public:
		explicit WindowMessageLoopImpl(System::DisplayPtr function);
		
		CLASS_INVARIANT_DECLARE;	

		WParam EnterMessageLoop(HWnd hwnd);

	private:
		using Msg = System::WindowMsg;
		using CustomTime = CoreTools::CustomTime;

	private:
		WParam EnterOldMessageLoop();
		WParam EnterNewMessageLoop(HWnd hwnd);
		bool ProcessingMessage(HWnd hwnd);
		void Idle(HWnd hwnd);

	private:
		System::DisplayPtr m_Function;
		CustomTime m_LastTime;
		Msg m_Msg;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H
