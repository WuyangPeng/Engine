// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 17:51)

#ifndef FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H
#define FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H

#include "Framework/FrameworkDll.h"

#include "MainFunctionHelperBase.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/shared_ptr.hpp>
#include <string>

FRAMEWORK_EXPORT_SHARED_PTR(ConsoleMainFunctionHelperImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE ConsoleMainFunctionHelper : public MainFunctionHelperBase
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ConsoleMainFunctionHelper);
		using ParentType = MainFunctionHelperBase;

	public:
		ConsoleMainFunctionHelper(int argc,char* argv[],const System::String& consoleTitle,
			                      const EnvironmentDirectory& environmentDirectory);
		virtual ~ConsoleMainFunctionHelper();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		int GetArgc() const;
		char** GetArgv() const;
		System::String GetApplicationProjectDirectory() const;

	private:		
		void ConsoleMainFunctionHelperInit(const System::String& consoleTitle);

		virtual int DoRun() = 0;

	private:
		int m_Argc;
		char** m_Argv; 

	    IMPL_TYPE_DECLARE(ConsoleMainFunctionHelper);
	};
}

#endif // FRAMEWORK_MAIN_FUNCTION_HELPER_CONSOLE_MAIN_FUNCTION_HELPER_H