// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:48)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H

#include "MainFunctionHelperBase.h"
#include "MainFunctionHelperFwd.h"
#include "System/Window/Using/WindowUsing.h"
#include "Framework/Application/ApplicationFwd.h"
#include "Framework/WindowRegister/WindowPictorial.h"

namespace Framework
{
	template <template<typename> class Build, typename Process>
	class WindowMainFunctionHelper : public MainFunctionHelperBase
	{
	public:
		using ClassType = WindowMainFunctionHelper<Build, Process>;
		using ParentType = MainFunctionHelperBase;
		using ClassShareType = CoreTools::NonCopyClasses;
		using BuildType = Build<Process>;
		using HWnd = System::WindowHWnd;
		using HInstance = System::WindowHInstance;		

	public:
		WindowMainFunctionHelper(HInstance instance, const char* commandLine, const WindowApplicationInformation& information,
								 const EnvironmentDirectory& environmentDirectory);
		~WindowMainFunctionHelper() noexcept;
		WindowMainFunctionHelper(const WindowMainFunctionHelper& rhs) noexcept = delete;
		WindowMainFunctionHelper& operator=(const WindowMainFunctionHelper& rhs) noexcept = delete;
		WindowMainFunctionHelper(WindowMainFunctionHelper&& rhs) noexcept;
		WindowMainFunctionHelper& operator=(WindowMainFunctionHelper&& rhs) noexcept;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void Destroy() override;

	protected:
		virtual int EnterMessageLoop();
		HWnd GetHwnd() const noexcept;

	private:
		using BuildSharedPtr = std::shared_ptr<BuildType>;

	private:
		int DoRun() override;

		void Initializers(HInstance instance, const char* commandLine, const WindowApplicationInformation& information);
		void Terminators();

		void InitWindowProcess();
		void InitCamera();
		void InitRendererManager();
		void InitImpl(HInstance instance, const char* commandLine, const WindowApplicationInformation& information);

		void DestroyImpl() noexcept;
		void DestroyRendererManager() noexcept;
		void DestroyCamera() noexcept;
		void DestroyWindowProcess() noexcept;

	private:
		BuildSharedPtr m_Build;
		WindowMainFunctionSchedule m_WindowMainFunctionSchedule;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_WINDOW_MAIN_FUNCTION_HELPER_H