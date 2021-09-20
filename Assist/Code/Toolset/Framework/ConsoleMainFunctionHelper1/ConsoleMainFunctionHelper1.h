// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.2 (2020/06/01 11:32)

#ifndef CONSOLE_MAIN_FUNCTION_HELPER1_H
#define CONSOLE_MAIN_FUNCTION_HELPER1_H

#include "Framework/ConsoleFrame/ConsoleProcess.h"
#include "Framework/ConsoleFrame/ConsoleFrameBuild.h"
#include "Framework/MainFunctionHelper/ConsoleMainFunctionHelper.h"

namespace Framework
{
	using BaseType = ConsoleMainFunctionHelper<ConsoleFrameBuild, ConsoleProcessInterface>;

	class ConsoleMainFunctionHelper1 final : public BaseType
	{
	public:
		using ClassType = ConsoleMainFunctionHelper1;
		using ParentType = BaseType;

	public:
		ConsoleMainFunctionHelper1(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE; 
	};
}

#endif // CONSOLE_MAIN_FUNCTION_HELPER1_H