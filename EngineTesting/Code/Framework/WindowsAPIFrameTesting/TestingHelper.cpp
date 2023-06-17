///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 23:36)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

WindowsAPIFrameTesting::TestingHelper::TestingHelper(WindowsHInstance hInstance, const char* lpCmdLine, const WindowApplicationInformation& information, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType(hInstance, lpCmdLine, information, environmentDirectory)
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(WindowsAPIFrameTesting, TestingHelper)
