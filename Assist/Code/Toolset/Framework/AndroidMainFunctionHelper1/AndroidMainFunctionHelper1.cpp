///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 15:28)

#include "AndroidMainFunctionHelper1.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidFrameBuildDetail.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"
#include "Framework/MainFunctionHelper/AndroidMainFunctionHelperDetail.h"

Framework::AndroidMainFunctionHelper1::AndroidMainFunctionHelper1(AndroidApp* state, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ state, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidMainFunctionHelper1)
