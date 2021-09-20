// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 21:24)

#ifndef FRAMEWORK_WINDOWS_API_FRAME_BUILD_H
#define FRAMEWORK_WINDOWS_API_FRAME_BUILD_H

#include "Framework/WindowCreate/WindowCreate.h"
#include "Framework/Application/ApplicationFwd.h"
#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowRegister/WindowRegister.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

namespace Framework
{
	template <typename Process>
	class WindowsAPIFrameBuild
	{
	public:
		using ClassType = WindowsAPIFrameBuild<Process>;
		using String = System::String;
		using HWnd = System::WindowsHWnd; 
		using HInstance = System::WindowsHInstance;

	public:
		explicit WindowsAPIFrameBuild(HInstance instance, const char* commandLine, const WindowApplicationInformation& information,
									  const EnvironmentDirectory& environmentDirectory);
		virtual ~WindowsAPIFrameBuild() noexcept = default;
		WindowsAPIFrameBuild(const WindowsAPIFrameBuild& rhs) noexcept = delete;
		WindowsAPIFrameBuild& operator=(const WindowsAPIFrameBuild& rhs) noexcept = delete;
		WindowsAPIFrameBuild(WindowsAPIFrameBuild&& rhs) noexcept;
		WindowsAPIFrameBuild& operator=(WindowsAPIFrameBuild&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		HWnd GetHwnd() const noexcept;
		HInstance GetHInstance() const noexcept;

		int EnterMessageLoop();

	private:
		using WindowRegister = WindowRegisterHandle<Process>;

	private:
		WindowRegister m_WindowRegister;
		WindowCreateHandle m_WindowCreate;
		WindowMessageLoop m_WindowMessageLoop;
	};
}

#endif // FRAMEWORK_WINDOWS_API_FRAME_BUILD_H