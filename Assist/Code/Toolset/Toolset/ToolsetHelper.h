// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2019/12/29 2:45)

#ifndef TOOLSET_TOOLSET_HELPER_H
#define TOOLSET_TOOLSET_HELPER_H

#include "Framework/WindowProcess/WindowProcessHandle.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuild.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelper.h"

namespace Toolset
{
	using WindowMainFunctionHelper = Framework::WindowMainFunctionHelper<Framework::WindowsAPIFrameBuild, Framework::WindowProcessInterface>;
	class ToolsetHelper : public WindowMainFunctionHelper
	{
	public:
		using ClassType = ToolsetHelper;
		using ParentType = WindowMainFunctionHelper; ;
		using EnvironmentDirectory = Framework::EnvironmentDirectory;
		using WindowApplicationInformation = Framework::WindowApplicationInformation;

	public:
		ToolsetHelper(HInstance instance, char* cmdLine, const WindowApplicationInformation& information,
					  const EnvironmentDirectory& environmentDirectory);
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // TOOLSET_TOOLSET_HELPER_H