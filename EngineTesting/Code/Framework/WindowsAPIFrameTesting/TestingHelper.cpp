// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/17 14:40)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"


WindowsAPIFrameTesting::TestingHelper
	::TestingHelper(HInstance hInstance, const char* lpCmdLine,const WindowApplicationInformation& information,const  Framework::EnvironmentDirectory& environmentDirectory)
	:ParentType(hInstance,lpCmdLine,information,environmentDirectory)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

WindowsAPIFrameTesting::TestingHelper
	::~TestingHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(WindowsAPIFrameTesting,TestingHelper)






