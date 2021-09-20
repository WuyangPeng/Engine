// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/09/29 23:37)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"

LibExample::TestingHelper
	::TestingHelper(HInstance hInstance,char* lpCmdLine,const WindowApplicationInformation& information,
			        const Framework::EnvironmentDirectory& environmentDirectory)
	:ParentType{ hInstance,lpCmdLine,information,environmentDirectory }
{
	SELF_CLASS_IS_VALID_9;
}



CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LibExample, TestingHelper)





