// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 17:50)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_IMPL_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_IMPL_H

#include "Framework/FrameworkDll.h" 

#include "CoreTools/Command/Command.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ConsoleMainFunctionHelperImpl
	{
	public:
		using ClassType = ConsoleMainFunctionHelperImpl;
		using Command = CoreTools::CommandHandle;

	public:
		ConsoleMainFunctionHelperImpl(int argc,char* argv[],const System::String& consoleTitle,
									  const System::String& engineInstallationDirectory);

		CLASS_INVARIANT_DECLARE;
		
		System::String GetApplicationProjectDirectory() const;

	private:
		void InsertEnvironmentDirectory();
		static System::String ProduceApplicationProjectDirectory(const System::String& consoleTitle,const System::String& engineInstallationDirectory);

	private:		
		System::String m_ConsoleTitle;

		// 唯一的命令行参数对象
		Command m_Command;

		// 应用程序项目目录的路径
		System::String m_ApplicationProjectDirectory;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_IMPL_H