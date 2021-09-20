// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 19:41)

#include "TestingHelper.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"


EngineMiddleLayer::TestingHelper
	::TestingHelper(HInstance instance, const char* commandLine,const WindowApplicationInformation& information,const EnvironmentDirectory& environmentDirectory)
	:ParentType{ instance,commandLine,information,environmentDirectory }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

EngineMiddleLayer::TestingHelper
	::~TestingHelper()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(EngineMiddleLayer, TestingHelper)







