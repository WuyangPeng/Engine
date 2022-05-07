// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 16:07)

#include "Testing.h"
#include "TestingHelper.h"
#include "System/Helper/Helper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "Framework/AndroidFrame/AndroidMessageLoop.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelperDetail.h"

AndroidMessageLoopTesting::TestingHelper::TestingHelper(AndroidApp* state, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ state, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AndroidMessageLoopTesting, TestingHelper)

int AndroidMessageLoopTesting::TestingHelper::RunAndroidMainLoop()
{
    Framework::AndroidMessageLoop loop(GetAndroidApp(), DisplayPtr);

    loop.EnterMessageLoop();

    return 0;
}

void AndroidMessageLoopTesting::TestingHelper::DisplayPtr([[maybe_unused]] AndroidApp* state, [[maybe_unused]] int64_t timeDelta) noexcept
{
}
