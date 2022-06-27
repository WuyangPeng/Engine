///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/23 17:06)

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
