///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:35)

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
