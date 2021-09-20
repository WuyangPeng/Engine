// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 16:07)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelperDetail.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"
#include "Framework/AndroidFrame/AndroidMessageLoop.h"
#include "System/Helper/Helper.h"

AndroidMessageLoopTesting::TestingHelper
	::TestingHelper(AndroidApp* state,const Framework::EnvironmentDirectory& environmentDirectory)
	:ParentType{ state,environmentDirectory }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

AndroidMessageLoopTesting::TestingHelper
	::~TestingHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AndroidMessageLoopTesting,TestingHelper)
									   
int AndroidMessageLoopTesting::TestingHelper
    ::RunAndroidMainLoop()
{
	Framework::AndroidMessageLoop loop(GetAndroidApp(),DisplayPtr);

	loop.EnterMessageLoop();

	return 0;
}

void AndroidMessageLoopTesting::TestingHelper ::DisplayPtr([[maybe_unused]] AndroidApp* state, [[maybe_unused]] int64_t timeDelta)
{
	 
}



