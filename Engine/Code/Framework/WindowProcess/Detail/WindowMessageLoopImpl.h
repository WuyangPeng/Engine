// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:36)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Time/CustomTime.h"
#include "System/Windows/WindowsCreate.h"
#include "System/Windows/WindowsProcess.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowMessageLoopImpl
	{
	public:
		using ClassType = WindowMessageLoopImpl;
		using HWnd = System::WindowsHWnd;
		using WParam = System::WindowsWParam;
		using DisplayFunction = System::DisplayFunction;

	public:
		explicit WindowMessageLoopImpl(DisplayFunction function) noexcept;

		CLASS_INVARIANT_DECLARE;

		WParam EnterMessageLoop(HWnd hwnd);

	private:
		using WindowMsg = System::WindowsMsg;
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
