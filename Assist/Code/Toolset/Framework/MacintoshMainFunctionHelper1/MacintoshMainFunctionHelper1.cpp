///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 10:26)

#include "MacintoshMainFunctionHelper1.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MacintoshFrame/MacintoshFrameBuildDetail.h"
#include "Framework/MacintoshFrame/MacintoshProcessDetail.h"
#include "Framework/MainFunctionHelper/MacintoshMainFunctionHelperDetail.h"

Framework::MacintoshMainFunctionHelper1::MacintoshMainFunctionHelper1(const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;

    System::SystemPause();
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MacintoshMainFunctionHelper1)
