// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 20:11)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"
#include SYSTEM_WARNING_DISABLE(26432)
Framework::TestingHelper::TestingHelper(AndroidApp* state, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType(state, environmentDirectory)
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::TestingHelper::~TestingHelper()
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, TestingHelper)
