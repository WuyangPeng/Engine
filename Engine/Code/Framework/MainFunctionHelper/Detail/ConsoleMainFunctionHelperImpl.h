// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/07/31 17:50)

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

		// Ψһ�������в�������
		Command m_Command;

		// Ӧ�ó�����ĿĿ¼��·��
		System::String m_ApplicationProjectDirectory;
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_IMPL_H