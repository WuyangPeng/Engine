// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:47)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Window/WindowProcess.h"

FRAMEWORK_EXPORT_SHARED_PTR(WindowMessageLoopImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowMessageLoop
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(WindowMessageLoop);
		using HWnd = System::WindowHWnd;
		using WParam = System::WindowWParam;
		using Display = System::DisplayFunction;

	public:
		explicit WindowMessageLoop(Display function);
		~WindowMessageLoop() noexcept = default;
		WindowMessageLoop(const WindowMessageLoop&) noexcept = delete;
		WindowMessageLoop& operator=(const WindowMessageLoop&) noexcept = delete;
		WindowMessageLoop(WindowMessageLoop&& rhs) noexcept;
		WindowMessageLoop& operator=(WindowMessageLoop&& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

		WParam EnterMessageLoop(HWnd hwnd);

	private:
		IMPL_TYPE_DECLARE(WindowMessageLoop);
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H
