// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:47)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
FRAMEWORK_NON_COPY_EXPORT_IMPL(WindowMessageLoopImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowMessageLoop
	{
	public:
		NON_COPY_TYPE_DECLARE(WindowMessageLoop);
		using HWnd = System::WindowsHWnd;
		using WParam = System::WindowsWParam;
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
                PackageType impl;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_LOOP_H
