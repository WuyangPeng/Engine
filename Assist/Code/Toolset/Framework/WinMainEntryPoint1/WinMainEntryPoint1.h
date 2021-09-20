// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/24 22:34)

#ifndef WIN_MAIN_ENTRY_POINT1_H
#define WIN_MAIN_ENTRY_POINT1_H

#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h" 
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"

namespace Framework
{
	using BaseType = WindowMainFunctionHelper<WindowsAPIFrameBuild, WindowProcessInterface>;

	class WinMainEntryPoint1 final : public BaseType
	{
	public:
		using ClassType = WinMainEntryPoint1;
		using ParentType = BaseType;

	public:
		WinMainEntryPoint1(HInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

		CLASS_INVARIANT_FINAL_DECLARE;
	};
}

#endif // WIN_MAIN_ENTRY_POINT1_H
