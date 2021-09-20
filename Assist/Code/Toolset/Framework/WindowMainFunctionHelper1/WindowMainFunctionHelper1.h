// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.2 (2020/06/01 21:56)

#ifndef WINDOW_MAIN_FUNCTION_HELPER1_H
#define WINDOW_MAIN_FUNCTION_HELPER1_H

#include "Framework/WindowProcess/WindowProcess.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"

namespace Framework
{
	using BaseType = WindowMainFunctionHelper<WindowsAPIFrameBuild, WindowProcessInterface>; 

	class WindowMainFunctionHelper1 final : public BaseType
	{
	public:
		using ClassType = WindowMainFunctionHelper1;
		using ParentType = BaseType; 

	public:
		WindowMainFunctionHelper1(HInstance instance, const char* commandLine, const WindowApplicationInformation& information,
								  const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE;
	};
}

#endif // WINDOW_MAIN_FUNCTION_HELPER1_H