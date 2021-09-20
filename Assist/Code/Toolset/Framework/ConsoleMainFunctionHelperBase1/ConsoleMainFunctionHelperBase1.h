// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/31 21:18)

#ifndef CONSOLE_MAIN_FUNCTION_HELPER_BASE1_H
#define CONSOLE_MAIN_FUNCTION_HELPER_BASE1_H

#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelperBase.h" 

namespace Framework
{
	class ConsoleMainFunctionHelperBase1 final : public ConsoleMainFunctionHelperBase
	{
	public:
		using ClassType = ConsoleMainFunctionHelperBase1;
		using ParentType = ConsoleMainFunctionHelperBase;

	public:
		ConsoleMainFunctionHelperBase1(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE;

		int DoRun() final;

	private:
		void PrintConsoleParameterNumber();
		void PrintConsoleParameter();
		void PrintApplicationProjectDirectory();
		void PrintCommand(); 
	};
}

#endif // CONSOLE_MAIN_FUNCTION_HELPER_BASE1_H