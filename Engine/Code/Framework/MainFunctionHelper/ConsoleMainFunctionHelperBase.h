// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 11:46)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_H

#include "Framework/FrameworkDll.h"

#include "MainFunctionHelperBase.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Command/CommandFwd.h"

FRAMEWORK_EXPORT_SHARED_PTR(ConsoleMainFunctionHelperBaseImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE ConsoleMainFunctionHelperBase : public MainFunctionHelperBase
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ConsoleMainFunctionHelperBase);
		using ParentType = MainFunctionHelperBase;
		using String = System::String;
		using Command = CoreTools::CommandHandle;

	public:
		ConsoleMainFunctionHelperBase(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		int GetArgc() const noexcept;
		char** GetArgv() const noexcept;
		String GetApplicationProjectDirectory() const;
		Command GetCommand() const noexcept;

	private:
		void ConsoleMainFunctionHelperInit(const String& consoleTitle);

	private:
		IMPL_TYPE_DECLARE(ConsoleMainFunctionHelperBase);

		int m_Argc;
		char** m_Argv;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_H