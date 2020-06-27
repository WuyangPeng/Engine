// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:46)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H

#include "ConsoleMainFunctionHelperBase.h" 

namespace Framework
{
	template <template<typename> class Build, typename Process>
	class ConsoleMainFunctionHelper : public ConsoleMainFunctionHelperBase
	{
	public:
		using ClassType = ConsoleMainFunctionHelper<Build, Process>;
		using ParentType = ConsoleMainFunctionHelperBase;
		using ClassShareType = CoreTools::NonCopyClasses;
		using BuildType = Build<Process>;

	public:
		ConsoleMainFunctionHelper(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);
		~ConsoleMainFunctionHelper() noexcept;
		ConsoleMainFunctionHelper(const ConsoleMainFunctionHelper& rhs) noexcept = delete;
		ConsoleMainFunctionHelper& operator=(const ConsoleMainFunctionHelper& rhs) noexcept = delete;
		ConsoleMainFunctionHelper(ConsoleMainFunctionHelper&& rhs) noexcept;
		ConsoleMainFunctionHelper& operator=(ConsoleMainFunctionHelper&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void Destroy() override;

	private:
		using BuildSharedPtr = std::shared_ptr<BuildType>;

	private:
		int DoRun() noexcept override;
		virtual int RunConsoleMainLoop() noexcept;

		void Initializers();
		void Terminators();

		void InitConsoleProcess() noexcept;
		void InitImpl();

		void DestroyImpl() noexcept;
		void DestroyConsoleProcess() noexcept;

	private:
		BuildSharedPtr m_Build;
		ConsoleMainFunctionSchedule m_ConsoleMainFunctionSchedule;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H
