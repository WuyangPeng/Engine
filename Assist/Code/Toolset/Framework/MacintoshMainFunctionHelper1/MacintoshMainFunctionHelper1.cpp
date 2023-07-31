///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:06)

#include "MacintoshMainFunctionHelper1.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MacintoshFrame/MacintoshFrameBuildDetail.h"
#include "Framework/MacintoshFrame/MacintoshProcessDetail.h"
#include "Framework/MainFunctionHelper/MacintoshMainFunctionHelperDetail.h"

Framework::MacintoshMainFunctionHelper1::MacintoshMainFunctionHelper1SharedPtr Framework::MacintoshMainFunctionHelper1::Create(const EnvironmentDirectory& environmentDirectory)
{
    return std::make_shared<MacintoshMainFunctionHelper1>(environmentDirectory);
}

Framework::MacintoshMainFunctionHelper1::MacintoshMainFunctionHelper1(const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    System::SystemPause();
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MacintoshMainFunctionHelper1)
