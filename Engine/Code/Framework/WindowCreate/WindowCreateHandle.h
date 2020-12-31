// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 09:45)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_H

#include "Framework/FrameworkDll.h"

#include "WindowCreateFwd.h"
#include "System/Window/Using/WindowUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(WindowCreateHandleImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE WindowCreateHandle 
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(WindowCreateHandle);
		using HWnd = System::WindowHWnd;

	public:
		WindowCreateHandle(const WindowInstanceParameter& windowInstanceParameter, const WindowCreateParameter& windowCreateParameter, const WindowSize& size);
		~WindowCreateHandle() noexcept = default;
		WindowCreateHandle(const WindowCreateHandle& rhs) noexcept = delete;
		WindowCreateHandle& operator=(const WindowCreateHandle& rhs) noexcept = delete;
		WindowCreateHandle(WindowCreateHandle&& rhs) noexcept;
		WindowCreateHandle& operator=(WindowCreateHandle&& rhs) noexcept;

		CLASS_INVARIANT_DECLARE;

		HWnd GetHwnd() const noexcept;

		void SetMainWindow();

	private:
		IMPL_TYPE_DECLARE(WindowCreateHandle);
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_CREATE_HANDLE_H