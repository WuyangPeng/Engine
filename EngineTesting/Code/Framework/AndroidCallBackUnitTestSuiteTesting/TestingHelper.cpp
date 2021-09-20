// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 14:37)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelperDetail.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"

AndroidCallBackUnitTestSuiteTesting::TestingHelper
	::TestingHelper(AndroidApp* state,const Framework::EnvironmentDirectory& environmentDirectory)
	:ParentType{ state,environmentDirectory }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

AndroidCallBackUnitTestSuiteTesting::TestingHelper
	::~TestingHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AndroidCallBackUnitTestSuiteTesting,TestingHelper)

									   
 
