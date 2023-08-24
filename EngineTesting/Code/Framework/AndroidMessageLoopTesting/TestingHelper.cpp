///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 17:51)

#include "Testing.h"
#include "TestingHelper.h"
#include "System/Helper/Helper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "Framework/AndroidFrame/AndroidMessageLoop.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelperDetail.h"

AndroidMessageLoopTesting::TestingHelper::TestingHelper(AndroidApp* state, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ state, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AndroidMessageLoopTesting, TestingHelper)

int AndroidMessageLoopTesting::TestingHelper::RunAndroidMainLoop()
{
    Framework::AndroidMessageLoop loop(GetAndroidApp(), Display);

    loop.EnterMessageLoop();

    return 0;
}

void AndroidMessageLoopTesting::TestingHelper::Display(AndroidApp* state, int64_t timeDelta) noexcept
{
    System::UnusedFunction(state, timeDelta);
}
