// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 09:30)

#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

Framework::TestingHelper
::TestingHelper(HInstance instance, const char* commandLine, const WindowApplicationInformation& information,
				const EnvironmentDirectory& environmentDirectory)
	:ParentType{ instance,commandLine,information,environmentDirectory }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework,TestingHelper)







