// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2019/12/29 2:47)

#include "ToolsetHelper.h"
#include "Toolset.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

Toolset::ToolsetHelper
	::ToolsetHelper(HInstance instance, char* cmdLine, const WindowApplicationInformation& information,
					const EnvironmentDirectory& environmentDirectory)
	:ParentType{ instance,cmdLine,information,environmentDirectory }
{
	SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Toolset, ToolsetHelper)





