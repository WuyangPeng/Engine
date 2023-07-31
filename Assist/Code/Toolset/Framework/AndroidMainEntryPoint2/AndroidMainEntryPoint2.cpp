///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:35)

#include "AndroidMainEntryPoint2.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelperDetail.h"

Framework::AndroidMainEntryPoint2::AndroidMainEntryPoint2(AndroidApp* state, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ state, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidMainEntryPoint2)
