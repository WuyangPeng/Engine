// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:36)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Time/CustomTime.h"
#include "System/Window/WindowCreate.h"
#include "System/Window/WindowProcess.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowMessageLoopImpl
	{
	public:
		using ClassType = WindowMessageLoopImpl;
		using HWnd = System::WindowHWnd;
		using WParam = System::WindowWParam;
		using DisplayFunction = System::DisplayFunction;

	public:
		explicit WindowMessageLoopImpl(DisplayFunction function) noexcept;

		CLASS_INVARIANT_DECLARE;

		WParam EnterMessageLoop(HWnd hwnd);

	private:
		using WindowMsg = System::WindowMsg;
		using CustomTime = CoreTools::CustomTime;

	private:
		WParam EnterOldMessageLoop() noexcept;
		WParam EnterNewMessageLoop(HWnd hwnd);
		bool ProcessingMessage(HWnd hwnd) noexcept;
		void Idle(HWnd hwnd);

	private:
		DisplayFunction m_Function;
		CustomTime m_LastTime;
		WindowMsg m_Msg;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H
