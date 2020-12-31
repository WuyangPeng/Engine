// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/20 21:18)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_IMPL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_IMPL_H

#include "Framework/FrameworkDll.h" 

#include "CoreTools/Command/Command.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ConsoleMainFunctionHelperBaseImpl
	{
	public:
		using ClassType = ConsoleMainFunctionHelperBaseImpl;
		using String = System::String;
		using Command = CoreTools::CommandHandle;

	public:
		ConsoleMainFunctionHelperBaseImpl(int argc, char** argv, const String& consoleTitle, const String& engineInstallationDirectory);

		CLASS_INVARIANT_DECLARE;

		String GetApplicationProjectDirectory() const;
		Command GetCommand() const noexcept;

	private:
		static String ProduceApplicationProjectDirectory(const String& consoleTitle, const String& engineInstallationDirectory);

	private:
		String m_ConsoleTitle;

		// 唯一的命令行参数对象
		Command m_Command;

		// 应用程序项目目录的路径
		String m_ApplicationProjectDirectory;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_BASE_IMPL_H