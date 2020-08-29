// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:47)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_H

#include "MainFunctionHelperBase.h" 

namespace Framework
{
	template <template<typename> class Build, typename Process>
	class MacintoshMainFunctionHelper : public MainFunctionHelperBase
	{
	public:
		using ClassType = MacintoshMainFunctionHelper<Build, Process>;
		using ParentType = MainFunctionHelperBase;
		using ClassShareType = CoreTools::NonCopyClasses;
		using BuildType = Build<Process>;

	public:
		explicit MacintoshMainFunctionHelper(const EnvironmentDirectory& environmentDirectory);
		~MacintoshMainFunctionHelper() noexcept;
		MacintoshMainFunctionHelper(const MacintoshMainFunctionHelper& rhs) noexcept = delete;
		MacintoshMainFunctionHelper& operator=(const MacintoshMainFunctionHelper& rhs) noexcept = delete;
		MacintoshMainFunctionHelper(MacintoshMainFunctionHelper&& rhs) noexcept;
		MacintoshMainFunctionHelper& operator=(MacintoshMainFunctionHelper&& rhs) noexcept;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void Destroy() override;

	private:
		using BuildSharedPtr = std::shared_ptr<BuildType>;

	private:
		int DoRun() noexcept override;
		virtual int RunMacintoshMainLoop() noexcept;

		void Initializers();
		void Terminators();

		void InitMacintoshProcess() noexcept;
		void InitImpl();

		void DestroyImpl() noexcept;
		void DestroyMacintoshProcess() noexcept;

	private:
		BuildSharedPtr m_Build;
		MacintoshMainFunctionSchedule m_MacintoshMainFunctionSchedule;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_MACINTOSH_MAIN_FUNCTION_HELPER_H
